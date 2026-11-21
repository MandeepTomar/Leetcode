class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, 0);
        ans[0] = nums[0];
        if (nums.size() > 1) {
            ans[1] = max(nums[0], nums[1]);
        }

        for (int i = 2; i < nums.size(); i++) {
            ans[i] = max(nums[i] + ans[i - 2], ans[i - 1]);
        }

        return ans.back();
    }
};