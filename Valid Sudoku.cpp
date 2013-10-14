//Author: hayborl(Haibo Liu)

//大体思路即是使用一个标志数组flags
//来判断某一行或某一列或一个3x3块中的相应数字是否已经出现过

class Solution {
public:
    bool isValidSudoku(vector<vector<char> > &board) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int brn[9] = {0, 0, 0, 3, 3, 3, 6, 6, 6};
        int bcn[9] = {0, 3, 6, 0, 3, 6, 0, 3, 6};
        for (int i = 0; i < 9; i++)
        {
            bool flags[3][9];
            for (int j = 0; j < 9; j++)
            {
                flags[0][j] = false;
                flags[1][j] = false;
                flags[2][j] = false;
            }
            for (int j = 0; j < 9; j++)
            {
                int br = brn[i] + j / 3;
                int bc = bcn[i] + j % 3;
                int rn[3] = {i, j, br};
                int cn[3] = {j, i, bc};
                for (int k = 0; k < 3; k++)
                {
                    int num = board[rn[k]][cn[k]];
                    if (num != '.')
                    {
                        if (num > 9)
                        {
                            num -= '1';
                        }
                        if (flags[k][num])
                        {
                            return false;
                        }
                        else
                        {
                            flags[k][num] = true;
                        }
                    }
                }
            }
        }
        
        return true;
    }
};