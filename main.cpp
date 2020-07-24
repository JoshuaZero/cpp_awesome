/*================================================================
*   Copyright (C) 2020 Sangfor Ltd. All rights reserved.
*   
*       FileName：main.cpp
*         Author：joshua_zero@outlook.com
*     CreateTime：2020-06-28 16:15:11
*    Describtion：
*  Last Modified: 2020-06-28 16:15:11
*
================================================================*/

#include <iostream>
#include <string>
#include <vector>

int stream_test(std::string in_file){
   std::ifstream in_f(in_file)
   std::string line;
   while(!in_f.eof()){
       getline(in_f, line);
       std::cout << line << std::endl;
   }  
}


int main(int argc, char** argv){
  stream_test('./test.txt');

  return 0;
}
