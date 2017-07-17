/*
假设你正在爬楼梯，需要n步你才能到达顶部。但每次你只能爬一步或者两步，你能有多少种不同的方法爬到楼顶部？
*/

/* 转化为菲波那切数列问题。 迭代居然不给过。 */

#include <iostream>


using namespace std;

/*
class Solution {
public:

	int fb(int n) {

        if (n == 0||n == 1)
        {
        	return 1;
        }
		else if (n == 2)
		{
			return 2;
		}
		return fb(n-1)+fb(n-2);
	}

    int climbStairs(int n) {
        	
    	return fb(n);
    }
};*/


class Solution {
public:

    int climbStairs(int n) {
        if (n == 0||n == 1)
        {
        	return 1;
        }
        else if (n == 2) 
        {
        	return 2;
        }
    	
        int final_s = 1;//倒数第二个数
        int final_f = 2;//倒数最后一个
        int result = 0;
        
        for (int i = 2; i < n; ++i)
        {	
        	result = final_s + final_f;
        	final_s = final_f;
        	final_f = result;
        }

    	return result;
    }
};

int main(int argc, char const *argv[])
{
	Solution solution;
	cout << solution.climbStairs(0);
	return 0;
}