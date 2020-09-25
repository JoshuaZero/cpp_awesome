/*================================================================
*   Copyright (C) 2020 Sangfor Ltd. All rights reserved.
*   
*    FileName：ptr_check.h
*      Author：joshua_zero@outlook.com
*  CreateTime：2020年09月18日
* Describtion：--
*
================================================================*/


#pragma once
#include <iostream>
#include <memory>

namespace ptr_name{

  class ptr_check{
  public:
    ptr_check();
    ptr_check(const ptr_check& lh);
    ptr_check(ptr_check&& rh);
    ptr_check& operator=(const ptr_check& lh);
    ptr_check& operator=(ptr_check&& rh);
    ptr_check* operator&();
    const ptr_check* operator&() const;


    ~ptr_check();

  int testptr();


  private:


  };


}  //namespace ptr_name


