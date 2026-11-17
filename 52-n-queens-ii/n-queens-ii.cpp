class Solution {
public:
    
    vector<vector<int>> directions = {{-1, -1}, {-1, 1}};
    bool isvalidcol(int row, int col,int &n, vector<string>& board) {
        for (int i = row - 1; i >= 0; i--) {
            if (board[i][col] == 'Q') {
                return false;
            }
        }
        return true;
    }
    bool isvaliddiagonal(int row,int col,int &n,vector<string>&board){
        for(auto dir:directions){
            int new_row=row+dir[0];
            int new_col=col+dir[1];
            while(new_row>=0 && new_col>=0 && new_row<n && new_col<n){
                if(board[new_row][new_col]=='Q'){
                    return false;
                }
                new_row+=dir[0];
                new_col+=dir[1];
            }
        }
        return true;
    }
    void solve(int row, int &cnt,int &n, vector<string>& board) {
        if (row == n) {
            cnt++;
            return;
        }
        for (int col = 0; col < n; col++) {
            if (isvalidcol(row, col,n, board) &&
                isvaliddiagonal(row, col,n, board)) {
                board[row][col] = 'Q';
                solve(row + 1, cnt,n, board);
                board[row][col] = '.';
            }
        }
    }

    int totalNQueens(int n) {
        
        int cnt=0;
        vector<string> board(n, string(n, '.'));
        solve(0, cnt,n, board);
        return cnt;
    }
};