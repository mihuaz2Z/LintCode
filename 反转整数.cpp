/*
将一个整数中的数字进行颠倒，当颠倒后的整数溢出时，返回 0 (标记为 32 位整数)。
样例
给定 x = 123，返回 321

给定 x = -123，返回 -321

陷阱是第26行 //        	long temp = (long)result * 10;
result * 10 是会超过int的最大值，导致最终值错误的。

*/
#include <iostream>

using namespace std;


class Solution {
public:
    int reverseInteger(int n) {
    int result = 0;
        while(1) {
        	
        	result += n%10;
        	n = n/10;

        	long temp = (long)result * 10;
        	if (temp > 0x8fffffff)
        	{
        		return 0;
        	}
        	else {
        		if (n == 0)
        		{
        			return result;
        		}
        		else {
        			result = 10 * result;
        		}
        	}
        }
    }
};

int main(int argc, char const *argv[])
{
	Solution solution;
	int result = solution.reverseInteger(1534236469);
	cout <<1534236469<<"  "<<result;
	return 0;
}