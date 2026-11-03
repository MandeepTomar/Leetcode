class Solution {
public:
    vector<vector<int>>ans;
    void find(vector<int>&nums,vector<int>&temp,int idx){
        if(idx>=nums.size()){
            ans.push_back(temp);
            return;
        }
        //pick
        temp.push_back(nums[idx]);
        find(nums,temp,idx+1);

        //not picking
        temp.pop_back();
        while(idx<nums.size()-1 && nums[idx+1]==nums[idx]){
            idx++;
        }
        find(nums,temp,idx+1);

    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int>temp;
        find(nums,temp,0);
        return ans;
    }
};