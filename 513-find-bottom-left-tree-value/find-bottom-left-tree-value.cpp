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
    int findBottomLeftValue(TreeNode* root) {
        if(root==NULL){
            return 0;
        }

        queue<TreeNode* >q;
        TreeNode* firstnode=NULL;
        bool node=false;
        q.push(root);

        while(!q.empty()){
            node=true;
            int n=q.size();

            while(n--){
                if(node){
                    firstnode=q.front();
                    node=false;
                }
                TreeNode* curr=q.front();
                q.pop();
                if(curr->left!=NULL){
                    q.push(curr->left);
                }
                if(curr->right!=NULL){
                    q.push(curr->right);
                }
            }
        }
        return firstnode->val;
    }
};