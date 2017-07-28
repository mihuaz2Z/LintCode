//
//  main.cpp
//  两数之和
//
//  Created by Ruiwen Feng on 2017/7/28.
//  Copyright © 2017年 Ruiwen Feng. All rights reserved.
//
/*
 给一个整数数组，找到两个数使得他们的和等于一个给定的数 target。
 
 你需要实现的函数twoSum需要返回这两个数的下标, 并且第一个下标小于第二个下标。注意这里下标的范围是 1 到 n，不是以 0 开头。
 
 样例
 给出 numbers = [2, 7, 11, 15], target = 9, 返回 [1, 2].
 
 */

#include <iostream>
#include <map>
#include <vector>

using namespace std;



class Solution {
public:
 
    vector<int> twoSum(vector<int> &nums, int target) {
      
        vector<int> result;
        
        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = i + 1; j <= nums.size(); j++)
            {
                if (target - nums[i] == nums[j])
                {
                    result.push_back(i+1);
                    result.push_back(j+1);
                    return result;
                }
            }
        }
        
        return result;
    }
};


int main(int argc, const char * argv[]) {
   
    vector<int> nums = {1,0,-1};
    
    Solution s;
    nums = s.twoSum(nums, -1);
    
    for (int i = 0; i < nums.size(); i ++) {
        cout << nums[i] << " ";
    }
    cout <<endl;
    return 0;
}
