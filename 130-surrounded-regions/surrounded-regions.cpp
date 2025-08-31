class Solution {
public:
    void display(vector<vector<char>>& board) {
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                cout << board[i][j] << " ";
            }
            cout << endl;
        }
    }
    void dfs(int row, int col, vector<vector<char>>& board) {
        // boundary condition waalo ko chor ke
        if (row < 0 || row > board.size() - 1 || col < 0 ||
            col > board[0].size() - 1 || board[row][col] != 'O') {
            return;
        }
        board[row][col] = '#';
        dfs(row + 1, col, board);
        dfs(row - 1, col, board);
        dfs(row, col + 1, board);
        dfs(row, col - 1, board);
    }
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        // first traversing the first row
        int firstrow = 0;
        for (int j = 0; j < m; j++) {
            if (board[firstrow][j] == 'O') {
                dfs(firstrow, j, board);
            }
        }
        // traversing the last row;
        int lastrow = n - 1;
        for (int j = 0; j < m; j++) {
            if (board[lastrow][j] == 'O') {
                dfs(lastrow, j, board);
            }
        }
        // traversing the first column
        int firstcol = 0;
        for (int i = 0; i < n; i++) {
            if (board[i][firstcol] == 'O') {
                dfs(i, firstcol, board);
            }
        }
        // traversing the last column
        int lastcol = m - 1;
        for (int i = 0; i < n; i++) {
            if (board[i][lastcol] == 'O') {
                dfs(i, lastcol, board);
            }
        }
        display(board);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == 'O')
                    board[i][j] = 'X';
                else if (board[i][j] == '#')
                    board[i][j] = 'O';
                else
                    continue;
            }
        }
    }
};