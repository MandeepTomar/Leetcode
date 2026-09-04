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
    bool checkq(TreeNode* curr, queue<TreeNode*> q, int& cnt,int n) {
        if (q.empty()) {
            return true;
        }
        if (cnt % 2 == 0) {
            int min_val = curr->val;
            while (n--) {
                if (q.front()->val <= min_val) {
                    return false;
                }
                q.pop();
            }

        } else if (cnt % 2 != 0) {
            int max_val = curr->val;
            while (n--) {
                if (q.front()->val >= max_val) {
                    return false;
                }
                q.pop();
            }
        }
        return true;
    }

    bool isEvenOddTree(TreeNode* root) {
        if (root == NULL) {
            return false;
        }
        queue<TreeNode*> q;
        q.push(root);
        int cnt = 0;
        while (!q.empty()) {
            int n = q.size();
            while (n--) {
                TreeNode* curr = q.front();
                q.pop();
                bool oddeven = checkq(curr, q, cnt,n);
                if (!oddeven) {
                    return false;
                }

                if (cnt % 2 == 0) {
                    if (curr->val % 2 == 0) {
                        return false;
                    }
                } else {
                    if (curr->val % 2 != 0) {
                        return false;
                    }
                }
                if (curr->left != NULL) {
                    q.push(curr->left);
                }
                if (curr->right != NULL) {
                    q.push(curr->right);
                }
            }
            cnt++;
        }
        return true;
    }
};