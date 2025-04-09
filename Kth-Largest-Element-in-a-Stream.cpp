class KthLargest {
    private:
    int K;
    priority_queue <int, vector<int>,greater<int>> checkpoint;
public:



    KthLargest(int k, vector<int>& nums) {
        
        K=k;
        
        
        for(int& num:nums){
            checkpoint.push(num);
            if(checkpoint.size()>k){
                checkpoint.pop();
            }
        }
        
    }
    
    int add(int val) {
        checkpoint.push(val);
        if(checkpoint.size()>K){
            checkpoint.pop();
        }
        return checkpoint.top();
        
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */