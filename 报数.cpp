/*
 
 报数指的是，按照其中的整数的顺序进行报数，然后得到下一个数。如下所示：
 
 1, 11, 21, 1211, 111221, ...
 
 1 读作 "one 1" -> 11.
 
 11 读作 "two 1s" -> 21.
 
 21 读作 "one 2, then one 1" -> 1211.
 
 给定一个整数 n, 返回 第 n 个顺序。
 
 注意事项
 
 整数的顺序将表示为一个字符串。
 
 样例
 给定 n = 5, 返回 "111221".
 
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        if (n == 1) {
            return "1";
        }
        string  result = to_string(1);
        
        while (n-1) {
            int temp_i;
            string temp_result = "";
            for (int i = 0; i < result.size(); i ++) {
                temp_i = i;
                int times = 1;
                for (int j = i + 1; j < result.size()&&result[temp_i] == result[j]; j++) {
                    times ++;
                    i++;
                }
                temp_result += to_string(times);
                temp_result += result[temp_i];
            }
            
            result = temp_result;
            n--;
        }
        return result;
    }
};

int main(int argc, const char * argv[]) {
    
    Solution solution;
    string result = solution.countAndSay(10);
    cout << result <<endl;
    
    return 0;
}
