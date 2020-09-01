/*================================================================
*   Copyright (C) 2020 Sangfor Ltd. All rights reserved.
*   
*    FileName：hashstr_opt.h
*      Author：joshua_zero@outlook.com
*  CreateTime：2020年09月01日
* Describtion：--
*
================================================================*/


#pragma once

namespace hashstr_opt{

  class hashstr_opt{
    public:
      int int_func(int key, int tablelen);
      int str_func(std::string, int tablelen);

      std::string minWindow(std::string strbase, std::string strsub);
      bool is_window_ok(int map_t[], int map_s[], std::vector<int> &vec_t);

    private:
      const int MAX_LEN = 128;
  };  

} //namespace hashstr_opt
