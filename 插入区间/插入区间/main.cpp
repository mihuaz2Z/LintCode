//
//  main.cpp
//  插入区间
//
//  Created by Ruiwen Feng on 2017/7/24.
//  Copyright © 2017年 Ruiwen Feng. All rights reserved.
//

/*
 插入区间
 
 给出一个无重叠的按照区间起始端点排序的区间列表。
 
 在列表中插入一个新的区间，你要确保列表中的区间仍然有序且不重叠（如果有必要的话，可以合并区间）。
 
 样例
 插入区间[2, 5] 到 [[1,2], [5,9]]，我们得到 [[1,9]]。
 
 插入区间[3, 4] 到 [[1,2], [5,9]]，我们得到 [[1,2], [3,4], [5,9]]。
 
 */

#include <iostream>
#include <vector>

using namespace std;

// * Definition of Interval:
class Interval {
public:
    int start, end;
    Interval(int start, int end) {
        this->start = start;
        this->end = end;
    }
};

class Solution {
public:

    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {

        if (intervals.size() == 0) {
            intervals.insert(intervals.begin(), vector<Interval>::value_type(newInterval));
            return intervals;
        }
        
        for (int i = 0; i < intervals.size(); i++) {
            if (newInterval.end < intervals[i].start) {
                //直接插入
                intervals.insert(intervals.begin()+i, vector<Interval>::value_type(newInterval));
                break;
            }
            else if (newInterval.start > intervals[i].end) {
                if (i == intervals.size()-1) {
                    //直接插入
                    intervals.insert(intervals.begin()+i+1, vector<Interval>::value_type(newInterval));
                    break;
                }
                else
                {
                    continue;
                }
            }
            else {
                //有相交部分。
                intervals[i].start = intervals[i].start<newInterval.start?intervals[i].start:newInterval.start;
                intervals[i].end = intervals[i].end>newInterval.end?intervals[i].end:newInterval.end;
                break;
            }
        }
        
        for (int i = 0; i < intervals.size(); i ++) {
            cout << intervals[i].start << "-"<<intervals[i].end<<endl;
        }
        
        //合并区间：
        for (int i = 0; i < intervals.size()-1; i ++) {
            if (intervals[i].end >= intervals[i+1].start) {
                if (intervals[i].end >= intervals[i+1].end) {
                    intervals.erase(intervals.begin()+i+1);
                    i-=2;
                }
                else {
                    intervals[i].end = intervals[i+1].end;
                    intervals.erase(intervals.begin()+i+1);
                    i-=2;
                }
            }
        }
        return intervals;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    vector<Interval> vec;
    Interval inter1 = *new Interval(1,5);
    Interval inter2 = *new Interval(7,8);
    Interval inter3 = *new Interval(10,13);
    vec.push_back(inter1);
    vec.push_back(inter2);
    vec.push_back(inter3);

    Interval inter4 = *new Interval(6,10);

    
    vector<Interval> result = s.insert(vec, inter4);
    
    for (int i = 0; i < result.size(); i ++) {
        cout << result[i].start << "-"<<result[i].end<<endl;
    }
    
    
    return 0;
}
