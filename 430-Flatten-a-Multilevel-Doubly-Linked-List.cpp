/**
 * Definition for a Node.
 * class Node {
 * public:
 *     int val;
 *     Node* next;
 *     Node* prev;
 *     Node* child;
 *     
 *     Node(int _val) {
 *         val = _val;
 *         next = NULL;
 *         prev = NULL;
 *         child = NULL;
 *     }
 * };
 */
 
#include <stack>
using namespace std;

class Solution {
public:
    Node* flatten(Node* head) {
        if (!head)
         return head;
        
        Node* curr = head;
        stack<Node*> st;
        
        while (curr) {
           
            if (curr->child) {
                
                if (curr->next)
                    st.push(curr->next);
                
               
                curr->next = curr->child;
                if (curr->next)
                    curr->next->prev = curr;
                
                
                curr->child = NULL;
            }
            
            
            if (!curr->next && !st.empty()) {
                curr->next = st.top();
                st.pop();
                if (curr->next)
                    curr->next->prev = curr;
            }
            
           
            curr = curr->next;
        }
        
        return head;
    }
};
