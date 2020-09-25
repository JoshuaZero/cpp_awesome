/*================================================================
*   Copyright (C) 2020 Sangfor Ltd. All rights reserved.
*   
*    FileName：process_env.h
*      Author：joshua_zero@outlook.com
*  CreateTime：2020年09月18日
* Describtion：--
*
================================================================*/


#pragma once

#include "apue.h"
#include <setjmp.h>

#define TOK_ADD 5
char* tok_ptr;

static jmp_buf jmpbuffer;
static int globval;

static void my_exit1(void);
static void my_exit2(void);

int env_atexit(void);

int env_echo(int argc, char* argv[]);

void do_line(char* ptr);

void env_jmp(void);

void cmd_add(void);

int get_token(void);

static void f1(int, int, int, int);

static void f2(void);

int env_variable(void);


