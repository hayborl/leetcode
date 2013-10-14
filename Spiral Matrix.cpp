//Author: hayborl(Haibo Liu)

//此题解决思路和Spiral Matrix II 一致
//使用sr, sc来决定行和列的行进方向，
//minr, maxr, minc, maxc来作为改变方向的判断条件

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        vector<int> result(0);
        
        int m = matrix.size();
        if (m > 0)
        {
            int n = matrix[0].size();
            int total = m * n;
            result.resize(total);
            
            int r = 0, c = 0;
            int minr = 0, minc = 0, maxr = m - 1, maxc = n - 1;
            int sr = 0, sc = 1;
            for (int i = 0; i < total; i++)
            {
                result[i] = matrix[r][c];
                r += sr;
                c += sc;
                
                if (c > maxc)
                {
                    c -= sc;
                    sc = 0;
                    sr = 1;
                    r += sr;
                    minr++;
                }
                if (r > maxr)
                {
                    r -= sr;
                    sr = 0;
                    sc = -1;
                    c += sc;
                    maxc--;
                }
                if (c < minc)
                {
                    c -= sc;
                    sc = 0;
                    sr = -1;
                    r += sr;
                    maxr--;
                }
                if (r < minr)
                {
                    r -= sr;
                    sr = 0;
                    sc = 1;
                    c += sc;
                    minc++;
                }
            }
        }
        return result;
    }
};