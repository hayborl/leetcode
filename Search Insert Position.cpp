//Author: hayborl(Haibo Liu)

//这里直接使用顺序搜索。可以使用二分查找来加速

class Solution {
public:
    int searchInsert(int A[], int n, int target) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int i;
        for (i = 0; i < n; i++)
        {
            if (target <= A[i])
            {
                return i;
            }
        }
        return i;
    }
};