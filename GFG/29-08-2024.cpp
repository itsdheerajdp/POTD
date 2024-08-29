// Find length of Loop`
class Solution {
  public:
    int findLength(Node* fast,Node* slow){
        int ans=1;
        fast = fast->next;
        while(fast!=slow){
            fast = fast->next;
            ans++;
        }
        return ans;
    }
    int countNodesinLoop(struct Node *head) {
        Node *fast=head, *slow=head;
        
        while(fast!=NULL && fast->next!=NULL){
            fast = fast->next->next;
            slow = slow->next;
            if(fast==slow){
                return findLength(slow,fast);
            }
        }
        
        return 0;
    }
};