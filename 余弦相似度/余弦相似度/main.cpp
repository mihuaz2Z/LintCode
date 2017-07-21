//
//  main.cpp
//  余弦相似度
//
//  Created by Ruiwen Feng on 2017/7/21.
//  Copyright © 2017年 Ruiwen Feng. All rights reserved.
//

/*
 Cosine similarity is a measure of similarity between two vectors of an inner product space that measures the cosine of the angle between them. The cosine of 0° is 1, and it is less than 1 for any other angle.
 
 See wiki: Cosine Similarity
 
 Here is the formula:
 
 cosine-similarity
 
 Given two vectors A and B with the same size, calculate the cosine similarity.
 
 Return 2.0000 if cosine similarity is invalid (for example A = [0] and B = [0]).
 
 
 样例
 给出 A = [1, 2, 3], B = [2, 3 ,4].
 
 返回 0.9926.
 
 给出 A = [0], B = [0].
 
 返回 2.0000
 */

#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

class Solution {
public:
    double cosineSimilarity(vector<int> A, vector<int> B) {

        bool flag = false;
        
        for (int i = 0; i < A.size(); i++) {
            if (A[i] != 0) {
                flag = true;
            }
        }
        
        if (!flag) {
            return 2.;
        }
        
        float head = 0;
        float foot1 = 0;
        float foot2 = 0;
        for (int i = 0; i < A.size(); i ++) {
            head += A[i]*B[i];
            foot1 += A[i]*A[i];
            foot2 += B[i]*B[i];
        }
        return head/(sqrt(foot1)*sqrt(foot2));
    
    }
};



int main(int argc, const char * argv[]) {
    
    Solution s;
    vector<int> A = {0};
    vector<int> B = {0};

    float result = s.cosineSimilarity(A, B);
    cout << result;
    
    return 0;
}
