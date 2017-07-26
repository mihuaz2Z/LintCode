//
//  main.cpp
//  最长上升连续子序列
//
//  Created by Ruiwen Feng on 2017/7/26.
//  Copyright © 2017年 Ruiwen Feng. All rights reserved.
//
/*
 给定一个整数数组（下标从 0 到 n-1， n 表示整个数组的规模），请找出该数组中的最长上升连续子序列。（最长上升连续子序列可以定义为从右到左或从左到右的序列。）
 
 注意事项
 time
 
 样例
 给定 [5, 4, 2, 1, 3], 其最长上升连续子序列（LICS）为 [5, 4, 2, 1], 返回 4.
 
 给定 [5, 1, 2, 3, 4], 其最长上升连续子序列（LICS）为 [1, 2, 3, 4], 返回 4.
 
 */


#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    /**
     * @param A an array of Integer
     * @return  an integer
     */
    int longestIncreasingContinuousSubsequence(vector<int>& A) {
        
        if (A.size() <= 1) {
            return (int)A.size();
        }

        int flag = 0;
        int up_max = 0;
        int up_temp = 1;
        int down_max = 0;
        int down_temp = 1;
        for (int i = 0; i < A.size()-1; i ++) {
            if (A[i+1] > A[i]) {
                if (flag >= 0) {
                    up_temp ++;
                    up_max= up_max>up_temp?up_max:up_temp;
                }
                else if(flag < 0){
                    up_temp = 2;
                    up_max= up_max>up_temp?up_max:up_temp;
                }
                flag = 1;
            }
            else if (A[i+1] < A[i]){
                if (flag > 0) {
                    down_temp = 2;
                    down_max= down_max>down_temp?down_max:down_temp;
                }
                else if (flag <= 0){
                    down_temp ++;
                    down_max= down_max>down_temp?down_max:down_temp;
                }
                flag = -1;
            }
            else if (A[i+1] == A[i]){
                if (flag > 0) {
                    down_temp = 2;
                    down_max= down_max>down_temp?down_max:down_temp;
                    up_temp ++;
                    up_max= up_max>up_temp?up_max:up_temp;
                }
                else if (flag < 0)
                {
                    up_temp = 2;
                    up_max= up_max>up_temp?up_max:up_temp;
                    down_temp ++;
                    down_max= down_max>down_temp?down_max:down_temp;
                }
                else
                {
                    down_temp ++;
                    up_temp ++;
                    up_max= up_max>up_temp?up_max:up_temp;
                    down_max= down_max>down_temp?down_max:down_temp;
                }
            }
            
        }
        
        return up_max>down_max?up_max:down_max;
    }
};

int main(int argc, const char * argv[]) {
    
    
    Solution s;
    
    vector<int> temp = {3,2,1,70,61,43,12,78,22,1};
    
    int result = s.longestIncreasingContinuousSubsequence(temp);
    cout << result << endl;
    
    return 0;
}













