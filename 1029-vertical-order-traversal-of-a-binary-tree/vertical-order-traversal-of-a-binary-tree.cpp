/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<pair<int,pair<int,int>>>ans;
        vector<vector<int>>fans;
        int col = 0;
        int row = 0;
        queue<pair<int, pair<int, TreeNode*>>> q;
        q.push({col, {row, root}});
        ans.push_back({col,{row,root->val}});

        while (!q.empty()) {
            int n = q.size();
            while (n--) {
                auto a = q.front();
                int currcol=a.first;
                int currrow=a.second.first;
                q.pop();
                TreeNode* curr = a.second.second;
                if (curr->left != NULL) {
                    q.push({currcol-1, {currrow + 1, curr->left}});
                    ans.push_back({currcol-1,{currrow+1,curr->left->val}});
                }
                if (curr->right != NULL) {
                    q.push({currcol+1, {currrow + 1, curr->right}});
                    ans.push_back({currcol+1,{currrow+1,curr->right->val}});
                }
            }
        }
        sort(ans.begin(),ans.end());
        int i=0;
        while(i<ans.size()){
            int curr=ans[i].first;
            vector<int>temp;
            while(i<ans.size() && ans[i].first==curr){
                 temp.push_back(ans[i].second.second);
                 i++;
            }
            fans.push_back(temp);
        }
        return fans;
        

    }
};