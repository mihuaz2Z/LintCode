//
//  ;;
//  最后一个单词的长度
//
//  Created by Ruiwen Feng on 2017/7/25.
//  Copyright © 2017年 Ruiwen Feng. All rights reserved.
//
/*
 最后一个单词的长度
 给定一个字符串， 包含大小写字母、空格' '，请返回其最后一个单词的长度。
 
 如果不存在最后一个单词，请返回 0 。
 
 样例
 给定 s = "Hello World"，返回 5。
 
 */

#include <iostream>
#include <string>
#include <vector>


using namespace std;

class Solution {
public:
    
    int lengthOfLastWord(string& s) {
        
        if (s.size() == 0) {
            return 0;
        }
        
        string pattern = " ";
        std::string::size_type pos;
        std::vector<std::string> result;
        s+=pattern;//扩展字符串以方便操作
        long size= s.size();
        
        for(int i=0; i<size; i++)
        {
            pos=s.find(pattern,i);
            if(pos<size)
            {
                std::string subString=s.substr(i,pos-i);
                result.push_back(subString);
                i = (int)pos+(int)pattern.size()-1;
            }
        }

        for (int i =0; i < result.size(); i ++) {
            cout << result[i] << endl;
        }
        
        return (int)result[result.size()-1].size();

    }
};

int main(int argc, const char * argv[]) {
    
    Solution s;
    string hello = "a";
    int result = s.lengthOfLastWord(hello);
    
    
    std::cout << result << endl;
    return 0;
}
