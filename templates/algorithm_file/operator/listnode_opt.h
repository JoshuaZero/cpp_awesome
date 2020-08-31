/*================================================================
*   Copyright (C) 2020 Sangfor Ltd. All rights reserved.
*   
*    FileName：listnode_opt.h
*      Author：joshua_zero@outlook.com
*  CreateTime：2020年08月31日
* Describtion：--
*
================================================================*/


#pragma once

#include "../basestruct/listnode.h"

namespace listnode_opt{

  class listnode_opt{
    public:
      listnode::slistnode* reverse(listnode::slistnode* head);

  };  

}
