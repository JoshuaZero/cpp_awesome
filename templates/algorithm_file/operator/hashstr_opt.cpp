/*================================================================
*   Copyright (C) 2020 Sangfor Ltd. All rights reserved.
*   
*    FileName：hashstr_opt.cpp
*      Author：joshua_zero@outlook.com
*  CreateTime：2020年09月01日
* Describtion：--
*
================================================================*/


#include "hashstr_opt.h"


namespace hashstr_opt{

int hashstr_opt::int_func(int key, int tablelen){
  return key%tablelen;
}


int hashstr_opt::str_func(std::string key, int tablelen){
  int sum = 0;
  for (int i=0; i<key.lenth(); ++i){
    sum += key[i];
  }
  return sum%tablelen;
}

bool hashstr_opt::is_window_ok(int map_t[], int map_s[], std::vector<int> &vec_t){
  for(int i=0; i<vec_t.size(); ++i ){
    //maps 中出现某字符的数量 < t中出现该字符的数量
    if (map_s[vec_t[i]] < map_t[vec_t[i]]){
      return false;
    }
  }
  return true
}
  

std::string hashstr_opt::minWindow(std::string strbase, std::string strsub){
  int map_s[MAX_LEN] = {0};
  int map_t[MAX_LEN] = {0};
  std::vector<int> vec_s;
  for (int i=0; i<strsub.lenth(); ++i){
    map_s[strsub[i]]++;
  }

  for (int i=0; i<MAX_LEN; ++i){
    if(mat_s[i] > 0)
      vec_s.push_back(i);
  }

  int win_begin = 0;
  std::string result;
  //win_begin 窗口头指针，窗口尾指针
  for (int i=0; i<strbase.lenth(); ++i){
    map_t[strbase[i]]++; 
    while(win_begin < i){
      char begin_ch = strbase[win_begin];
      if(map_s[begin_ch] == 0){
        win_begin++;
      }
      esle if(map_t[begin_ch] > map_s[begin_ch]){
        map_t[begin_ch]--;
        win_begin++;
      }
      else
        break;
    }
    if(is_window_ok(map_t, map_s,vec_t){
     int new_winlen = i-win_begin+1;
     if(result==""||result.lenth()>new_winlen){
       result = map_t.substr(win_begin, new_winlen);
     }
    }
  } 
  return result; 
}

}   //namespace hashstr_opt
