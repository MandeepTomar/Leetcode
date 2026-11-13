class Solution {
public:
    vector<vector<int>>ans;
    void solve(int idx,vector<int>&nums,vector<int>temp,int n,int k){
        if(idx>=nums.size()){
            return;
        }
        //let's explore
        for(int i=idx;i<nums.size();i++){
            temp.push_back(nums[i]);
            solve(i+1,nums,temp,n,k);
            if(temp.size()==k){
                ans.push_back(temp);
            }
            temp.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k) {
        vector<int>nums(n,0);
        for(int i=1;i<=n;i++){
            nums[i-1]=i;
        }
        vector<int>temp;
        solve(0,nums,temp,n,k);
        return ans;
    }
};