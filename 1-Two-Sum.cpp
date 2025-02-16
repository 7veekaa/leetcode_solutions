class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        //hash mapping krlo values and indices ki 
        //traverse thorugh the array
        //normal check krte chalo if ans matches the sum
        //return if yes if no just store
       
       
        unordered_map<int, int> numIndex;
        
        
        
        for (int i = 0; i < nums.size(); i++) {
         int complement = target - nums[i];

            
            if (numIndex.find(complement) != numIndex.end()) {
                return {numIndex[complement], i};
            }

            
            numIndex[nums[i]] = i;
        }

        
        
        return {}; //this is for just in case 
    }
}; 
        
