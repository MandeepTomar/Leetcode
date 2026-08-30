class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int mini=INT_MAX;
        int maxi=INT_MIN;
        int minindex=0;
        int maxindex=0;
        int n=nums.size();
        int ans=0;
        if(nums.size()==1){
            return 1;
        }
        for(int i=0;i<nums.size();i++){
            if(nums[i]<mini){
                mini=nums[i];
                minindex=i;
            }
            if(nums[i]>maxi){
                maxi=nums[i];
                maxindex=i;
            }
        }
        int left=max(minindex,maxindex)+1;
        int right=n-min(minindex,maxindex);
        int both=min(minindex,maxindex)+1+(n-max(maxindex,minindex));
        ans=min({left,right,both});
        return ans;
        
    }
};