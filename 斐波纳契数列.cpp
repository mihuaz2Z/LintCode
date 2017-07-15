#include <iostream>

/*
查找斐波纳契数列中第 N 个数。

所谓的斐波纳契数列是指：

前2个数是 0 和 1 。
第 i 个数是第 i-1 个数和第i-2 个数的和。
斐波纳契数列的前10个数字是：

0, 1, 1, 2, 3, 5, 8, 13, 21, 34 ...

*/

class Solution{
public:
  
    int fibonacci(int n) {

    	int first = 0;
    	int second = 1;

    	if (n == 0||n == 1)
    	{
    		return first;
    	}
    	else if (n ==2) {
    		return second;
    	}

    	int result = 0;

    	for (int i = 2; i < n; ++i)
    	{
			result = first + second;    		
			first = second;
			second = result;
    	}
    	return result;    	
    }
};


int main(int argc, char const *argv[])
{
	
	Solution solution;
	int result = solution.fibonacci(41);
	std::cout << result;
	return 0;
}