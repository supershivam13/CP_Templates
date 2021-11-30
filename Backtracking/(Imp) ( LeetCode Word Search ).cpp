class Solution {
public:

    //pass board by reference otherwise it'll result in TLE
    bool DFS(vector<vector<char>>& board, string word, int i, int j, int n) {

        //check if all the alphabets in the word is checked (i.e we reached the end of the word)
        if (n == word.size())
            return true;

        //check if i and j are out of bound or if the characters aren't equal
        if (i < 0 || i >= board.size() || j < 0 || j >= board[i].size() || board[i][j] != word[n])
            return false;

        //mark as visited, so that this character can't be used twice
        // Example - if word = 'ABA' and we have A and B adjacent, then from B, dfs call to left will take
        // it as true (i.e we found the word but in real, it is not there )
        board[i][j] = '0';

        //branch out in all 4 directions
        bool status = DFS(board, word, i + 1, j, n + 1) ||  //down
                      DFS(board, word, i, j + 1, n + 1) ||  //right
                      DFS(board, word, i - 1, j, n + 1) ||  //up
                      DFS(board, word, i, j - 1, n + 1);    //left

        //change the character back for other searches
        board[i][j] = word[n];

        return status;
    }

    // Solution starts here
    bool exist(vector<vector<char>>& board, string word) {

        for (int i = 0; i < board.size(); i++)
            for (int j = 0; j < board[i].size(); j++)
                //check if the first characters are equal, only then call DFS
                if (board[i][j] == word[0] && DFS(board, word, i, j, 0))
                    return true;

        return false;
    }
};