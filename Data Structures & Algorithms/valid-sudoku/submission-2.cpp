class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<int, unordered_set<char>> rows;
        unordered_map<int, unordered_set<char>> cols;
        unordered_map<int, unordered_set<char>> squares;
        int sizeBRow = board.size();
        int sizeBCol = board[0].size();
        for(int i = 0; i < sizeBRow; i++){
            for(int j = 0; j < sizeBCol; j++){
                if(board[i][j] == '.'){
                    continue;
                }
                if(rows[i].count(board[i][j]) != 0){
                    return false;
                }
                if(cols[j].count(board[i][j]) != 0){
                    return false;
                }
                if(squares[i/3 * 3 + j/3].count(board[i][j]) != 0){
                    return false;
                }
                rows[i].insert(board[i][j]);
                cols[j].insert(board[i][j]);
                squares[i/3 * 3 + j/3].insert(board[i][j]);
            }
        }
        return true;
    }
};
