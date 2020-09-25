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


int main(int argc, char* argv[]){
  //env_atexit();
  env_echo(argc, argv);


  return 0;

}
