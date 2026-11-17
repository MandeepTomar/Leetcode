class Solution {
public:
    vector<vector<int>>ans;
    void solve(vector<int>&temp,unordered_set<int>&st,vector<int>&nums){
        if(temp.size()==nums.size()){
            ans.push_back(temp);
        }
        for(int i=0;i<nums.size();i++){
            if(st.find(nums[i])==st.end()){
                temp.push_back(nums[i]);
                st.insert(nums[i]);
                solve(temp,st,nums);
                temp.pop_back();
                st.erase(nums[i]);
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<int>temp;
        unordered_set<int>st;
        solve(temp,st,nums);
        return ans;
    }
};