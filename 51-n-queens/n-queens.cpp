class Solution {
public:
    vector<vector<int>> directions{{-1, -1}, {-1, 1}};
    bool isvalidcol(int row, int col, int n, vector<string>& board) {
        for (int i = row; i >= 0; i--) {
            if (board[i][col] == 'Q') {
                return false;
            }
        }
        return true;
    }
    bool isvaliddiagonal(int row, int col, int n, vector<string>& board) {
        for (auto& dir : directions) {
            int new_i = row;
            int new_j = col;
            while (new_i >= 0 && new_j >= 0 && new_i < n && new_j < n) {
                if (board[new_i][new_j] == 'Q') {
                    return false;
                }
                new_i += dir[0];
                new_j += dir[1];
            }
        }
        return true;
    }

    vector<vector<string>> ans;
    void solve(int row, int n, vector<string>& board) {
        if (row == n) {
            ans.push_back(board);
            return;
        }
        for (int i = 0; i < n; i++) {
            if (isvalidcol(row, i, n, board) &&
                isvaliddiagonal(row, i, n, board)) {

                board[row][i] = 'Q';
                solve(row + 1,  n, board);
                board[row][i] = '.';
            }
        }
    }
        vector<vector<string>> solveNQueens(int n) {
            vector<string> board(n, string(n, '.'));
            solve(0, n, board);
            return ans;
        }
    };