class Solution {


private:
    int digsum(int nn) {  
     int ds = 0;
    while (nn > 0) {
            ds += nn % 10;
            nn /= 10;
        }
        return ds;
    }
public:
    int maximumSum(vector<int>& nums) {
        unordered_map<int, vector<int>> digitzsum;
        int sol = -1;

        
        for (int num : nums) {
            int sum = digsum(num);
            digitzsum[sum].push_back(num);
        }

        
       
     for (auto& [key, values] : digitzsum) {
         if (values.size() > 1) { 
            sort(values.rbegin(), values.rend());  
            sol = max(sol, values[0] + values[1]); 
            }
        }

 return sol;
    }
};
