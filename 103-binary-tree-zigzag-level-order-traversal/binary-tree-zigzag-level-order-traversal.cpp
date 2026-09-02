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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        if(root==NULL){
            return ans;
        }
        int level=1;
        bool righttoleft=false;
        queue<TreeNode* >q;
        q.push(root);
        while(!q.empty()){
            int n=q.size();
            vector<int>temp;
            while(n--){
                TreeNode* curr=q.front();
                temp.push_back(curr->val);
                q.pop();
                if(curr->left!=NULL){
                    q.push(curr->left);
                }
                if(curr->right!=NULL){
                    q.push(curr->right);
                }
                
            }
            if(level%2==0){
                righttoleft=true;
            }else{
                righttoleft=false;
            }
            
            if(righttoleft){
                reverse(temp.begin(),temp.end());
            }
            ans.push_back({temp});
            level++;
        }
        return ans;
    }
};