/*================================================================
*   Copyright (C) 2020 Sangfor Ltd. All rights reserved.
*   
*       FileName：singleton.h
*         Author：joshua_zero@outlook.com
*     CreateTime：2020-07-16 18:38:54
*    Describtion：
*  Last Modified: 2020-07-16 18:38:54
*
================================================================*/

#pragma once

namespace design_pt_name{

class CSingleTon{
  public:
    static CSingleTon * getInstance();  

    static CSingleTon& GetInstance();

  private:
    CSingleTon();
    static CSingleTon* m_Instance = NULL;

    //声明copy assign 为private
    CSingleTon(const CSingle & lsh);
    CSingleTon & operator=(const SGingle & lsh);
    
};

}

