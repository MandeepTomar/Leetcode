class Solution {
public:
    vector<vector<string>>ans;
    int n;
    bool ispalindrome(string &s,int left,int right){
        if(left>=right){
            return true;
        }
        if(s[left]!=s[right]){
            return false;
        }
        return ispalindrome(s,left+1,right-1);
    }
    void backtrack(string &s,int idx,vector<string>&temp){
        if(idx==n){
            ans.push_back(temp);
            return;
        }
        for(int i=idx;i<n;i++){
            if(ispalindrome(s,idx,i)){
              temp.push_back(s.substr(idx,i-idx+1));

            
            backtrack(s,i+1,temp);
            temp.pop_back();}
        }
    }
    vector<vector<string>> partition(string s) {
        vector<string>temp;
        n=s.size();
        backtrack(s,0,temp);
        return ans;
    }
};