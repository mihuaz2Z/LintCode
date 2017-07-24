//
//  main.cpp
//  Guess Number Game
//
//  Created by Ruiwen Feng on 2017/7/24.
//  Copyright © 2017年 Ruiwen Feng. All rights reserved.
//
/*
 We are playing the Guess Game. The game is as follows:
 
 I pick a number from 1 to n. You have to guess which number I picked.
 
 Every time you guess wrong, I'll tell you whether the number is higher or lower.
 
 You call a pre-defined API guess(int num) which returns 3 possible results (-1, 1, or 0):
 
 样例
 n = 10, I pick 4 (but you don't know)
 
 Return 4. Correct !
 
 */

/*
    这题有陷阱。
    int超过最大值，求中间值的时候会出错。所以用long来装就问题。我擦勒，要注意。
 
 */


#include <iostream>

// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0


using namespace std;

int key = 2147483647;

int guess(int num) {

    if (num < key) {
        return 1;
    }
    else if(num > key)
    {
        return -1;
    }
    else{
        return 0;
    }
    
}

class Solution {
public:

    int guessnum(int n) {

        long top = n;
        long bottom = 1;
        
        while (1) {
            long result = (top+bottom+1)/2;
            int guessResult = guess((int)result);
            if (guessResult == -1) {
                top = result - 1;
            }
            else if (guessResult == 1){
                bottom = result + 1;
            }
            else{
                return (int)result;
            }
            if (bottom > top) {
                
                return n;
            }
        }
        return 0;
    }
    
    int guessNumber(int n) {
        int result = guessnum(n);
        return result;
    }
};


int main(int argc, const char * argv[]) {

    Solution s;
    int result = s.guessNumber(2147483647);
    
    std::cout << result << std::endl;
    return 0;
}
