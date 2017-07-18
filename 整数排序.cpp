#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
 
    void sortIntegers(vector<int>& A) {
        for (int i = 0; i < A.size();i++ ){
            for (int j = i+1; j < A.size(); ++j)
            {
            	if (A[j] < A[i])
            	{	
            		int temp = A[i];
            		A[i] = A[j];
            		A[j] = temp;
            	}
            }
        }
    }
};

int main(int argc, char const *argv[])
{
	Solution solution;
	int value[] = {6,4,3,45,1};
	vector<int> v;
	for (int i = 0; i < sizeof(value)/sizeof(int); ++i)
	{
		v.push_back(value[i]);
	}

	solution.sortIntegers(v);

	for (int i = 0; i < v.size(); ++i)
	{
		cout<<v[i] <<" ";
	}

	return 0;
}