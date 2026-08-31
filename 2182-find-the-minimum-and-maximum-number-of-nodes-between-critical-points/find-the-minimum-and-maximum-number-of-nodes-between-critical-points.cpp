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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        int firstPos = -1;
        int lastPos = -1;
        int minDiff = INT_MAX;

        ListNode *prev = NULL;
        ListNode *curr = head;
        int cnt = 1;

        while(curr!=NULL){
            ListNode *nxt = curr->next;
            if(prev!=NULL && nxt!=NULL){
                if((curr->val < prev->val && curr->val < nxt->val) || (curr->val > prev->val && curr->val > nxt->val)){
                    if(lastPos!=-1) minDiff = min(minDiff, (cnt-lastPos));
                    if(firstPos == -1){
                        firstPos = cnt;
                    }

                    lastPos = cnt;
                }
            }

            cnt++;
            prev = curr;
            curr = curr->next;
        }

        if(minDiff == INT_MAX) return {-1,-1};

        return {minDiff, lastPos-firstPos};
    }
};