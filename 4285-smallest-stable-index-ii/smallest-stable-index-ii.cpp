class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n=nums.size();
       vector<int>maxarr(n,0);
       vector<int>minarr(n,0);
       int maxel=nums[0];
       maxarr[0]=maxel;
       for(int i=1;i<nums.size();i++){
        if(nums[i]>maxel){
            maxel=nums[i];
        }
        maxarr[i]=maxel;
       } 
       int minel=nums[n-1];
       for(int i=n-1;i>=0;i--){
           if(nums[i]<minel){
            minel=nums[i];
           }
           minarr[i]=minel;
       }
       int ans=-1;
       for(int i=0;i<n;i++){
        if(maxarr[i]-minarr[i]<=k){
            ans=i;
            return ans;
        }
       }
       return ans;
    }
};