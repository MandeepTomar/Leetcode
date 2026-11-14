class Solution {
public:
    int ans = 0;
    bool isvalid(vector<int>& temp, int key, int k) {
        if (temp.empty()) {
            return true;
        }
        for (auto it : temp) {
            if (abs(it - key) == k) {
                return false;
            }
        }
        return true;
    }
    void solve(int idx, vector<int>& nums, vector<int>& temp, int k) {
        if (!temp.empty()){
            ans++;
        }
        //
        for (int i = idx; i < nums.size(); i++) {
            if (isvalid(temp, nums[i], k)) {
                temp.push_back(nums[i]);
                solve(i + 1, nums, temp, k);
                temp.pop_back();
            }
        }
    }
    int beautifulSubsets(vector<int>& nums, int k) {
        vector<int> temp;
        solve(0, nums, temp, k);

        return ans;
    }
};