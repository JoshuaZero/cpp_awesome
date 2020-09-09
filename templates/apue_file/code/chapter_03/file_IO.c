/*================================================================
*   Copyright (C) 2020 Sangfor Ltd. All rights reserved.
*   
*    FileName：file_IO.c
*      Author：joshua_zero@outlook.com
*  CreateTime：2020年09月07日
* Describtion：--
*
================================================================*/

#include "apue.h"
#include <fcntl.h>
#include "file_IO.h"

int is_seek(void){
  if(lseek(STDIN_FILENO, 0, SEEK_CUR) == -1)
    printf("con not seek! \n");
  else
    printf("seek ok \n");
}


int file_hole(void){
  char buf1[] = "abcdefghij";
  char buf2[] = "ABCDEFGHIJ";
  int fd;
  if((fd = creat("file.hole", FILE_MODE)) < 0)
    err_sys("creat error!");

  if(write(fd, buf1, 10) != 10)
    err_sys("buf1 write error!");
  if(lseek(fd, 16384, SEEK_SET) == -1)
    err_sys("lseek error!");
  if(write(fd, buf2, 10) != 10)
    err_sys("buf2 write error!");
}

#define BUFFSIZE 4096

int file_copy(void){
  int n;
  char buf[BUFFSIZE];

  while((n = read(STDIN_FILENO, buf, BUFFSIZE)) > 0){
    if(write(STDOUT_FILENO, buf, n) != n)
      err_sys("write error!");
  }

  if(n < 0)
    err_sys("read error!");

}


int file_fcntl(int argc, char* argv[] ){
  int val;

  if (argc != 2)
     err_quit("usage: file_IO < descriptor # > !");
  
  printf("params: 0:%d \n 1:%d \n 2:%d\n", argv[0], argv[1], argv[2]);

  if((val = fcntl(atoi(argv[1]), F_GETFL, 0)) < 0)
    err_sys("fcntl error for fd %d", atoi(argv[1]));

  switch(val & O_ACCMODE){
    case O_RDONLY:
      printf("read only!");
      break;
    case O_WRONLY:
      printf("write only!");
      break;
    case O_RDWR:
      printf("read write!");
      break;
    
    default:
      err_dump("unknown access mode!");
  }

  if(val & O_APPEND)
    printf(", append");
  if(val & O_NONBLOCK)
    printf(", nonblocking");
  if(val & O_SYNC)
    printf(", synchronous writes");

#if !defined(_POSIX_C_SOURCE) && defined(O_FSYNC) && (O_FSYNC != O_SYNC)
  if(val & O_FSYNC)
    printf(", synchronous writes");
#endif

  putchar('\n');

}

void set_fl(int fd, int flags){
  int val;
  if((val = fcntl(fd, F_GETFL, 0)) < 0)
    err_sys("fcntl F_GETFL error!");

  //turn on flags
  val |= flags;
  //turn off flags
  //val &= ~flags;

  if(fcntl(fd, F_SETFL, val) < 0)
    err_sys("fcntl F_SETFL error!");
} 

int main(int argc, char* argv[]){
  //is_seek();
  //file_hole();
  //file_copy();
  file_fcntl(argc, argv);
  
  exit(0);
}
