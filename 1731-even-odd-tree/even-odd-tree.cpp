/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isEvenOddTree(TreeNode* root) {
        queue<TreeNode* >q;
        q.push(root);
        bool even_level=true;
        while(!q.empty()){
            int prev;
            int n=q.size();
            if(even_level){
                prev=INT_MIN;
            }
            else{
                prev=INT_MAX;
            }
            while(n--){
                TreeNode* curr=q.front();
                q.pop();
                if(even_level && (curr->val<=prev || curr->val%2==0)){
                        return false;
                }
                else if(!even_level && (curr->val%2!=0 || curr->val>=prev)){
                    return false;
                }
                if(curr->left!=NULL){
                    q.push(curr->left);
                }
                if(curr->right!=NULL){
                    q.push(curr->right);
                }
                prev=curr->val;

            }
            even_level=!even_level;
        }
        return true;
    }
};