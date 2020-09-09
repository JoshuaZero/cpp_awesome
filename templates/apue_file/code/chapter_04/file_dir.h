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
#include <dirent.h>
#include <limits.h>
#include <sys/sysmacros.h>
#ifdef SOLARIS
 #include <sys/mkdev.h>
#endif

int file_access(int argc, char* argv[]);

int file_umask(void);

int file_chmod(void);

int file_link(void);

int file_stat(int argc, char* argv[]);

typedef int Myfunc(const char*, const struct stat*, int);

static Myfunc myfunc;
static int myftw(char*, Myfunc *);
static int dopath(Myfunc *);
static long nreg, ndir, nblk, nchr, nfifo, nslink, nsock, ntot;
int file_traverse(int argc, char* argv[]);

int file_chdir(void);

int file_getcwd(void);

int file_dev(int argc, char* argv[]);

