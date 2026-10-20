class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<int, unordered_set<char>> accountedForCol;
        unordered_map<int, unordered_set<char>> accountedForRow;
        unordered_map<int, unordered_set<char>> accountedForSquare;
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board.size(); j++){
                if(board[i][j] == '.'){
                    continue;
                } else {
                    if(accountedForCol[j].count(board[i][j]) != 0){
                        return false;
                    }
                    if(accountedForRow[i].count(board[i][j]) != 0){
                        return false;
                    }
                    if(accountedForSquare[(i/3)*3 + (j/3)].count(board[i][j]) != 0){
                        return false;
                    }
                    accountedForCol[j].insert(board[i][j]);
                    accountedForRow[i].insert(board[i][j]);
                    accountedForSquare[(i/3)*3 + (j/3)].insert(board[i][j]);
                }
            }
        }
        return true;
    }
};
