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
        if(head==NULL ||head->next==NULL || head->next->next==NULL){
            return{-1,-1};
        }
        vector<int>ans;
        ListNode* prev=head;
        ListNode* curr=head->next;
        ListNode* later=head->next->next;
        int currindex=2;
        while(curr!=NULL && later!=NULL){
            if(curr->val>prev->val && curr->val>later->val){
               ans.push_back(currindex);
            }
            else if(curr->val<prev->val && curr->val<later->val){
                ans.push_back(currindex);
            }
            prev=prev->next;
            curr=curr->next;
            later=later->next;
            currindex++;
        }
        if(ans.size()<2){
            return{-1,-1};
        }
        int minval=INT_MAX;
        int maxval=ans.back()-ans.front();
        for(int i=1;i<ans.size();i++){
            int mini=ans[i]-ans[i-1];
            minval=min(minval,mini);
        }
        return{minval,maxval};
    }
};