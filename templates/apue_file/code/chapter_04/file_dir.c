/*================================================================
*   Copyright (C) 2020 Sangfor Ltd. All rights reserved.
*   
*    FileName：file_dir.c
*      Author：joshua_zero@outlook.com
*  CreateTime：2020年09月08日
* Describtion：--
*
================================================================*/


#include "file_dir.h"


#define  RWRWRW (S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH)


int file_access(int argc, char* argv[]){
  if(argc != 2)
    err_quit("usage: file_dir <pathname>");

  if(access(argv[1], R_OK) < 0)
    err_ret("access error for %s", argv[1]);
  else
    printf("read access OK!\n");

  if(open(argv[1], O_RDONLY) < 0)
    err_ret("open error for %s", argv[1]);
  else 
    printf("open for reading OK \n");

}


int file_umask(void){
  umask(0);

  if(creat("foo", RWRWRW) < 0)
    err_sys("creat error for foo");

  umask(S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH);

  if(creat("bar", RWRWRW) < 0)
    err_sys("creat error for bar!");
  
  return 0;
}


int file_chmod(void){
  struct stat statbuf;

  if(stat("foo", &statbuf) < 0)
    err_sys("stat error for foo!");
  if(chmod("foo", (statbuf.st_mode & ~S_IXGRP) | S_ISGID) < 0)
    err_sys("chmod error for foo!");

  if(chmod("bar", S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH) < 0)
    err_sys("chmode error for bar!");

}

int file_link(void){
  if(open("tempfile", O_RDWR) < 0)
    err_sys("open error!");
  if(unlink("tempfile") < 0)
    err_sys("unlink error!");
  printf("file unlinked!\n");
  sleep(15);
  printf("done!\n");
}

int file_stat(int argc, char* argv[]){
  int i,fd;
  struct stat statbuf;
  struct timespec times[2];
  for(i =1; i < argc; i++){
    if(stat(argv[i], &statbuf) < 0){
      err_ret("%s: stat error", argv[1]);
      continue;
    }
    if((fd = open(argv[i], O_RDWR | O_TRUNC)) < 0){
      err_ret("%s: open error", argv[1]);
      continue;
    }
    times[0] = statbuf.st_atim;
    times[1] = statbuf.st_mtim;
    if(futimens(fd, times) < 0)
      err_ret("%s: futimens error", argv[1]);
    close(fd);
  }
}

#define FTW_F 1
#define FTW_D 2
#define FTW_DNR 3
#define FTW_NS 4

static char * fullpath;
static size_t pathlen;

static int myftw(char * pathname, Myfunc* func){
  fullpath = path_alloc(&pathlen);
  if(fullpath <= strlen(pathname)){
    pathlen = strlen(pathname);
    if((fullpath = realloc(fullpath, pathlen)) == NULL)
      err_sys("realloc failed!"); 
  }
  strcpy(fullpath, pathname);
  return (dopath(func));
}

static int dopath(Myfunc* func){
  struct stat statbuf;
  struct dirent * dirp;
  DIR *dp;
  int ret, n;
  if(lstat(fullpath, &statbuf) < 0)
    return(func(fullpath, &statbuf, FTW_NS));
  if(S_ISDIR(statbuf.st_mode) == 0)
    return(func(fullpath, &statbuf, FTW_F));

  if((ret=func(fullpath, &statbuf, FTW_D)) != 0)
    return(ret);
  n = strlen(fullpath);
  if(n + NAME_MAX + 2 > pathlen){
    pathlen += 2;
    if((fullpath = realloc(fullpath, pathlen)) == NULL)
      err_sys("realloc failed!");
  }
  fullpath[n++] = '/';
  fullpath[n] = 0;
  if((dp = opendir(fullpath)) == NULL)
    return(func(fullpath, &statbuf, FTW_DNR));

  while((dirp = readdir(dp)) != NULL){
    if((strcmp(dirp->d_name, ".") == 0) || (strcmp(dirp->d_name, "..") == 0))
      continue;
    strcpy(&fullpath[n], dirp->d_name);
    if((ret = dopath(func)) != 0)
      break;
  }
  fullpath[n-1] = 0;
  if(closedir(dp) < 0)
    err_sys("can't close directory %s", fullpath);
  return (ret);  

}

static int myfunc(const char* pathname, const struct stat* statptr, int type){
  switch(type){
  case FTW_F:
    switch(statptr->st_mode & S_IFMT){
    case S_IFREG: nreg++; break;
    case S_IFBLK: nblk++; break;
    case S_IFCHR: nchr++; break;
    case S_IFIFO: nfifo++; break;
    case S_IFLNK: nslink++; break;
    case S_IFSOCK: nsock++; break;
    case S_IFDIR: err_dump("for S_IFDIR for %s", pathname);
    }
    break;
  case FTW_D:
    ndir++;
    break;
  case FTW_DNR:
    err_ret("can't read directory %s", pathname);
  case FTW_NS:
    err_ret("stat error for %s", pathname);
  default:
    err_dump("unknown type %d for pathname %s", type, pathname);
  } 
  return 0;
}

int file_traverse(int argc, char* argv[]){
  int ret;
  if(argc != 2)
    err_quit("usage: ftw <starting-pathname>");
  ret = myftw(argv[1], myfunc);
  ntot = nreg + ndir + nblk + nchr + nfifo + nslink + nsock;
  if(ntot == 0)
    ntot = 1;
  printf("regular files = %7ld, %5.2f %%\n", nreg, nreg*100.0/ntot);
  printf("directories = %7ld, %5.2f %%\n", ndir, ndir*100.0/ntot);
  printf("block special = %7ld, %5.2f %%\n", nblk, nblk*100.0/ntot);
  printf("char special = %7ld, %5.2f %%\n", nchr, nchr*100.0/ntot);
  printf("FIFOs = %7ld, %5.2f %%\n", nfifo, nfifo*100.0/ntot);
  printf("symbolic links = %7ld, %5.2f %%\n", nslink, nslink*100.0/ntot);
  printf("sockets = %7ld, %5.2f %%\n", nsock, nsock*100.0/ntot);

  exit(ret);
}

int file_chdir(void){
  if(chdir("/temp") < 0)
    err_sys("chdir failed!");
  printf("chdir to /tmp succeeded \n");
  exit(0);
}

int file_getcwd(void){
  char * ptr;
  size_t size;
  if(chdir("/usr/spool/uucppublic") < 0)
    err_sys("chdir failed!");
  ptr = path_alloc(&size);
  if(getcwd(ptr, size) == NULL)
    err_sys("getcwd failed!");
  printf("cwd = %s \n");
  exit(0);
}


int file_dev(int argc, char* argv[]){
  int i;
  struct stat buf;
  for(i=1; i < argc; i++){
    printf("%s: ", argv[1]);
    if(stat(argv[i], &buf) < 0){
      err_ret("stat error!");
      continue;
    }
    printf("dev = %d/%d", major(buf.st_dev), minor(buf.st_dev));
    if(S_ISCHR(buf.st_mode) || S_ISBLK(buf.st_mode)){
      printf("(%s) rdev = %d/%d", (S_ISCHR(buf.st_mode)) ? "character" : "block", major(buf.st_rdev), minor(buf.st_rdev));
    }
   printf("\n");
  }
  exit(0);
}

int main(int argc, char* argv[]){
  //file_access(argc, argv);
  //file_umask();
  //file_chmod();
  
  //file_link();
  //file_stat(argc, argv);

  //file_traverse(argc, argv);
  file_dev(argc, argv);

  exit(0);
}


