//
//  main.cpp
//  最大子数组
//
//  Created by Ruiwen Feng on 2017/7/26.
//  Copyright © 2017年 Ruiwen Feng. All rights reserved.
//
/*
 给定一个整数数组，找到一个具有最大和的子数组，返回其最大和。
 
 注意事项
 
 子数组最少包含一个数
 样例
 给出数组[−2,2,−3,4,−1,2,1,−5,3]，符合要求的子数组为[4,−1,2,1]，其最大和为6
 
 思路，反着来。
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:

    int maxSubArray(vector<int> nums) {
        if (nums.size() == 0) {
            return 0;
        }
        // write your code here
        int sum = 0;
        int max = nums[0];
        for (int i = (int)nums.size()-1; i >= 0  ; i --) {
            sum += nums[i];
            max = max > sum ? max : sum;
            if (sum < 0) {
                sum = 0;
            }
        }
        return max;
    }
};


int main(int argc, const char * argv[]) {
    Solution s;
    vector<int> temp = {-1};
    s.maxSubArray(temp);
    return 0;
}
