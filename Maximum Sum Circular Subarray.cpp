#include<iostream>
#include<vector> 
using namespace std; 


class Solution {
public:
    int maxSubarraySumCircular(vector<int>& A) {
        int maxSum = -30000, minSum = 30000;
        int curMax = -30000, curMin = 30000;
        int total = 0;
        for(int i = 0; i < A.size(); i++)
        {
        	curMax = max(curMax+A[i], A[i]);
        	maxSum = max(curMax, maxSum);
        	curMin = min(curMin+A[i], A[i]);
        	minSum = min(curMin, minSum);
        	total += A[i];
        }
        return maxSum < 0 ? maxSum : max(maxSum, total-minSum);
    }
};

int main()
{
	Solution s;
	vector<int> A(3, 5);
	A[0] = -1, A[1] = -2; A[2] = -3;
	int res = s.maxSubarraySumCircular(A);
	cout << "res == " << res << endl;
}
