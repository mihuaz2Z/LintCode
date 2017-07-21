//
//  main.cpp
//  A+B问题
//
//  Created by Ruiwen Feng on 2017/7/21.
//  Copyright © 2017年 Ruiwen Feng. All rights reserved.
//

#include <iostream>


class Solution {
public:
    
    int add(int a, int b) {
        
        while (b) {
            int temp1 = a^b;
            int tmep2 = a&b;
            a = temp1;
            b = tmep2<<1;
        }
        
        return a;
    }
    
    int aplusb(int a, int b) {
      return  add(a,b);
    }
};

int main(int argc, const char * argv[]) {
    
    Solution solution;
    
    int result = solution.aplusb(100, 1);
    std::cout<<result<<std::endl;
    return 0;
}
