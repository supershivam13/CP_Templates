class Solution {
    // Directions: Up, Right, Down, Left
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = { 0, 1, 0, -1};

public:
    bool solve(vector<vector<char>>& board, int row, int col, int i, int j, string& word, int index, int n) {
        // Base case: entire word has been matched
        if (index == n)
            return true;

        // Boundary check, Visited check and Mismatch check
        if (i < 0 || j < 0 || i >= row || j >= col || board[i][j] == '.' || board[i][j] != word[index])
            return false;

        char temp = board[i][j];
        board[i][j] = '.';         // Mark current cell as visited

        // Explore all 4 directions
        for (int d = 0; d < 4; d++) {
            int x = i + dx[d], y = j + dy[d];
            if (solve(board, row, col, x, y, word, index + 1, n))
                return true;
        }

        board[i][j] = temp;     // Backtrack: restore the original value

        return false;
    }

    // CODE starts here
    bool exist(vector<vector<char>>& board, string word) {
        int row = board.size();
        int col = board[0].size();
        int n = word.size();

        // Try to start DFS from every cell that matches the first character
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (board[i][j] == word[0]) {
                    if (solve(board, row, col, i, j, word, 0, n))
                        return true;
                }
            }
        }

        return false;
    }
};
