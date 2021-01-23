/*
 * @lc app=leetcode.cn id=130 lang=cpp
 *
 * [130] 被围绕的区域
 */

// @lc code=start
class Solution {
public:
    void solve(vector<vector<char>>& board) {
        if(board.empty()) return;
        for(int i = 0; i < board.size(); ++i) {
            for(int j = 0; j < board[0].size(); ++j) {
                // cout << board[i][j] << " ";
            }
            // cout << endl;
        }
        // cout << endl;
        vector<vector<bool>> tmp_board(board.size(), vector<bool>(board[0].size(), false));
        for(int i = 0; i < board.size(); ++i) {
            fillBoard(board, tmp_board, i, 0);
            fillBoard(board, tmp_board, i, board[0].size()-1);
        }
        for(int i = 0; i < board[0].size(); ++i) {
            fillBoard(board, tmp_board, 0, i);
            fillBoard(board, tmp_board, board.size()-1, i);
        }
        for(int i = 0; i < board.size(); ++i) {
            for(int j = 0; j < board[0].size(); ++j) {
                if(!tmp_board[i][j]) board[i][j] = 'X';
                // cout << board[i][j] << " ";
            }
            // cout << endl;
        }
    }
    void fillBoard(vector<vector<char>>& board, vector<vector<bool>>& board_flag, int x, int y) {
        if(x < 0 || x >= board.size()) return;
        if(y < 0 || y >= board[0].size()) return;
        if(board[x][y] == 'X' || board_flag[x][y]) return;
        board_flag[x][y] = true;
        fillBoard(board, board_flag, x-1, y);
        fillBoard(board, board_flag, x+1, y);
        fillBoard(board, board_flag, x, y-1);
        fillBoard(board, board_flag, x, y+1);
    }
};
// @lc code=end

