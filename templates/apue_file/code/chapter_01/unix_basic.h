/*================================================================
*   Copyright (C) 2020 Sangfor Ltd. All rights reserved.
*   
*    FileName：unix_basic.h
*      Author：joshua_zero@outlook.com
*  CreateTime：2020年09月05日
* Describtion：--
*
================================================================*/


#pragma onc

int myls(int argc, char* argv[]);

int mystdinout(void);

int mystdinout_buffer(void);

int processctrl(void);


static void sig_int(int);
int process_signal(void);
