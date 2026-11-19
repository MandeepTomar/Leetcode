class Solution {
public:
    int finalscore=0;
    void resetmp(string &str,unordered_map<char,int>&mp){
         for(int i=0;i<str.size();i++){
            mp[str[i]]++;
         }
    }
    bool canformword(string &str,unordered_map<char,int>&mp){
        for(int i=0;i<str.size();i++){
            if(mp[str[i]]<=0){
                int a=i;
                for(int j=0;j<a;j++){
                    mp[str[j]]++;
                }
                return false;
            }
            mp[str[i]]--;
        }
        return true;
    }
    int calculatescore(string &str,vector<int>&score){
        int wordscore=0;
        for(int i=0;i<str.size();i++){
            char ch=str[i];
            wordscore+=score[ch-'a'];
        }
        return wordscore;
    }
    void solve(int idx,int wordscore,vector<string>&words,unordered_map<char,int>&mp,vector<int>& score){
        if(idx==words.size()){
            finalscore=max(wordscore,finalscore);
            return;
        }
        //skip
        solve(idx+1,wordscore,words,mp,score);
        //explore

        if(canformword(words[idx],mp)){
            int calcscore=calculatescore(words[idx],score);
            solve(idx+1,wordscore+calcscore,words,mp,score);
            //need to reset mp to it's original condition
            resetmp(words[idx],mp);

        }
    }
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        unordered_map<char,int>mp;
        for(auto &it:letters){
            mp[it]++;
        }
        solve(0,0,words,mp,score);
        return finalscore;

    }
};