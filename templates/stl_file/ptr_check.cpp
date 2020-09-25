/*================================================================
*   Copyright (C) 2020 Sangfor Ltd. All rights reserved.
*   
*    FileName：ptr_check.cpp
*      Author：joshua_zero@outlook.com
*  CreateTime：2020年09月18日
* Describtion：--
*
================================================================*/


#include "ptr_check.h"

namespace ptr_name{

ptr_check::ptr_check(){

}

ptr_check::ptr_check(const ptr_check& lh){

}

ptr_check::ptr_check(ptr_check&& rh){

}

ptr_check& ptr_check::operator=(const ptr_check& lh){

}

ptr_check& ptr_check::operator=(ptr_check&& rh){

}

ptr_check* ptr_check::operator&(){

}


const ptr_check* ptr_check::operator&() const{

}


ptr_check::~ptr_check(){

}



int ptr_check::testptr(){
  std::shared_ptr<int>  pa;
  int pb = 1;
  int pc = 2;

  pa = pb = pc;
  std::cout << pa->use_count << std::endl;
  return 0;
}



}  //namespace ptr_name
