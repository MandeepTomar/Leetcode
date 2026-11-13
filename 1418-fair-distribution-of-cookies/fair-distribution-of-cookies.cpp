class Solution {
public:

    vector<int>result;
    void solve(vector<int>&nums,int idx,vector<int>&cookie,int k){
        if(idx>=nums.size()){
            int maxi=*max_element(cookie.begin(),cookie.end());
            result.push_back(maxi);
            return;
        }
        int cookies=nums[idx];
        for(int j=0;j<k;j++){
            cookie[j]+=cookies;
            //explore
            solve(nums,idx+1,cookie,k);
            cookie[j]-=cookies;
        }
    }
    
    int distributeCookies(vector<int>& nums, int k) {
      vector<int>cookie(k,0);  
      solve(nums,0,cookie,k); 
      int mini=*min_element(result.begin(),result.end());
      return mini;
    }
};