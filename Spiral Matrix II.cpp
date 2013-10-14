//Author: hayborl(Haibo Liu)

//本题还比较简单，
//使用sr, sc来决定行和列的行进方向，
//minr, maxr, minc, maxc来作为改变方向的判断条件

class Solution {
public:
    vector<vector<int> > generateMatrix(int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        vector<vector<int>> results(n);
        for (int i = 0; i < n; i++)
        {
            results[i].resize(n);
        }
        
        int r = 0, c = 0;
        int minr = 0, minc = 0, maxr = n - 1, maxc = n - 1;
        int sr = 0, sc = 1;
        for (int i = 1; i <= n * n; i++)
        {
            results[r][c] = i;
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
        
        return results;
    }
};