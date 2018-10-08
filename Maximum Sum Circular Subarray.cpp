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

