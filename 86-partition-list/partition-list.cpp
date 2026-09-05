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
    void insertNode(ListNode* &node, ListNode* &head, ListNode* &prev){
        if(head==NULL){
            head = node;
            prev = head;
            return;
        }

        prev->next = node;
        prev = node;
    }

    ListNode* partition(ListNode* head, int x) {
        if(head == NULL) return NULL;

        ListNode *head1 = NULL;
        ListNode *head2 = NULL;

        ListNode *temp = head;
        ListNode *prev1 = NULL;
        ListNode *prev2 = NULL;

        while(temp!=NULL){
            ListNode* nextNode = temp->next; 
            if(temp->val < x){
                insertNode(temp, head1, prev1);
            }else{
                insertNode(temp, head2, prev2);
            }
            temp = nextNode;
        }

        if(prev1 != NULL) prev1->next = NULL; 
        if(prev2 != NULL) prev2->next = NULL;

        if(head1 == NULL) return head2;

        prev1->next = head2;

        return head1;
    }
};