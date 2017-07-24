//
//  main.cpp
//  平面列表
//
//  Created by Ruiwen Feng on 2017/7/24.
//  Copyright © 2017年 Ruiwen Feng. All rights reserved.
//

/*
 给定一个列表，该列表中的每个要素要么是个列表，要么是整数。将其变成一个只包含整数的简单列表。
 
 注意事项
 
 如果给定的列表中的要素本身也是一个列表，那么它也可以包含列表。
 
 样例
 给定 [1,2,[1,2]]，返回 [1,2,1,2]。
 
 给定 [4,[3,[2,[1]]]]，返回 [4,3,2,1]。
 
 */

#include <iostream>
#include <vector>

using namespace std;


/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 */
class NestedInteger {
public:
    int value = 0;
    vector<NestedInteger> list;
    
    // Return true if this NestedInteger holds a single integer,
    // rather than a nested list.
    bool isInteger() {
        if(value!=0) {
            return true;
        }
        return false;
    };
    
    // Return the single integer that this NestedInteger holds,
    // if it holds a single integer
    // The result is undefined if this NestedInteger holds a nested list
    int getInteger() {return value;};
    
    // Return the nested list that this NestedInteger holds,
    // if it holds a nested list
    // The result is undefined if this NestedInteger holds a single integer
    vector<NestedInteger> &getList() {return  list;};
    
       bool isInteger() const;
        int getInteger() const;
        const vector<NestedInteger> &getList() const;

};

class Solution {
public:
    // @param nestedList a list of NestedInteger
    // @return a list of integer
    
    vector<int> flatten(vector<NestedInteger> &nestedList) {
        vector<int> result;
        for (int i = 0; i < nestedList.size(); i ++) {
            if (nestedList[i].isInteger()) {
                result.push_back(nestedList[i].getInteger());
            }
            else{
                vector<int>  innerResult = flatten(nestedList[i].getList());
                for (int j = 0; j < innerResult.size(); j ++) {
                    result.push_back(innerResult[j]);
                }
            }
        }
        return result;
        
    }
};


int main(int argc, const char * argv[]) {

    NestedInteger interger_1;
    interger_1.value = 1;
    NestedInteger interger_2;
    interger_2.value = 2;
    NestedInteger interger_3;
    interger_3.value = 3;
    NestedInteger interger_4;
    interger_4.value = 4;

    vector<NestedInteger>temp;
    temp.push_back(interger_1);
    NestedInteger interger_5;
    interger_5.list = temp;
    
    vector<NestedInteger>temp2;
    temp2.push_back(interger_2);
    temp2.push_back(interger_5);
    NestedInteger interger_6;
    interger_6.list = temp2;

    vector<NestedInteger>temp3;
    temp3.push_back(interger_3);
    temp3.push_back(interger_6);
    NestedInteger interger_7;
    interger_7.list = temp3;

    vector<NestedInteger>temp4;
    temp4.push_back(interger_4);
    temp4.push_back(interger_7);
    NestedInteger interger_8;
    interger_8.list = temp4;
    
    vector<NestedInteger> nestedList;
    nestedList.push_back(interger_8);

    Solution  s;
    vector<int > result = s.flatten(nestedList);
    
    for (int i = 0; i < result.size(); i ++) {
        cout<< result[i] << " ";
    }
    
    return 0;
}
