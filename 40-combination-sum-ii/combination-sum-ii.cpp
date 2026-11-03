class Solution {
public:
    vector<vector<int>>ans;
    void find(vector<int>&c,vector<int>&temp,int target,int idx,int sum){
          if(sum>=target){
            if(sum==target){
                ans.push_back(temp);
            }
            return;
          }
          if(idx>=c.size())return;

          //pick
          
          temp.push_back(c[idx]);
          //explore
          find(c,temp,target,idx+1,sum+c[idx]);
          //not pick
          temp.pop_back();
          while( idx<c.size()-1 && c[idx+1]==c[idx]){
               idx++;
          }
          find(c,temp,target,idx+1,sum);
    }

    vector<vector<int>> combinationSum2(vector<int>& c, int target) {
        sort(c.begin(),c.end());
        vector<int>temp;
        find(c,temp,target,0,0);
        return ans;
    }
};