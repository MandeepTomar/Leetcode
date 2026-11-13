class Solution {
public:
    vector<vector<int>>ans;
    void solve(int idx,vector<int>&c,vector<int>&temp,int sum,int target){
         if(sum>target){
            return;
         }
         if(idx>=c.size()){
            if(sum==target){
                ans.push_back(temp);
            }
            return;
         }
         //pick
         temp.push_back(c[idx]);
         solve(idx,c,temp,sum+c[idx],target);
         //not pick
         temp.pop_back();
         solve(idx+1,c,temp,sum,target);
    }

    vector<vector<int>> combinationSum(vector<int>& c, int target) {
        vector<int>temp;
        solve(0,c,temp,0,target);
        return ans;
    }
};