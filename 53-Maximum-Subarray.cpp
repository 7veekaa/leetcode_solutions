#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int maxSum = nums[0];  // Initialize maxSum with the first element
        int currentSum = nums[0];  // Track the current running sum
        
        for (int i = 1; i < n; i++) {
            currentSum = max(nums[i], currentSum + nums[i]);  // Either start new or extend
            maxSum = max(maxSum, currentSum);  // Update maxSum if currentSum is larger
        }
        
        return maxSum;
    }
};
