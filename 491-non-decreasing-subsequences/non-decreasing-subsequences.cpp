class Solution {
public:
    vector<vector<int>> ans;
    set<vector<int>>a;
    bool isvalid(vector<int>& temp, int idx, vector<int>& nums) {
        if (temp.empty()) {
            return true;
        }
        else if (temp[temp.size() - 1] <= nums[idx]) {
            return true;
        }
        return false;
    }
    void backtrack(int idx, vector<int>& nums, vector<int>& temp) {
        // base condition
        if (idx >= nums.size()) {
            
                
            
            return;
        }

        for (int i = idx; i < nums.size(); i++) {
            if (isvalid(temp, i, nums)) {
                temp.push_back(nums[i]);
                if(temp.size()>=2){
                a.insert(temp);}

                backtrack(i + 1, nums, temp);
                temp.pop_back();
            }
        }
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<int> temp;
        backtrack(0, nums, temp);
        for(auto it:a){
            ans.push_back(it);
        }
        return ans;
    }
};