class Solution {
public:
    vector<vector<int>>ans;
    void find(vector<int>&nums,vector<int>&temp,int k, int n,int sum,int idx){
        //base case
        if(temp.size()==k){
            if(sum==n){
                ans.push_back(temp);
            }
            return;
        }
        if(idx>=nums.size()){
            return;
        }
        //pick
        temp.push_back(nums[idx]);
        find(nums,temp,k,n,sum+nums[idx],idx+1);
        //not pick
        temp.pop_back();
        find(nums,temp,k,n,sum,idx+1);
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int>nums;
        vector<int>temp;
        for(int i=1;i<=9;i++){
            nums.push_back(i);
        }
        find(nums,temp,k,n,0,0);
        return ans;
    }
};