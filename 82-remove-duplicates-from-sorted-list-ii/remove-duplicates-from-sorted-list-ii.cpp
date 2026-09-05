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
    void deleteNode(ListNode* &temp, ListNode* &prev, ListNode* &head){
        if(prev==NULL){
            head = temp->next;
        }else prev->next = temp->next;
    }

    ListNode* deleteDuplicates(ListNode* head) {
        unordered_map<int, int> mpp;

        ListNode *temp = head;
        while(temp!=NULL){
            mpp[temp->val]++;
            temp = temp->next;
        }

        temp = head;
        ListNode *prev = NULL;
        while(temp!=NULL){
            if(mpp[temp->val] > 1){
                ListNode *nodeToDelete = temp;

                deleteNode(temp, prev, head);

                if(prev!=NULL) temp = prev->next;
                else temp = head;

                delete(nodeToDelete);
            }else{
                prev = temp;
                temp = temp->next;
            }
        }

        return head;
    }
};