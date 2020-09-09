/*================================================================
*   Copyright (C) 2020 Sangfor Ltd. All rights reserved.
*   
*    FileName：file_IO.h
*      Author：joshua_zero@outlook.com
*  CreateTime：2020年09月07日
* Describtion：--
*
================================================================*/


#pragma once

int is_seek(void);

int file_hole(void);

int file_copy(void);

int file_fcntl(int argc, char* argv[]);
