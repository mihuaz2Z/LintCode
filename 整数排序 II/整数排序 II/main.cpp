//
//  main.cpp
//  整数排序 II
//
//  Created by Ruiwen Feng on 2017/7/29.
//  Copyright © 2017年 Ruiwen Feng. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    
    void adjustHeap(vector<int>* A,int size,int parent) {
    
        int left = parent*2+1;
        int right = parent*2+2;
        int max = 0;
        
        if (left > size-1) {
            return;
        }
        else if(right > size-1) {
            max = left;
        }
        else {
            max = (*A)[left] >= (*A)[right] ? left : right;
        }
        
        if ((*A)[parent] < (*A)[max]) {
            swap((*A)[parent] ,(*A)[max]);
            
            adjustHeap(A,size, max);
        }
    }
    
    void heapSort(vector<int>* A) {
    
        if (A->size() <= 1) {
            return;
        }
        
        for (int i = ((int)A->size()-1)/2; i >= 0; i --) {
            adjustHeap(A,(int)A->size(), i);
        }
        
        for (int i = (int)A->size()-1; i >= 1; i --) {
            swap((*A)[0], (*A)[i]);
            adjustHeap(A,i,0);
        }
        
    }

    void sortIntegers2(vector<int>& A) {
        
        heapSort(&A);
        
    }
};


int main(int argc, const char * argv[]) {
    vector<int> a = {1,3,5,3,8,2,1,7,8,6,5};
    Solution s;
    s.sortIntegers2(a);
    for (int i = 0; i < a.size(); i ++) {
        std::cout << a[i] << " ";
    }
    return 0;
}
