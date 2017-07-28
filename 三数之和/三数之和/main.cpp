//
//  main.cpp
//  三数之和
//
//  Created by Ruiwen Feng on 2017/7/28.
//  Copyright © 2017年 Ruiwen Feng. All rights reserved.
//
/*
 给出一个有n个整数的数组S，在S中找到三个整数a, b, c，找到所有使得a + b + c = 0的三元组。
 
 样例
 如S = {-1 0 1 2 -1 -4}, 你需要返回的三元组集合的是：
 
 (-1, 0, 1)
 
 (-1, -1, 2)
 

 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
    
    
public:

    
    void quickSort(vector<int> *nums,int low,int high) {
        
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
        
        quickSort(nums,low,left-1);
        quickSort(nums, left+1, high);
    }
    
    
    vector<vector<int> > threeSum(vector<int> &nums) {
      
        quickSort(&nums,0,(int)nums.size()-1);
        
        vector<vector<int> > result;
        
        for (int i = 0; i < nums.size(); i ++) {
            
            bool continueFlag_i = false;
            for (int m = i-1; m >= 0; m--) {
                if (nums[i] == nums[m]) {
                    continueFlag_i = true;
                    break;
                }
            }
            if (continueFlag_i) {
                continue;
            }
            
            
            for (int j = i + 1; j < nums.size(); j ++) {
                
                for (int k = j + 1; k < nums.size(); k ++) {
                    
                    if (nums[i] + nums[j] + nums [k] == 0) {

                        vector<int> innerResult;
                        innerResult.push_back(nums[i]);
                        innerResult.push_back(nums[j]);
                        innerResult.push_back(nums[k]);
                       
                        result.push_back(innerResult);
                        break;
                    }
                }
            }
        }
        
        for (int i = 0; i < result.size(); i ++) {
            for (int j = 0; j < result[i].size(); j ++) {
                cout << result[i][j] << " ";
            }
            cout <<endl;
        }
        if (result.size() <= 1) {
            return result;
        }
        for (int i = 0; i < result.size()-1; i ++) {
            for (int j = (int)result.size() - 1; j > i; j --) {
                if (result[i][0] == result[j][0] && result[i][1] == result[j][1] && result[i][2] == result[j][2]) {
                    result.erase(result.begin()+j);
                }
                if (j == 0) {
                    break;
                }
            }
        }
        
        return result;
    }
};



int main(int argc, const char * argv[]) {
    
    vector<int> temp = {2,7,11,15};
    
    Solution s;
    vector<vector<int> > result;
    result = s.threeSum(temp);
    
    for (int i = 0; i < result.size(); i ++) {
        for (int j = 0; j < result[i].size(); j ++) {
            cout << result[i][j] << " ";
        }
        cout <<endl;
    }
    
    return 0;
}
