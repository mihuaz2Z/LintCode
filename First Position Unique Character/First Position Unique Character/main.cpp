//
//  main.cpp
//  First Position Unique Character
//
//  Created by Ruiwen Feng on 2017/7/24.
//  Copyright © 2017年 Ruiwen Feng. All rights reserved.
//

/*
 First Position Unique Character
 
 Given a string, find the first non-repeating character in it and return it's index. If it doesn't exist, return -1.
 
 Given s = "lintcode", return 0.
 
 Given s = "lovelintcode", return 2.
 */


#include <iostream>
#include <string>
#include <map>

using namespace std;

class Solution {
public:
    /**
     * @param s a string
     * @return it's index
     */
    int firstUniqChar(string& s) {

        map<char,int> readed_map;
        
        for (int i = 0; i < s.size(); i ++) {
            readed_map[s[i]] = readed_map[s[i]] + 1;
        }
        
        for (int i = 0; i < s.size(); i ++) {
            if (readed_map[s[i]] == 1) {
                return i;
            }
        }

        return -1;
    }
};

int main(int argc, const char * argv[]) {

    Solution s;
    string sss = "lovelintcode";
    int result = s.firstUniqChar(sss);
    
    std::cout << result << endl;
    return 0;
}
