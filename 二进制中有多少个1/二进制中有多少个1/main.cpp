//
//  main.cpp
//  二进制中有多少个1
//
//  Created by Ruiwen Feng on 2017/7/21.
//  Copyright © 2017年 Ruiwen Feng. All rights reserved.
//

/*
 二进制中有多少个1
 计算在一个 32 位的整数的二进制表示中有多少个 1.
 
 样例
 给定 32 (100000)，返回 1
 
 给定 5 (101)，返回 2
 
 给定 1023 (111111111)，返回 9
 
 */


#include <iostream>




class Solution {
public:

    int countOnes(int num) {

        int num_1 = 0;
        int value = num;
        for (int i = 0; i < 32 && value != 0; i++) {
            if (value&0x1) {
                num_1++;
            }
            value = value >> 1;
        }
        
        return num_1;
    }
};

int main(int argc, const char * argv[]) {
    
    Solution s;
    int result = s.countOnes(0);
    
    std::cout << result;
    return 0;
}
