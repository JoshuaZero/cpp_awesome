/*================================================================
*   Copyright (C) 2020 Sangfor Ltd. All rights reserved.
*   
*    FileName：sys_datainfo.c
*      Author：joshua_zero@outlook.com
*  CreateTime：2020年09月18日
* Describtion：--
*
================================================================*/


#include "sys_datainfo.h"

struct passwd* getpwnam(const char* name){
  struct passwd* ptr;
  setpwent();
  while((ptr = getpwent()) != NULL){
    if(strcmp(name, ptr->pw_name) == 0)
      break;
  endpwent();
  return (ptr);
  }
}

int sys_strftime(void){
  time_t t;
  struct tm* tmp;
  char buf1[16];
  char buf2[64];

  time(&t);
  tmp = localtime(&t);
  if(strftime(buf1, 16, "time and date: %r, %a, %b, %d, %Y", tmp) == 0)
    printf("buffer length 16 is too small!\n");
  else
    printf("%s\n", buf1);
  if(strftime(buf2, 64, "time and date: %r, %a, %b, %d, %Y", tmp) == 0)
    printf("buffer length 64 if too samll!\n");
  else
    printf("%s\n", buf2);
  return 0;
}


int main(int argc, char* argv[]){
  //struct passwd * pwd = getpwnam("test");
  sys_strftime();

  exit(0);
  return 0;
}
