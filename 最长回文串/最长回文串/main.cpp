//
//  main.cpp
//  最长回文串
//
//  Created by Ruiwen Feng on 2017/7/26.
//  Copyright © 2017年 Ruiwen Feng. All rights reserved.
//
/*
 给出一个包含大小写字母的字符串。求出由这些字母构成的最长的回文串的长度是多少。
 
 数据是大小写敏感的，也就是说，"Aa" 并不会被认为是一个回文串。
 
 注意事项
 
 假设字符串的长度不会超过 1010。
 
 样例
 给出 s = "abccccdd" 返回 7
 
 一种可以构建出来的最长回文串方案是 "dccaccd"。
 */


#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

class Solution {
public:
    /**
     * @param s a string which consists of lowercase or uppercase letters
     * @return the length of the longest palindromes that can be built
     */
    int longestPalindrome(string& s) {
        map<char,int> hashmap;
        vector<char> vec;
        vec.push_back(s[0]);
        for (int i = 0; i < s.size(); i ++) {
            hashmap[s[i]] = hashmap[s[i]] + 1;
            for (int j = 0; j < vec.size(); j ++) {
                if (vec[j] == s[i]) {
                        break;
                }
                else
                {
                    if (j == vec.size()-1) {
                        vec.push_back(s[i]);
                    }
                }
            }
        }
        
        int sum = 0;
        int has_a = 0;
        for (int i = 0; i < vec.size(); i ++) {
            if (hashmap[vec[i]]%2 == 0) {
                sum += hashmap[vec[i]];
            }
            else{
                has_a = 1;
                sum += hashmap[vec[i]] -1;
            }
        }

        return sum+has_a;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    string gaga = "NTrQdQGgwtxqRTSBOitAXUkwGLgUHtQOmYMwZlUxqZysKpZxRoehgirdMUgy";
    int result = s.longestPalindrome(gaga);
    std::cout << result <<" size:"<<gaga.size()<< endl;
    
    return 0;
}
