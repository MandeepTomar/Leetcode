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
    bool isCousins(TreeNode* root, int x, int y) {
        if(root==NULL){
            return false;
        }
        queue<TreeNode*>q;
        q.push(root);
        if(root->val==x|| root->val==y){
            return false;
        }
        while(!q.empty()){
            int n=q.size();
            int cnt=0;
            while(n--){
                int sameparentnode=0;
                TreeNode* curr=q.front();
                if(curr->val==x){
                   cnt++;
                }
                if(curr->val==y){
                    cnt++;
                }
                q.pop();
                if(curr->left!=NULL){
                    q.push(curr->left);
                    if(curr->left->val==x || curr->left->val==y){
                        sameparentnode++;
                    }
                }
                if(curr->right!=NULL){
                    q.push(curr->right);
                    if(curr->right->val==x || curr->right->val==y){
                        sameparentnode++;
                    }
                }
                if(sameparentnode==2){
                    return false;
                }
            }
            if(cnt==2){
                return true;
            }
        }
        return false;
        
    }
};