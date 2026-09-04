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
    int minDepth(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        queue<TreeNode* >q;
        q.push(root);
        int depth=1;
        while(!q.empty()){
            int n=q.size();
            while(n--){
                TreeNode* curr=q.front();
                q.pop();
                if(curr->left==NULL && curr->right==NULL){
                    return depth;
                }
                if(curr->left!=NULL){
                    q.push(curr->left);
                }
                if(curr->right!=NULL){
                    q.push(curr->right);
                }
            }
            depth++;
        }
        return depth;
    }
};