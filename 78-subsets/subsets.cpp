class Solution {
public:
    void subsets(vector<vector<int>>&ans,vector<int>&nums,vector<int>&temp,int idx){
        if(idx>=nums.size()){
            ans.push_back(temp);
            return;
        }
        //pick
        temp.push_back(nums[idx]);
        subsets(ans,nums,temp,idx+1);
        //not pick
        temp.pop_back();
        subsets(ans,nums,temp,idx+1);

    }

    vector<vector<int>> subsets(vector<int>& nums) {
      vector<vector<int>>ans;
      vector<int>temp;
      subsets(ans,nums,temp,0); 
      return ans; 
    }
};