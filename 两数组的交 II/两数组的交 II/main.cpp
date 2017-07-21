//
//  main.cpp
//  两数组的交 II
//
//  Created by Ruiwen Feng on 2017/7/21.
//  Copyright © 2017年 Ruiwen Feng. All rights reserved.
//

/*
 两数组的交 II
 计算两个数组的交
 
 注意事项
 
 每个元素出现次数得和在数组里一样
 答案可以以任意顺序给出
 
 样例
 nums1 = [1, 2, 2, 1], nums2 = [2, 2], 返回 [2, 2].
 */

#include <iostream>
#include <map>
#include <vector>

using namespace std;

//时间复杂度不符合。
/*
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
    
        if (nums1.size() == 0 || nums2.size() == 0) {
            return {};
        }
        
        vector<int> result;
        for (int i = 0; i < nums1.size(); i ++) {
            for (int j = 0; j < nums2.size(); j ++) {
                if (nums1[i] == nums2[j]) {
                    result.push_back(nums1[i]);
                    nums2.erase(nums2.begin()+j);
                    break;
                }
            }
        }
        
        return result;
    }
};*/


class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() == 0 || nums2.size() == 0) {
            return {};
        }
       
        map<int,int> map_z;
        
        for (int i = 0; i < nums1.size(); i ++) {
            if (map_z[nums1[i]]) {
                map_z[nums1[i]] ++;
            }else{
                map_z[nums1[i]] = 1;
            }
        }
        
        nums1.erase(nums1.begin(),nums1.end());
        
        for (int j = 0; j < nums2.size() ; j ++) {
            if (map_z[nums2[j]]) {
                nums1.push_back(nums2[j]);
                map_z[nums2[j]] --;
            }
        }
        return nums1;
    }
};

int main(int argc, const char * argv[]) {

    Solution solution;
    vector<int> nums1 = {1,2,3,2,0};
    vector<int> nums2 = {1,2,2,0,0,0,0,0};

    
    vector<int> result = solution.intersection(nums1, nums2);
    for (int i = 0; i < result.size(); i ++) {
        cout << result[i] << " ";
    }
    cout << " end" << endl;
    
    
    return 0;
}
