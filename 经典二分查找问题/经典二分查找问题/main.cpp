//
//  main.cpp
//  经典二分查找问题
//
//  Created by Ruiwen Feng on 2017/7/21.
//  Copyright © 2017年 Ruiwen Feng. All rights reserved.
//

/*
 在一个排序数组中找一个数，返回该数出现的任意位置，如果不存在，返回-1
 
 样例
 给出数组 [1, 2, 2, 4, 5, 5].
 
 对于 target = 2, 返回 1 或者 2.
 对于 target = 5, 返回 4 或者 5.
 对于 target = 6, 返回 -1.


 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:

    int findPosition(vector<int>& A, int target) {
    
        long left = 0;
        long right = A.size() - 1;
        
        while (left <= right) {
            long mid = (left+right)/2;
            if (A[mid] > target) {
                right = mid-1;
            }
            else if(A[mid] < target)
            {
                left = mid+1;
            }
            else if (A[mid] == target) {
                return (int)mid;
            }
        }
        
        return -1;//没找到
    }
};


int main(int argc, const char * argv[]) {

    Solution s;
    vector<int> array = {1,2,3,4,5,6};
    int result = s.findPosition(array, 4);
    
    cout << result;
    return 0;
}
