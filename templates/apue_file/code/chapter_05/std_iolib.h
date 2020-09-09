/*================================================================
*   Copyright (C) 2020 Sangfor Ltd. All rights reserved.
*   
*    FileName：std_iolib.h
*      Author：joshua_zero@outlook.com
*  CreateTime：2020年09月09日
* Describtion：--
*
================================================================*/


#pragma once

#include "apue.h"
#include <errno.h>

#define NAMESIZE 128
#define BSZ 48

struct {
  short count;
  long total;
  char name[NAMESIZE];
}item;

int io_getput(void);

int io_fgetput(void);

int io_fwriteread(void);

int io_streamstate(void);

void pr_stdio(const char*, FILE*);
int is_unbuffered(FILE*);
int is_linebuffered(FILE*);
int buffer_size(FILE*);

void make_temp(char* template);
int io_tmpfile(void);

int io_mkstemp(void);

int io_memstream(void);


