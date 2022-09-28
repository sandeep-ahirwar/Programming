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
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        if(head -> next == NULL){
            return NULL;
        }
        
        int count = 1;
        ListNode* curr = head;
        
        while(curr!= NULL){
            curr=curr->next;
            count++;
        }
        
        int c = count-n+1;
        count = 1;
        curr=head;
        ListNode* temp =NULL;
        ListNode* prev =NULL;

        
        while(curr!=NULL){
            if (count == c){
                if (c == 1){
                    temp = curr->next;
                    curr->next = NULL;
                    head = temp;
                    return head;
                    
                }
                else{
                    temp = curr->next;
                    prev->next = temp;
                    curr->next = NULL;
                    curr = temp;
                    return head;
                }
            }
        }
        return head;
    }
};