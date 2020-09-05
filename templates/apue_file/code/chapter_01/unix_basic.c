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
#include "unix_basic.h"


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


int main(int argc, char* argv[]){
  myls(argc, argv);
  exit(0);

}
