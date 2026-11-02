class Solution {
public:
    vector<vector<int>>ans;
    void checksum(vector<int>&c,vector<int>&temp,int target,int sum,int idx){
         if(idx<=c.size() && sum>=target ){
            if(sum==target){
            ans.push_back(temp);}
            return;
         }
         if(idx==c.size()){
            return;
         }
         //pick a number
         temp.push_back(c[idx]);
         //now, we can pick it again.
         checksum(c,temp,target,sum+c[idx],idx);

         //not picking it at all
         temp.pop_back();
         checksum(c,temp,target,sum,idx+1);
    }

    vector<vector<int>> combinationSum(vector<int>& c, int target) {
        vector<int>temp;
        checksum(c,temp,target,0,0);
        return ans;
    }
};