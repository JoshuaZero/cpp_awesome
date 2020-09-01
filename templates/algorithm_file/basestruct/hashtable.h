/*================================================================
*   Copyright (C) 2020 Sangfor Ltd. All rights reserved.
*   
*    FileName：hashtable.h
*      Author：joshua_zero@outlook.com
*  CreateTime：2020年09月01日
* Describtion：--
*
================================================================*/


#pragma once
#include "listnode.h"

namespace hashtable{
  //hastable 为普通的单链表构成
  listnode::listnode* hash_t [];

  //以string映射为int的hastable
  typedef struct strlist{
    std::string key;
    int val;
    strlist* next;
    strlist(int v):val(v),next(nullptr){}
  }strlist;

  class hastable{
   public:
     
  };


}
