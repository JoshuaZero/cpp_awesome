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

static void my_exit1(void);
static void my_exit2(void);

int env_atexit(void);

int env_echo(int argc, char* argv[]);
