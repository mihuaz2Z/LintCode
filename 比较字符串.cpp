/*
 比较两个字符串A和B，确定A中是否包含B中所有的字符。字符串A和B中的字符都是 大写字母
 注意事项
 
 在 A 中出现的 B 字符串里的字符不需要连续或者有序。
 
 样例
 给出 A = "ABCD" B = "ACD"，返回 true
 
 给出 A = "ABCD" B = "AABC"， 返回 false
 
 注意，在for循环里面，把for循环从头开始的代码为i = -1,因为它还会执行一次i++操作。
 */

#include <iostream>
#include <string>
using namespace std;


class Solution {
public:

    bool compareStrings(string A, string B) {
        for (int i = 0; i < A.size() ; i ++) {
            for (int j = 0; j < B.size(); j ++) {
                if (A[i] == B[j]) {
                    string::iterator deleteA = A.begin()+i;
                    string::iterator deleteB = B.begin()+j;
                    A.erase(deleteA);
                    B.erase(deleteB);
                    i = -1;
                    break;
                }
            }
        }
        
        if (B.size() == 0) {
            return true;
        }
        else{
            return false;
        }
    }
};




int main(int argc, const char * argv[]) {

    Solution solution;
    bool result = solution.compareStrings("ABC", "ABC");
    
    cout << "result:" << result <<endl;
    
    return 0;
}
