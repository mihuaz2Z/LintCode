//
//  main.cpp
//  左填充
//
//  Created by Ruiwen Feng on 2017/7/25.
//  Copyright © 2017年 Ruiwen Feng. All rights reserved.
//
/*
 实现一个leftpad库，如果不知道什么是leftpad可以看样例
 样例
 leftpad("foo", 5)
 >> "  foo"
 
 leftpad("foobar", 6)
 >> "foobar"
 
 leftpad("1", 2, "0")
 >> "01"
 */

#include <iostream>
#include <string>

using namespace std;


class StringUtils {
public:

    static string leftPad(string& originalStr, int size, char padChar=' ') {

        int sub = size-(int)originalStr.size();
        string result = "";
        for (int i = 0; i < sub; i ++) {
            result = padChar + result;
        }
        
        result = result + originalStr;
        
        return result;
    }
};


int main(int argc, const char * argv[]) {

    StringUtils newstring;
    string result = "1";
    result = newstring.leftPad(result,2,'0');
    
    
    std::cout << result << endl;
    return 0;
}
