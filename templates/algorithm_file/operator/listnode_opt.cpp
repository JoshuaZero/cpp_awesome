/*================================================================
*   Copyright (C) 2020 Sangfor Ltd. All rights reserved.
*   
*    FileName：listnode_opt.cpp
*      Author：joshua_zero@outlook.com
*  CreateTime：2020年08月31日
* Describtion：--
*
================================================================*/


#include "listnode_opt.h"


namespace listnode_opt{
//slistnode
listnode::slistnode* listnode_opt::reverse(listnode::slistnode* head){
  listnode::slistnode* newhead = nullptr;
  while(head){
    listnode::slistnode* next = head->next;
    head->next = newhead;
    newhead = head;
    head = next;

  }
  return newhead;
}



}
