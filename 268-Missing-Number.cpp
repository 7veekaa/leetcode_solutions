class Solution {

    // get exact number of distinct numbers in the array by size of array
    //loop through array and find missing number , my first approach would be to just sort, jo number missing hoga, return that
    //sorting can be done based on bits of the numbers - brute approach


    //better would involve sets and index, tc sahi aajaegi but sc optimize krni hogi

    //optimal includes xoring index number and index val to get the one which doesnt cancel out which in turn is the answer


public:
    int missingNumber(vector<int>& nums) {
        int sol = nums.size(); 
        for (int i = 0; i < nums.size(); i++) {
         sol ^= i ^ nums[i]; 
        }
        
             return sol;
    }
};