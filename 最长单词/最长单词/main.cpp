//
//  main.cpp
//  最长单词
//
//  Created by Ruiwen Feng on 2017/7/26.
//  Copyright © 2017年 Ruiwen Feng. All rights reserved.
//
/*
 给一个词典，找出其中所有最长的单词。
 样例
 在词典
 
 {
 "dog",
 "google",
 "facebook",
 "internationalization",
 "blabla"
 }
 中, 最长的单词集合为 ["internationalization"]
 
 在词典
 
 {
 "like",
 "love",
 "hate",
 "yes"
 }
 中，最长的单词集合为 ["like", "love", "hate"]
 */


#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    /**
     * @param dictionary: a vector of strings
     * @return: a vector of strings
     */
    vector<string> longestWords(vector<string> &dictionary) {
       
        if (dictionary.size() <= 1) {
            return dictionary;
        }
        
        vector<string>result;
        long max = 0;
        for (int i = 0; i < dictionary.size(); i ++) {
            
            string temp = dictionary[i];
            
            if (max < temp.size()) {
                max = temp.size();
                result.erase(result.begin(), result.end());
            }
            else if(max > temp.size()){
                continue;
            }
            result.push_back(temp);
        }
        return result;
    }
};

int main(int argc, const char * argv[]) {
    
    Solution s;
    vector<string> dic = {};
    dic = s.longestWords(dic);
    for (int i = 0; i < dic.size(); i ++) {
        cout<<dic[i]<<endl;
    }
    
    return 0;
}










