/*================================================================
*   Copyright (C) 2020 Sangfor Ltd. All rights reserved.
*   
*    FileName：greed_opt.cpp
*      Author：joshua_zero@outlook.com
*  CreateTime：2020年09月01日
* Describtion：--
*
================================================================*/


#include "greedy_opt.h"

namespace greedy_opt{

int greedy_opt::wiggleMaxLength(std::vector<int> & nums){
  static const int BEGIN=0;
  static const int UP = 1;
  static const int DOWN = 2;
  
  int STATE=BEGIN;
  int max_lenth = 1;
  
  if(nums.size < 2)
    return nums.size();
  
  for(int i=1; i<nums.size(); ++i){
    switch(STATE){
      case BEGIN:
        if(nums[i-1] < nums[i]){
          STATE = UP;
          max_length++;
        }
        else if(nums[i-1] > nums[i]){
          STATE = DOWN;
          max_length++;  
        }
        break;
      case UP:
        if(nums[i-1] > nums[i]){
          STATE = DOWN;
          max_length++;
        }
        break;
      case DOWN:
        if(nums[i-1] < nums[i]){
          STATE = UP;
          max_length++;
        }
        break;
        
    }
    return max_length;
  }
  

}  //namespace greedy_opt
