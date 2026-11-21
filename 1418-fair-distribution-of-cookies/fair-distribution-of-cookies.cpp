class Solution {
public:
    int result=INT_MAX;
    int n;
    void solve(int idx,vector<long long>&children,vector<int>&cookies,int k){
        if(idx>=cookies.size()){
            int maxi=*max_element(children.begin(),children.end());
            result=min(maxi,result);
            return;
        }
        int cookie=cookies[idx];
        for(int i=0;i<k;i++){
            
            children[i]+=cookie;
           solve(idx+1,children,cookies,k);
           children[i]-=cookie;
        }
    }

    int distributeCookies(vector<int>& cookies, int k) {
        n=cookies.size();
        vector<long long>children(k,0);
        solve(0,children,cookies,k);
        return result;
    }
};