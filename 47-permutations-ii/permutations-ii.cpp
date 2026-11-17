class Solution {
public:
    vector<vector<int>>ans;
    void solve(vector<int>&nums,unordered_map<int,int>&mp,vector<int>&temp){
        if(temp.size()==nums.size()){
            ans.push_back(temp);
            return;
        }
        for(auto &[num,count]:mp){
            if(count==0){
                continue;
            }
            temp.push_back(num);
            mp[num]--;
            solve(nums,mp,temp);
            temp.pop_back();
            mp[num]++;
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(int x:nums){
            mp[x]++;
        }
        vector<int>temp;
        solve(nums,mp,temp);
        return ans;
    }
};