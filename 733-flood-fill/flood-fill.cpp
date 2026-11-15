class Solution {
public:
    int m,n;
    int original;
    vector<vector<int>>directions={{1,0},{0,1},{-1,0},{0,-1}};
    void solve(int i,int j,int color,vector<vector<int>>&grid){
        if(i<0||j<0||i>=m||j>=n||grid[i][j]!=original){
            return;
        }
        
           grid[i][j]=color;
        
        
        for(auto dir:directions){
            int new_i=i+dir[0];
            int new_j=j+dir[1];
            solve(new_i,new_j,color,grid);
        }
        
        
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        m=image.size();
        n=image[0].size();
        original=image[sr][sc];
        if(original==color){
            return image;
        }
        else{
            solve(sr,sc,color,image);
        }
        
        return image;
    }
};