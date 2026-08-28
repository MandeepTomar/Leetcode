class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        int cumsum=0;
        mp[0]=1;
        int cnt=0;
        for(int n:nums){
            cumsum+=n;
            if(mp.find(cumsum-k)!=mp.end()){
              cnt+=mp[cumsum-k];
            }
            mp[cumsum]++;
        }
        return cnt;
    }
};