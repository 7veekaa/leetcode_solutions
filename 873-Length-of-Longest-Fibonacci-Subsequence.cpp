class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {

        int n = arr.size();
        unordered_map<int, int> aa;

        int sol = 0;
        

       
        for (int i = 0; i < n; i++) {
            aa[arr[i]] = i;
        }

        
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) { 
                int pre = arr[i];
                int now = arr[j];
                int coming = pre + now;
                int le = 2; 

              
     while (aa.find(coming) != aa.end()) { 
                    le++;
                    pre = now;
                    now = coming;
                    coming = pre + now;
                    sol = max(sol, le);
                }
            }
        }

     return sol;  
    }
};
