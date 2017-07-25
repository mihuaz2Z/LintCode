//
//  main.cpp
//  加一
//
//  Created by Ruiwen Feng on 2017/7/25.
//  Copyright © 2017年 Ruiwen Feng. All rights reserved.
//
/*
 给定一个非负数，表示一个数字数组，在该数的基础上+1，返回一个新的数组。
 
 该数字按照大小进行排列，最大的数在列表的最前面。
 
 样例
 给定 [1,2,3] 表示 123, 返回 [1,2,4].
 
 给定 [9,9,9] 表示 999, 返回 [1,0,0,0].
 

 */

#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    /**
     * @param digits a number represented as an array of digits
     * @return the result
     */
    vector<int> plusOne(vector<int>& digits) {

        if (digits.size() == 0) {
            return digits;
        }
        
        int flag = 0;
        for (int i = (int)digits.size()-1; i >= 0; i --) {
            int result = 0;
            if (i == (int)digits.size()-1) {
                result = digits[i] + 1 + flag;
            }
            else{
                if (flag == 0) {//提前结束。
                    break;
                }
                result = digits[i] + flag;
            }
            flag = 0;
            if (result/10) {
                flag = result/10;
            }
            digits[i] = result%10;
        }
    
        if (flag == 1) {
            digits.insert(digits.begin(), vector<int>::value_type(flag));
        }
        
        return digits;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    vector<int> digits = {9,9,9,9,9};
    digits = s.plusOne(digits);
    for (int i = 0; i < digits.size(); i ++) {
        std::cout << digits[i]<<" ";
    }
    return 0;
}











