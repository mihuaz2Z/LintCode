//
//  main.cpp
//  哈希函数
//
//  Created by Ruiwen Feng on 2017/7/24.
//  Copyright © 2017年 Ruiwen Feng. All rights reserved.
//
/*
 在数据结构中，哈希函数是用来将一个字符串（或任何其他类型）转化为小于哈希表大小且大于等于零的整数。一个好的哈希函数可以尽可能少地产生冲突。一种广泛使用的哈希函数算法是使用数值33，假设任何字符串都是基于33的一个大整数。

 
 其中HASH_SIZE表示哈希表的大小(可以假设一个哈希表就是一个索引0 ~ HASH_SIZE-1的数组)。
 
 给出一个字符串作为key和一个哈希表的大小，返回这个字符串的哈希值。
 
 说明
 For this problem, you are not necessary to design your own hash algorithm or consider any collision issue, you just need to implement the algorithm as described.
 
 样例
 对于key="abcd" 并且 size=100， 返回 78
 
 */

#include <iostream>

using namespace std;

class Solution {
public:

    int hashCode(string key,int HASH_SIZE) {
        long sum = 0;
        
//        sum = a * 33
//        sum = (a * 33 + b) * 33
//        sum = (a * 33^2 + b * 33 + c) * 33
//        sum = (a * 33^3 + b * 33^2 + c * 33 + d) * 33
        
        for (int i = 0; i < key.size(); i ++) {
            //防止*33超出界限。
            sum = sum*33%HASH_SIZE + (int)(key[i]);
            std::cout << sum << endl;
        }
        sum %= HASH_SIZE;
        return (int)sum;
    }
};


int main(int argc, const char * argv[]) {
    Solution s;
    int result = s.hashCode("abcd", 100);
    std::cout << result << endl;
    return 0;
}
