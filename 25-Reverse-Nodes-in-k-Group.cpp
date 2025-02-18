class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        
        ListNode* curr = head;
        if(!head){
            return NULL;
        }
        int count = 0;
        
        //list me k nodes check krna padega just to be sure although leetcode aint that stupid
        while (curr && count < k) {
            curr = curr->next;
            count++;
        }
        
       //reversal happenning here
        if (count == k) {
            ListNode* next = NULL;
            ListNode* prev = NULL;
            ListNode* temp = head; 
            
            
            for (int i = 0; i < k; i++) {
                next = temp->next; // temp is head, second pos is next
                temp->next = prev; //temp ko rev krte time peeche krdo, basic reversal logic
                prev = temp; //new head allocation
                temp = next; //new head allocation pt 2, makes sense to me 
            }
            
          //recursive call ji
            head->next = reverseKGroup(temp, k);
            
            
            return prev;
        }
        
        //stupid case of not enough k nodes 
        return head;
    }
};
