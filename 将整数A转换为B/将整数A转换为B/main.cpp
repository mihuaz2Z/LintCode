//
//  main.cpp
//  将整数A转换为B
//
//  Created by Ruiwen Feng on 2017/7/24.
//  Copyright © 2017年 Ruiwen Feng. All rights reserved.
//

/*
 如果要将整数A转换为B，需要改变多少个bit位？
 
 注意事项
 
 Both n and m are 32-bit integers.
 
 样例
 如把31转换为14，需要改变2个bit位。
 
 (31)10=(11111)2
 
 (14)10=(01110)2
 
 注意：
 负数在计算机里面用补码表示：
 补码就是符号位不变，其他位置取反，末位加一
 
 */

#include <iostream>


class Solution {
public:
  
    int bitSwapRequired(int a, int b) {

        int dif = 0;
        
        //处理异号。
        if ((a<0&&b>0)||(b<0&&a>0)) {
            dif = dif +1;
            if (a<0) {
                a = a&0x7fffffff;
            }
            if (b<0) {
                b = b&0x7fffffff;
            }
        }
        
        int eoA_B = a^b;
        while (eoA_B > 0) {
            if (eoA_B&0x1) {
                dif ++;
            }
            eoA_B>>=1;
        }
        
        return dif;
    }
};



int main(int argc, const char * argv[]) {
    
    Solution s;
    int result = s.bitSwapRequired(14,31);
    
    std::cout << result << std::endl;
    
    return 0;
}
