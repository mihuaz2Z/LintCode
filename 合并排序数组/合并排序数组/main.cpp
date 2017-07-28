//
//  main.cpp
//  合并排序数组
//
//  Created by Ruiwen Feng on 2017/7/27.
//  Copyright © 2017年 Ruiwen Feng. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    /**
     * @param A and B: sorted integer array A and B.
     * @return: A new sorted integer array
     */
    
    void quick(vector<int> *nums,int low,int high) {
        if (low >= high) {
            return;
        }
        int key = (*nums)[low];
        int left = low;
        int right = high;
        
        while (left < right) {
            while (left < right && (*nums)[right] >= key) {
                right --;
            }
            (*nums)[left] = (*nums)[right];
            while (left < right && (*nums)[left] <= key) {
                left ++;
            }
            (*nums)[right] = (*nums)[left];
        }
        (*nums)[left] = key;
        
        quick(nums, low, left-1);
        quick(nums, left+1, high);
    }
    
    
    vector<int> mergeSortedArray(vector<int> &A, vector<int> &B) {
        if (A.size() == 0) {
            return B;
        }
        if (B.size() == 0) {
            return A;
        }
        
        vector<int>* big;
        vector<int>* small;
        if (A.size() >= B.size()) {
            big = &A;
            small = &B;
        }
        else
        {
            big = &B;
            small = &A;
        }
    
        int location = (int)big->size()-1;
        for (int i = (int)big->size()-1; i >= 0; i --) {
            if ((*big)[i] >= (*small)[0]) {
                location = i;
            }
        }
        
        for (int i = 0;i < small->size(); i ++) {
            big->push_back((*small)[i]);
        }
        
        quick(big, location, (int)big->size()-1);
        
        return *big;
    }
};


int main(int argc, const char * argv[]) {
    Solution s;
    vector<int> temp1 = {1,5};
    vector<int> temp2 = {2,3};
    vector<int>  big = s.mergeSortedArray(temp1, temp2);
    for (int i =0; i < big.size(); i ++) {
        cout << big[i] << " ";
    }
    return 0;
}
