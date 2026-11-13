class Solution {
public:
int count;
int maxi=INT_MIN;
    void solve(int idx,int count,vector<vector<int>>&requests,vector<int>&resultant){
              //base case
              if(idx>=requests.size()){
                bool allzero=true;
              
              for(auto it:resultant){
                if(it!=0){
                    allzero=false;
                }

              }
              if(allzero==true){
                 maxi=max(count,maxi);
              }
              return;
              }

         //
         int from=requests[idx][0];
         int to=requests[idx][1];
         resultant[from]--;
         resultant[to]++;
         solve(idx+1,count+1,requests,resultant);
         resultant[from]++;
         resultant[to]--;
         solve(idx+1,count,requests,resultant);
    }

    int maximumRequests(int n, vector<vector<int>>& requests) {
        vector<int>resultant(n,0);
        solve(0,0,requests,resultant);
        return maxi;
    }
};