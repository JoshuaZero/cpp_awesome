/*================================================================
*   Copyright (C) 2020 Sangfor Ltd. All rights reserved.
*   
*       FileName：singleton.cpp
*         Author：joshua_zero@outlook.com
*     CreateTime：2020-07-16 18:37:22
*    Describtion：
*  Last Modified: 2020-07-16 18:37:22
*
================================================================*/

#include "singleton.h"


CSingleTon* getInstance(){
  if (m_Instance == NULL){
     m_Instance = new CSingleTon();
  }
  return m_Instance;
}

//需要规避拷贝和赋值
CSingleTon& GetInstance(){
  static CSingleTon l_inst;
  return l_inst;
}
