/*================================================================
*   Copyright (C) 2020 Sangfor Ltd. All rights reserved.
*   
*    FileName：file_dir.h
*      Author：joshua_zero@outlook.com
*  CreateTime：2020年09月08日
* Describtion：--
*
================================================================*/


#pragma once

#include "apue.h"
#include <fcntl.h>
#include <sys/stat.h>


int file_access(int argc, char* argv[]);

int file_umask(void);

int file_chmod(void);

int file_link(void);

int file_stat(int argc, char* argv[]);
