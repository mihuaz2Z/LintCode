//
//  main.cpp
//  主元素
//
//  Created by Ruiwen Feng on 2017/7/26.
//  Copyright © 2017年 Ruiwen Feng. All rights reserved.
//
/*
 给定一个整型数组，找出主元素，它在数组中的出现次数严格大于数组元素个数的二分之一。
 
 
 
 注意事项
 
 You may assume that the array is non-empty and the majority number always exist in the array.
 
 样例
 给出数组[1,1,1,1,2,2,2]，返回 1
 */

#include <iostream>
#include <vector>
#include <map>

using namespace std;

//class Solution {
//public:
//    /**
//     * @param nums: A list of integers
//     * @return: The majority number
//     */
//
//    
//    int majorityNumber(vector<int> nums) {
//        if (nums.size() == 0) {
//            return 0;
//        }
//        map<int,int> lismap;
//        int max = 0;
//        int index = 0;
//        for (int i = 0; i < nums.size(); i ++) {
//            lismap[nums[i]] = lismap[nums[i]] +1;
//            if (max < lismap[nums[i]]) {
//                max = lismap[nums[i]];
//                index = nums[i];
//            }
//        }
// 
//        return index;
//    }
//};


//改进
//它在数组中的出现次数严格大于数组元素个数的二分之一。
class Solution {
public:

    int majorityNumber(vector<int> nums) {
        if (nums.size() == 0) {
            return 0;
        }
        int max = 0;
        int index = 0;
        for (int i = 0; i < nums.size(); i ++) {
            if (max == 0) {
                index = nums[i];//index存值。
                max = 1;
            }
            else
            {
                if (index == nums[i]) {
                    max ++;//是就+1
                }else{
                    max --;//不是-1
                }
            }
        }
        //因为始终大于1/2，所以max最后应该>1,index里面存了它的值。
        return index;
    }
};



int main(int argc, const char * argv[]) {
    Solution s;
    vector<int> temp = {1,1,1,1,2,2,2,2,2};
    int i = s.majorityNumber(temp);
    cout << i <<endl;
    return 0;
}
