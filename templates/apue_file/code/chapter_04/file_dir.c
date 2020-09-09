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


int main(int argc, char* argv[]){
  //file_access(argc, argv);
  //file_umask();
  //file_chmod();
  
  //file_link();
  file_stat(argc, argv);


  exit(0);
}


