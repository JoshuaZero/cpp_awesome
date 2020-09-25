/*================================================================
*   Copyright (C) 2020 Sangfor Ltd. All rights reserved.
*   
*    FileName：process_env.c
*      Author：joshua_zero@outlook.com
*  CreateTime：2020年09月18日
* Describtion：--
*
================================================================*/


#include "process_env.h"

void my_exit1(void){
  printf("first exit handler!\n");
}

void my_exit2(void){
  printf("second exit handler!\n");
}

int env_atexit(void){
  if(atexit(my_exit2) != 0)
    err_sys("can't register my_exit2!");
  
  if(atexit(my_exit1) != 0)
    err_sys("can't register my_exit1!");
  if(atexit(my_exit1) != 0)
    err_sys("can't register my_exit1!");

  printf("main function is done!\n");
  return 0;
}

int env_echo(int argc, char* argv[]){
  int i = 0;
  for(i=0; i<argc; ++i){
    printf("argv[%d]:%s\n", i, argv[i]);
  }
  return 0;
}


void do_line(char* ptr){
  int cmd;
  tok_ptr = ptr;
  while((cmd == get_token()) > 0){
    switch(cmd){
      case TOK_ADD:
        cmd_add();
        break;
    }
  }
}

void env_jmp(void){
  char line[MAXLINE];
  if(setjmp(jmpbuffer) != 0)
    printf("setjmp error!");
  while(fgets(line, MAXLINE, stdin) != NULL){
    do_line(line);
  }
  
}

void cmd_add(void){
  int token;
  token = get_token();
  if(token < 0)
    longjmp(jmpbuffer, 1);

  //rest of prcessing for this command
}

int get_token(void){
  
  //fetch next token from line pointed to by tok_ptr
}

int env_variable(void){
  int autoval;
  register int regival;
  volatile int volaval;
  static int statval;

  globval = 1;
  autoval = 2;
  regival = 3;
  volaval = 4;
  statval = 5;

  if(setjmp(jmpbuffer) != 0){
    printf("after longjmp:\n");
    printf("globval = %d, autoval = %d, regival =%d, volaval =%d, statval = %d\n", globval, autoval, regival, volaval, statval);
    return 0;
  }
  //change variables after setjmp , but before longjmp
  globval = 95, autoval = 96, regival = 97, volaval = 98, statval = 99;
  f1(autoval, regival, volaval, statval);
  return 0;

}

void f1(int i, int j, int k, int l){
  printf("in f1():;\n");
  printf("globval = %d, autoval =%d, regival =%d, volaval = %d, statval = %d\n", globval, i, j, k, l);
  f2();
}

void f2(void){
  longjmp(jmpbuffer, 1);
}

int main(int argc, char* argv[]){
  //env_atexit();
  //env_echo(argc, argv);
  //env_jmp();
  env_variable();


  return 0;

}
