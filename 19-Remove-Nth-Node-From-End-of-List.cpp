/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(nullptr) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* fast = head;
        ListNode* slow = head;

        
        for (int i = 0; i < n; i++) {
            fast = fast->next;
        }

        //agar fast null hai meaning n = size of the list cuz last code block me we are moving fast in accordance of n steps
        if (!fast)
         return head->next;

        
        while (fast->next) {
            fast = fast->next;
            slow = slow->next;
        }

        //when fast is at the end meaning slow nth node ke justt peeche hai 
        slow->next = slow->next->next;

        return head;
    }
};
