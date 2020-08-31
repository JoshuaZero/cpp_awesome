/*================================================================
*   Copyright (C) 2020 Sangfor Ltd. All rights reserved.
*   
*    FileName：listnode.h
*      Author：joshua_zero@outlook.com
*  CreateTime：2020年08月31日
* Describtion：--
*
================================================================*/


#pragma once

namespace listnode{
  typedef struct slistnode{
    int val;
    slistnode* next;
    slistnode(int v):val(v),next(nullptr){}
  }slistnode;

  typedef struct dlistnode{
    int val;
    dlistnode* prep;
    dlistnode* next;
    dlistnode(int v):val(v),prep(nullptr),next(nullptr){}
  }dlistnode;

  class listnode{
    
    listnode() = default;
    listnode(const listnode& lhs);
    listnode& operator=(const listnode& lhs);
    virtual ~listnode();
    listnode* operator&();
    const listnode* operator&()const;
    listnode(listnode&& rhs);
    listnode& operator=(listnode&& rhs);

    //以下为数据的基本操作：增删改查
    listnode* append();
    listnode* remove();
    listnode* update();
    listnode* find();

  };  


}

