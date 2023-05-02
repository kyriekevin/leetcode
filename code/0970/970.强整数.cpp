/*
 * @lc app=leetcode.cn id=970 lang=cpp
 * @lcpr version=21907
 *
 * [970] 强整数
 */

// @lc code=start
class Solution
{
public:
    vector<int> powerfulIntegers(int x, int y, int bound)
    {
        set<int> s;
        for (int a = 1; a < bound; a *= x)
        {
            for (int b = 1; a + b <= bound; b *= y)
            {
                s.insert(a + b);
                if (y == 1)
                    break;
            }
            if (x == 1)
                break;
        }

        return vector<int>(s.begin(), s.end());
    }
};
// @lc code=end

/*
// @lcpr case=start
// 2\n3\n10\n
// @lcpr case=end

// @lcpr case=start
// 3\n5\n15\n
// @lcpr case=end

 */
