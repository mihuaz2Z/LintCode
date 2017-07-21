//
//  main.cpp
//  Big Integer Addition
//
//  Created by Ruiwen Feng on 2017/7/21.
//  Copyright © 2017年 Ruiwen Feng. All rights reserved.
//

#include <iostream>

using namespace std;


class Solution {
public:
    /**
     * @param num1 a non-negative integers
     * @param num2 a non-negative integers
     * @return return sum of num1 and num2
     */
    string addStrings(string& num1, string& num2) {
        
        int size = (int)(num1.size() > num2.size() ? num1.size():num2.size());
        
        string temp;
        int flag = 0;
        for (int i = 0; i < size ; i++) {
            int num1_int = 0;
            int num2_int = 0;
            if (num1.size() >= 1) {
                char k = num1[num1.size()-1];
                num1_int = stoi(&k);
                num1.erase(num1.end()-1, num1.end());
            }
            else{
                num1_int = 0;
            }
            
            if (num2.size() >= 1) {
                char k = num2[num2.size()-1];
                num2_int = stoi(&k);
                num2.erase(num2.end()-1, num2.end());
            }
            else{
                num2_int = 0;
            }
            
            int num = num1_int + num2_int + flag;

            flag = num/10;
            num = num%10;
            
            temp += to_string(num);
        }
        
        if (flag != 0) {
            temp += to_string(flag);
        }
        
        string result;
        for (int i = (int)temp.size()-1; i >= 0; i --) {
            result += temp[i];
        }
        return result;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    string num1 = "9999999999981";
    string num2 = "19";
    string result = s.addStrings(num1, num2);
    std::cout << result << endl;
    return 0;
}
