class Solution {
public:
    int m,n;
    int ans=0;
    bool isvalidanswer(vector<vector<int>>&grid){
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0){
                    return false;
                }
            }
        }
        return true;
    }

    vector<vector<int>>directions={{-1,0},{1,0},{0,1},{0,-1}};
    void solve(int i,int j,vector<vector<int>>&grid){
        if(i<0||j<0||i>=m||j>=n || grid[i][j]==-1){
            return;
        }
        if(grid[i][j]==2 && isvalidanswer(grid)){
            ans++;
            return;
        }
        int temp=grid[i][j];
        grid[i][j]=-1;
        for(auto dir:directions){
            int new_i=i+dir[0];
            int new_j=j+dir[1];
            solve(new_i,new_j,grid);
        }
        grid[i][j]=temp;
    }

    int uniquePathsIII(vector<vector<int>>& grid) {
       m=grid.size();
       n=grid[0].size();
       for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(grid[i][j]==1){
                solve(i,j,grid);
            }
        }
       }
       return ans;
    }
};