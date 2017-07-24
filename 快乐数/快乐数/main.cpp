//
//  main.cpp
//  快乐数
//
//  Created by Ruiwen Feng on 2017/7/24.
//  Copyright © 2017年 Ruiwen Feng. All rights reserved.
//
/*
 写一个算法来判断一个数是不是"快乐数"。
 
 一个数是不是快乐是这么定义的：对于一个正整数，每一次将该数替换为他每个位置上的数字的平方和，然后重复这个过程直到这个数变为1，或是无限循环但始终变不到1。如果可以变为1，那么这个数就是快乐数。
 
 样例
 19 就是一个快乐数。
 
 1^2 + 9^2 = 82
 8^2 + 2^2 = 68
 6^2 + 8^2 = 100
 1^2 + 0^2 + 0^2 = 1
 
 */


#include <iostream>

using namespace std;

class Solution {
public:

    int isReallyHappy(int n) {
        if (n < 10) {
            return n;
        }
        int next_n = 0;
        while (n>0) {
            next_n += (n%10)*(n%10);
            n /= 10;
        }
        return isReallyHappy(next_n);
    }
    
    bool isHappy(int n) {
        if (isReallyHappy(n) == 1 ||isReallyHappy(n) == 7) { //10以内，只有1和7是快乐数。
            return true;
        }
        else{
            return false;
        }
    }
};

int main(int argc, const char * argv[]) {

    Solution s;
    bool result = s.isHappy(2);
    
    if (result) {
        cout << "she is really happy.." <<endl;
    }
    else
    {
        cout << "she is not really happy.." <<endl;
    }
    
    return 0;
}
