#include "header.h"

class Solution {
public:
    string tictactoe(vector<string>& board) {
        int n = board.size();
        bool space = false, flag1 = true, flag2 = true, flag3 = true, flag4 = true;
        for (int i = 0; i < n; i++)
        {
            flag1 &= (board[i][i] == board[0][0]);
            flag2 &= (board[i][n - i - 1] == board[0][n - 1]);
            for (int j = 0; j < n; j++)
            {
                space |= (board[i][j] == ' ');
                flag3 &= (board[i][j] == board[i][0]);
                flag4 &= (board[j][i] == board[0][i]);
            }
            if (flag3 && board[i][0] != ' ') return string(1, board[i][0]);
            if (flag4 && board[0][i] != ' ') return string(1, board[0][i]);
            flag3 = flag4 = true;
        }
        if (flag1 && board[0][0] != ' ') return string(1, board[0][0]);
        if (flag2 && board[0][n - 1] != ' ') return string(1, board[0][n - 1]);

        return space == true ? string("Pending") : string("Draw");
    }
};