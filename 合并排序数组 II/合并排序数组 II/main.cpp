//
//  main.cpp
//  合并排序数组 II
//
//  Created by Ruiwen Feng on 2017/7/27.
//  Copyright © 2017年 Ruiwen Feng. All rights reserved.
//

/*
 合并排序数组 II
 合并两个排序的整数数组A和B变成一个新的数组。
 
 注意事项
 
 你可以假设A具有足够的空间（A数组的大小大于或等于m+n）去添加B中的元素。
 
 样例
 给出 A = [1, 2, 3, empty, empty], B = [4, 5]
 
 合并之后 A 将变成 [1,2,3,4,5]
 
 
 */

#include <iostream>


class Solution {
public:
    
    void quick(int * nums, int low,int high) {
        if (low >= high) {
            return;
        }
        int key = nums[low];
        int left = low;
        int right = high;
        
        while (left < right) {
            
            while (left < right && nums[right] >= key) {
                right--;
            }
            nums[left] = nums[right];
            while (left < right && nums[left] <= key) {
                left ++;
            }
            nums[right] = nums[left];
        }
        nums[left] = key;
        
        quick(nums, low, left-1);
        quick(nums, left+1, high);
    }
    
    void mergeSortedArray(int A[], int m, int B[], int n) {
        
        if (n == 0) {
            return;
        }
        
        int begin_location = m-1;
        for (int i = m-1; i >=0; i --) {
            if (A[i] >= B[0]) {
                begin_location = i;
            }
        }
        //先把B都丢进A里面然后快排。
        int index = 0;
        for (int i = m; i < m+n; i ++) {
            A[i] = B[index];
            index ++;
        }
        quick(A, begin_location, m+n-1);
    }
};

int main(int argc, const char * argv[]) {
    int a[] = {9,10,11,12,13,0,0,0,0};
    int b[] = {4,5,6,7};
    Solution s;
    s.mergeSortedArray(a, 5, b, 4);
    for (int i = 0; i < sizeof(a)/sizeof(int); i ++) {
        std::cout << a[i] << " ";
    }
    return 0;
}
