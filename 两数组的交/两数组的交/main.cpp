//
//  main.cpp
//  两数组的交
//
//  Created by Ruiwen Feng on 2017/7/21.
//  Copyright © 2017年 Ruiwen Feng. All rights reserved.
//

/*两数组的交 
 样例
 nums1 = [1, 2, 2, 1], nums2 = [2, 2], 返回 [2].
 
 Each element in the result must be unique.
 The result can be in any order.
 
 */


#include <iostream>
#include <vector>
#include <map>

using namespace std;


class Solution {
public:

    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        
        map<int,int> numMap;
        bool hasZeroFlag_1 = false; //nums1是否有0
        bool hasZeroFlag_2 = false; //nums2是否有0


        for (int i = 0; i < nums1.size(); i ++ ) {
            if (nums1[i] == 0) {
                hasZeroFlag_1 = true;
            }
            else{
                numMap.insert(map<int,int>::value_type(nums1[i],nums1[i]));
            }
        }
        nums1.erase(nums1.begin(), nums1.end());
        
    
        for (int i = 0; i < nums2.size(); i ++) {
            if (numMap[nums2[i]]) {
                nums1.push_back(nums2[i]);
            }
            else if (nums2[i] == 0){
                hasZeroFlag_2 = true;
            }
        }
        
        if (hasZeroFlag_1&&hasZeroFlag_2) {
            nums1.push_back(0);
        }
        
        sort(nums1.begin(), nums1.end());
        nums1.erase(unique(nums1.begin(), nums1.end()),nums1.end());

        return nums1;
    }
};

int main(int argc, const char * argv[]) {
    
    Solution solution;
    vector<int> nums1 = {-126,-54,-159,-51,-100,-47,-61,10,0,199,-76,-61,-28,-25,-135,-123,24,-33,148,148,-182,21,-9,-66,112,140,161,57,-181,-16,158,191,-83,129,-27,32,-73,-116,-127,-23,-2,-80,-106,-1,-193,22,-55,-47,-7,-193,-74,-169,154,-100,-31,28,113,-133,196,-164,-2,71,-139,89,-43,165,116,74,-80,-114,-122,-29,17,59,157,-80,-12,100,137,89,134,60,50,19};
    vector<int> nums2 = {157,23,-103,-106,195,126,-181,81,-183,-83,-164,104,-45,190,-52,-144,-82,-65,-78,189,-18,-115,-171,-80,45,77,-117,158,187,-90,-106,-198,-92,-33,66,-164,-167,-101,-2,151,-119,-42,50,175,-125,182,130,-26,36,-166,-195,-126,173,80,-88,190,71,101,-77,123,159,-63,-142,17,-114,123,56,108,-139,31,184,97,128,-161,-21,-59,-129,-181,-150,60,-191,16,-139,70,-138,13,101,29,31,67,-184,163,18,-150,-182,68,-173,168,191,-84,152,31,-151,-91,-141,22};
    vector<int> result = solution.intersection(nums1, nums2);
    for (int i = 0; i < result.size(); i ++ ) {
        cout << result[i] <<endl;
    }
    
    return 0;
}
