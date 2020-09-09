/*================================================================
*   Copyright (C) 2020 Sangfor Ltd. All rights reserved.
*   
*    FileName：std_iolib.c
*      Author：joshua_zero@outlook.com
*  CreateTime：2020年09月09日
* Describtion：--
*
================================================================*/


#include "std_iolib.h"

int io_getput(void){
  int c;
  while((c=getc(stdin)) != EOF){
    if(putc(c, stdout) == EOF)
      err_sys("output error!");
  }
  if(ferror(stdin))
    err_sys("input error!");
}


int io_fgetput(void){
  char buf[MAXLINE];
  while(fgets(buf, MAXLINE, stdin) != NULL){
    if(fputs(buf, stdout) == EOF)
      err_sys("fputs error!");
  }
  if(ferror(stdin))
    err_sys("input error!");
}

int io_fwriteread(void){
  float data[10];
  FILE* fp;
  if(fwrite(&data[2], sizeof(float), 4, fp) != 4)
    err_sys("fwrite error!");

  if(fwrite(&item, sizeof(item), 1, fp) != 1)
    err_sys("fwrite error!");

}

int io_streamstate(void){
  
}

void pr_stdio(const char* name, FILE* fp){
  printf("stream =%s ", name);
  if(is_unbuffered(fp))
    printf("unbuffered!");
  else if (is_linebuffered(fp))
    printf("line buffered!");
  else 
    printf("fully buffered!");
  printf(", buffer size = %d\n", buffer_size(fp));
} 

#if defined(_IO_UNBUFFERED)
int is_unbuffered(FILE* fp){
  return (fp->_flags &_IO_UNBUFFERED);
}

int is_linebuffered(FILE* fp){
  return (fp->_flags & _IO_LINE_BUF);

}

int buffer_size(FILE* fp){
  return (fp->_IO_buf_end - fp->_IO_buf_base);
}
#elif defined(__SNBF)

int is_unbuffered(FILE* fp){
  return(fp->_flags & __SNBF);
}

int is_linebuffered(FILE* fp){
  return(fp->_flags & __SNBF);
}

int buffer_size(FILE*){
  return(fp->_bf._size);
}

#elif defined(_IONBF)
#ifdef _L{64
#define _flag __pad[4]
#define _ptr __pad[1]
#define _base __pad[2]
#endif

int is_unbuffered(FILE* fp){
  return (fp->_flag & _IONBF);
}

int is_linebuffered(FILE* fp){
  return (fp->_flag & _IONBF);
}

int buffer_size(FILE*){
#ifdef _LP64 
  return (fp->_base - fp->_ptr );
#else
  return (BUFSUZ);
#endif
}

#else
#error unknown stdio implementation!
#endif


int io_tmpfile(void){
  char name[L_tmpnam], line[MAXLINE];
  FILE* fp;
  printf("%s\n", tmpnam(NULL));
  tmpnam(name);
  printf("%s'n", name);
  if((fp = tmpfile()) == NULL)
    err_sys("tmpfile error!");
  fputs("one lien of ouput \n", fp);
  rewind(fp);
  if(fgets(line, sizeof(line), fp) == NULL)
    err_sys("fgets error!");
  fputs(line, stdout);

}

void make_temp(char* template){
  int fd;
  struct stat sbuf;
  if((fd = mkstemp(template)) < 0)
    err_sys("can't create temp file!");
  printf("temp name = %s\n", template);
  close(fd);
  if(stat(template, &sbuf) < 0){
    if(errno == ENOENT)
      printf("file doesn't exist \n");
    else
      err_sys("stat failed!");
  }
  else {
    printf("file exist! \n");
    unlink(template);
  }
}

int io_mkstemp(void){
 char good_template[] = "/tmp/dirXXXXXX";
 char *bad_template = "/tmp/dirXXXXXX";

 printf("trying to create first temp file... \n");
 make_temp(good_template);
 printf("trying to create second temp file... \n");
 make_temp(bad_template);
}

int io_memstream(void){
  FILE *fp;
  char buf[BSZ];

  memset(buf, 'a', BSZ-2);
  buf[BSZ-2] = '\0';
  buf[BSZ-1] = 'X';
  if((fp = fmemopen(buf, BSZ, "w+")) == NULL)
    err_sys("fmemopen failed!");
  printf("initial buffer contents: %s\n", buf);
  fprintf(fp, "hello world!");
  printf("before flush: %s\n", buf);
  fflush(fp);
  printf("after fflush: %s\n", buf);
  printf("len of string in buf = %ld\n", (long)strlen(buf));

  memset(buf, 'b', BSZ-2);
  buf[BSZ-2] = '\0';
  buf[BSZ-1] = 'X';
  fprintf(fp, "hello world!");
  fseek(fp, 0, SEEK_SET);
  printf("after fseek: %s \n", buf);
  printf("len of string in buf = %ld\n", (long)strlen(buf));

  memset(buf, 'c', BSZ-2);
  buf[BSZ-2] = '\0';
  buf[BSZ-1] = 'X';
  fprintf(fp, "hello world!");
  fclose(fp);
  printf("after fclose: %s\n", buf);
  printf("len of string in buf = %ld\n", (long)strlen(buf));
  return 0;
}


int main(int argc, char* argv[]){
  //io_getput();
  io_fgetput();
  
  
  exit(0);
}
