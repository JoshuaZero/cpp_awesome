/*================================================================
*   Copyright (C) 2020 Sangfor Ltd. All rights reserved.
*   
*       FileName：test.cpp
*         Author：joshua_zero@outlook.com
*     CreateTime：2020-07-14 15:13:52
*    Describtion：
*  Last Modified: 2020-07-14 15:13:52
*
================================================================*/

//#include "test.h"



#include <iostream>
#include <fstream>
#include <string>

int x = 0;

int main(int argc, char* argv[]){
  std::string fn = "test.b";
  double d = 3.1415926;  
  std::ofstream(fn, std::ios::binary).write(reinterpret_cast<char*>(&d), sizeof d) 
    << 124 << "asdf" << std::endl;

  std::ifstream s(fn, std::ios::binary);
  std::cout << s << std::endl;
 
 return 0; 
}
