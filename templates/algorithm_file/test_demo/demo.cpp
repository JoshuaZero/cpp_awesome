/*================================================================
*   Copyright (C) 2020 Sangfor Ltd. All rights reserved.
*   
*    FileName：demo.cpp
*      Author：joshua_zero@outlook.com
*  CreateTime：2020年08月31日
* Describtion：--
*
================================================================*/

#include <iostream>
#include "../operator/listnode_opt.h"

void print_help(){
   
}

void print_bound(){
  std::cout << R"(    __    ____)" << std::endl; 
  std::cout << R"(   / /   / __/)" << std::endl; 
  std::cout << R"(  / /    \ \  )" << std::endl; 
  std::cout << R"( / /___ __\ \ )" << std::endl; 
  std::cout << R"(/_____//____/ )" << std::endl; 

  std::cout << "welcome come to ls's algorithm world!" << std::endl;
}

void demo_listnode(){
  listnode::slistnode a(1);
  listnode::slistnode b(3);
  listnode::slistnode c(5);
  listnode::slistnode d(7);
  listnode::slistnode e(9);
  a.next = &b;
  b.next = &c;
  c.next = &d;
  d.next = &e;

  std::cout << "before reverse!" << std::endl;
  listnode::slistnode* head =&a;
  while(head){
    std::cout << "cur val:" << head->val  << std::endl;
    head=head->next;
  }

  head = &a;
  listnode_opt::listnode_opt opt_demo;
  listnode::slistnode* newhead = opt_demo.reverse(head);
  std::cout << "after reverse!" << std::endl;
  while(newhead){
    std::cout << "cur newval:" << newhead->val  << std::endl;
    newhead=newhead->next;
  }
}

int main(int argc, char* argv[]){
  print_bound();
  
  demo_listnode();

  return 0;
}
