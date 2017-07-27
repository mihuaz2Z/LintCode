//
//  main.cpp
//  中位数
//
//  Created by Ruiwen Feng on 2017/7/26.
//  Copyright © 2017年 Ruiwen Feng. All rights reserved.
//

/*
 给定一个未排序的整数数组，找到其中位数。
 
 中位数是排序后数组的中间值，如果数组的个数是偶数个，则返回排序后数组的第N/2个数。
 
 样例
 给出数组[4, 5, 1, 2, 3]， 返回 3
 
 给出数组[7, 9, 4, 5]，返回 5
 
 时间复杂度为O(n)
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    bool flag = true;
public:
    
    /**
     * @param nums: A list of integers.
     * @return: An integer denotes the middle number of the array.
     */
    
    
    void quickSort(vector<int>*nums,int low,int high){
    
        if (low >= high) {
            return;
        }
        
        int key = (*nums)[low];
        int left = low;
        int right = high;
        
        while (left < right) {
            
            while (left < right && (*nums)[right] >= key) {
                right--;
            }
            (*nums)[left] = (*nums)[right];
            
            while (left < right && (*nums)[left] <= key) {
                left ++;
            }
            (*nums)[right] = (*nums)[left];

        }
        (*nums)[left] = key;
        
        quickSort(nums, low, left-1);
        quickSort(nums, left+1, high);
    }
    
    
    
    int median(vector<int> &nums) {
        if (nums.size() == 0) {
            return 0;
        }
        quickSort(&nums, 0, (int)nums.size() -1);
        
        
        return nums[((int)nums.size()-1)/2];
    }

};


int main(int argc, const char * argv[]) {
    
    vector<int> nums = {};
    Solution s;
    int result = s.median(nums);
    
    cout << result << endl;
    
    return 0;
}
