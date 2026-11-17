class Solution {
public:
    int r, c;

    vector<vector<string>> ans;
    vector<vector<int>> directions = {{-1, -1}, {1, 1}, {-1, 1}, {1, -1}};

    bool isvalidcol(int& row, int& col, vector<string>& temp) {
        for (int i = 0; i < r; i++) {
            if (temp[i][col] == 'Q') {
                return false;
            }
        }
        return true;
    }
    bool isvaliddiagonal(int& row, int& col, vector<string>& temp) {

        // How do you traverse diagonally in a vector
        for (auto dir : directions) {
            int new_row = row + dir[0];
            int new_col = col + dir[1];
            while (new_row >= 0 && new_col >= 0 && new_row < r && new_col < c) {

                if (temp[new_row][new_col] == 'Q') {
                    return false;
                }
                new_row += dir[0];
                new_col += dir[1];
            }
        }

        return true;
    }

    void solve(int row, int col, vector<string>& temp) {
        if (row == r) {
            ans.push_back(temp);
            return;
        }
        for (int col = 0; col < c; col++) {
            if (isvalidcol(row, col, temp) && isvaliddiagonal(row, col, temp)) {
                temp[row][col] = 'Q';
                solve(row + 1, col, temp);
            }

            temp[row][col] = '.';
        }
    }

    vector<vector<string>> solveNQueens(int n) {

        vector<string> temp(n, string(n, '.'));
        r = temp.size();
        c = temp[0].size();
        
         solve(0, 0, temp);
        return ans;
    }
};