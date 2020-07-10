/*================================================================
*   Copyright (C) 2020 Sangfor Ltd. All rights reserved.
*   
*       FileName：baseobj.h
*         Author：joshua_zero@outlook.com
*     CreateTime：2020-06-28 16:18:57
*    Describtion：
*  Last Modified: 2020-06-28 16:18:57
*
================================================================*/

#pragma once

class baseobj{
public:
  baseobj()=default;
  //explicit baseobj();
  virtual ~baseobj();

  baseobj(const baseobj& lsh);
  baseobj(baseobj&& rsh);
  baseobj& operator=(const baseobj& lsh);
  baseobj& operator=(baseobj&& rsh);



private:


};
