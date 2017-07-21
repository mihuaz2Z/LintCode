//
//  main.cpp
//  各位相加
//
//  Created by Ruiwen Feng on 2017/7/21.
//  Copyright © 2017年 Ruiwen Feng. All rights reserved.
//

/*
 给出一个非负整数 num，反复的将所有位上的数字相加，直到得到一个一位的整数。
 样例
 给出 num = 38。
 
 相加的过程如下：3 + 8 = 11，1 + 1 = 2。因为 2 只剩下一个数字，所以返回 2。
 */

#include <iostream>

using namespace std;

class Solution {
public:
    int addDigits(int num) {

        while (num >= 10) {
            int temp = 0;
            while (num) {
                temp += num%10;
                num/=10;
            }
            num = temp;
        }

        return num;
    }
};

int main(int argc, const char * argv[]) {
    
    Solution s;
    int result = s.addDigits(999999);
    
    std::cout << result;
    return 0;
}
