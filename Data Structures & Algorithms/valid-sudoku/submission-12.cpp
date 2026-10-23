class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
       unordered_map<int, unordered_set<char>> row;
       unordered_map<int, unordered_set<char>> col;
       unordered_map< int, unordered_set<char>> square;

       for ( int r =0; r < 9; r++){
        for(int c = 0; c < 9; c++){
            if ( board[r][c] == '.'){
                continue;
            }

            int box = (r/3) * 3 + (c/3);

            if (row[r].count(board[r][c]) ||  col[c].count(board[r][c]) || square[box].count(board[r][c])){
                return false;

            }
            else {
                row[r].insert(board[r][c]);
                col[c].insert(board[r][c]);
                square[box].insert(board[r][c]);
            }

        }
         
       }
    return true; 
    }
};
