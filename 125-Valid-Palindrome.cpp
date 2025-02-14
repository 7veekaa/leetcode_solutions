class Solution {
public:
    bool isPalindrome(string s) {
        
         int left = 0, right = s.size() - 1;
         //left wala pointer moves to forward character
        
        while (left < right) {
           
            while (left < right && !isalnum(s[left])) {
                left++;
            }
           //right wala moves to prev character 
            while (left < right && !isalnum(s[right])) {
                right--;
            }
            
            
            if (tolower(s[left]) != tolower(s[right])) {
                return false;
            }
            
            left++;
            right--;
        }
        
        return true;
    }
};
    
