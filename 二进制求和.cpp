/*
	
	加法，先加低位。
	字符串存数字，高位在字符串的低位，需要处理一下。


*/


#include <iostream>
#include <string>

using namespace std;


class Solution
{
public:
    string addBinary(string& a, string& b) {
        string temp_a = "";
        for (int i = (int)a.size()-1; i >= 0; i --) {
            temp_a += a[i];
        }
        string temp_b = "";
        for (int i = (int)b.size()-1; i >= 0; i --) {
            temp_b += b[i];
        }
        
        long big_size = a.size() >= b.size()?a.size():b.size();
        string result = "";
        int count_s = 0;
        for (int i = 0; i < big_size ; i++)
        {
            int a_num = 0;
            int b_num = 0;
            if (a.size() > i)
            {
                char a_value = temp_a[i];
                a_num = stoi(&a_value);
            }
            if (b.size() > i)
            {
                char b_value = temp_b[i];
                b_num = stoi(&b_value);
            }
            int result_num = a_num+b_num+count_s;
            count_s = result_num/2;
            result = to_string(result_num%2) +result;
        }
        if (count_s == 1) {
            result = "1" +result;
        }
        return result;
    }
};




int main(int argc, char const *argv[])
{
    Solution solution;
    string a = "11";
    string b = "1";
    
    cout << solution.addBinary(a,b);
    return 0;
}