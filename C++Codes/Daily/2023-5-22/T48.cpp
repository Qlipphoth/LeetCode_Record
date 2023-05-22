#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int i, j, temp, row = matrix.size(), col = matrix[0].size();
        for (i = 0; i < row; i++){
            for (j = i; j < col; j++){
                if (i == j) continue;
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        for (i = 0; i < (int)(col / 2); i++){
            for (j = 0; j < row; j++){
                swap(matrix[j][i], matrix[j][col - i - 1]);
            }
        }
    }
};