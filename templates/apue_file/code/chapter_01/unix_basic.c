/*================================================================
*   Copyright (C) 2020 Sangfor Ltd. All rights reserved.
*   
*    FileName：unix_basic.c
*      Author：joshua_zero@outlook.com
*  CreateTime：2020年09月05日
* Describtion：--
*
================================================================*/

#include "apue.h"
#include <dirent.h>
#include <sys/wait.h>
#include "unix_basic.h"


#define BUFFSIZE 4096



int myls(int argc, char* argv[]){
  DIR *dp;
  struct dirent *dirp;

  if(argc != 2)
    err_quit("usage: ls dirctory name!");

  if((dp = opendir(argv[1]))==NULL)
    err_sys("can't open dir %s \n", dp);

  while((dirp = readdir(dp))!=NULL){
    printf("%s \n", dirp->d_name);
  }

  closedir(dp);
  exit(0);
}

int mystdinout(void){
  
  int n;
  char buf[BUFFSIZE];
  while((n=read(STDIN_FILENO, buf, BUFFSIZE)) > 0){
    if(write(STDOUT_FILENO, buf, n) != n)
      err_sys("write error!");
  }

  if(n < 0)
    err_sys("read error!");
}

int mystdinout_buffer(void){
  int c;
  while((c=getc(stdin)) != EOF){
    if(putc(c, stdout) == EOF)
      err_sys("output error!"); 
  }

  if(ferror(stdin))
    err_sys("input error!");

}

int processctrl(void){
  char   buf[MAXLINE];
  pid_t  pid;
  int status;

  printf("%% ");
  while(fgets(buf, MAXLINE, stdin) != NULL){
    if(buf[strlen(buf)-1] == '\n')
      buf[strlen(buf)-1] = 0;
    if((pid = fork()) < 0){
      err_sys("fork error!"); 
    }else if(pid == 0){
      execlp(buf, buf, (char*)0);
      err_ret("couldn't execute:%s", buf);
      exit(127);
    }
  if((pid = waitpid(pid, &status, 0)) < 0) 
    err_sys("waitpid error");

  printf("%% ;");
  }

}


void sig_int(int signo){
  printf("interrupt \n%% ");
}

int process_signal(void){
  char buf[MAXLINE];
  pid_t pid;
  int status;

  if(signal(SIGINT, sig_int) == SIG_ERR)
    err_sys("signal error!");

  printf("%% ");
  while(fgets(buf, MAXLINE, stdin) != NULL){
    if(buf[strlen(buf)-1] == '\n')
      buf[strlen(buf)-1] = 0;
    if((pid=fork()) < 0){
      err_sys("fork error!");
    } else if(pid == 0){
      execlp(buf, buf, (char*)0);
      err_ret("couldn't  execute: %s", buf);
      exit(127);
    }

  if((pid = waitpid(pid, &status, 0)) < 0){
    err_sys("waitpid error!");
  }
  printf("%% ");
  }
}




int main(int argc, char* argv[]){
  //myls(argc, argv);
  //mystdinout();
  printf("hello world from process ID %ld\n", (long)getpid());
  
  //processctrl();
  process_signal();

  exit(0);
} 
