class Solution {
public:
    int result=INT_MAX;
    int n;
    void solve(int idx,vector<int>&workers,vector<int>&jobs,int k){
        if(idx>=n){
            int maxi=*max_element(workers.begin(),workers.end());
            result=min(result,maxi);
            return;
        }
        int job=jobs[idx];
        for(int i=0;i<k;i++){
        
        if(workers[i]+job>=result){
            continue;
        }if(i>0 && workers[i]==workers[i-1]){
            continue;
        }
        else
           
           workers[i]+=job;
           
           solve(idx+1,workers,jobs,k);
           workers[i]-=job;
           }
        }
    
    
    int minimumTimeRequired(vector<int>& jobs, int k) {
        sort(jobs.begin(),jobs.end());
        n=jobs.size();
        vector<int>workers(n,0);
        solve(0,workers,jobs,k);
        return result;
    }
};