//
//  main.cpp
//  二分查找
//
//  Created by Ruiwen Feng on 2017/7/21.
//  Copyright © 2017年 Ruiwen Feng. All rights reserved.
//

/*
 给定一个排序的整数数组（升序）和一个要查找的整数target，用O(logn)的时间查找到target第一次出现的下标（从0开始），如果target不存在于数组中，返回-1。
 样例
 在数组 [1, 2, 3, 3, 4, 5, 10] 中二分查找3，返回2。

 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    
    int search (vector<int> &array, int target) {
        int left = 0;
        int right = (int)array.size();
        
        while (right > left) {
            int mid = (left + right)/2;
            cout <<"left:"<<left <<" right:"<<right << " mid " << mid << endl;
            if (array[mid] < target) {
                left = mid+1;
            }
            else if (array[mid] > target)
            {
                right = mid;
            }
            else if (array[mid] == target) {
                int result = mid;
                while (array[result] == target) {
                    result--;
                }
                return ++result;
            }
        }
        
        return -1;
    }
    
    int binarySearch(vector<int> &array, int target) {
        int result = search(array,target);
        return result;
    }
};

int main(int argc, const char * argv[]) {

    vector<int> array = {1,4,4,5,7,7,8,9,9,10};
    Solution s;
    int result = s.binarySearch(array,0);
    
    std::cout << result << endl;
    return 0;
}
