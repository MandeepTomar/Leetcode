class Solution {
public:
    int ans = INT_MIN;
    int m, n;
    int total;
    vector<vector<int>> directions = {{-1, 0}, {0, 1}, {0, -1}, {1, 0}};
    void solve(int i, int j, int sum, vector<vector<int>> &grid) {
        ans = max(sum, ans);
        if(ans==total){return;}
        if (i < 0 || j < 0 || i >= m || j >= n) {
            return;
        }
        if (grid[i][j] == 0) {
            return;
        }
        int temp = grid[i][j];
        grid[i][j] = 0;
        //
        for (auto dir : directions) {
            int new_i = i + dir[0];
            int new_j = j + dir[1];
            solve(new_i, new_j, sum + temp, grid);
        }
        grid[i][j] = temp;
    }
    int getMaximumGold(vector<vector<int>>& grid) {
        total=0;
        ans = 0;
        m = grid.size();
        n = grid[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                total+=grid[i][j];
            }
        }
       
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                
                if (grid[i][j] != 0 ) {
                    solve(i, j, 0, grid);
                }
            }
        }
        return ans;
    }
};