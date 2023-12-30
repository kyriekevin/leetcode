/*
 * @lc app=leetcode.cn id=1185 lang=cpp
 * @lcpr version=30112
 *
 * [1185] 一周中的第几天
 */


// @lcpr-template-start
using namespace std;
#include <algorithm>
#include <array>
#include <bitset>
#include <climits>
#include <deque>
#include <functional>
#include <iostream>
#include <list>
#include <queue>
#include <stack>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
// @lcpr-template-end
// @lc code=start
class Solution {
public:
    vector<string> week = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", };
    vector<int> days = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    int is_leap(int year) {
        if (year % 4 == 0 && year % 100 || year % 400 == 0)
            return 1;
        return 0;
    }

    int get_days(int year, int month) {
        int res = days[month];
        if (month == 2)
            res += is_leap(year);
        return res;
    }

    string dayOfTheWeek(int day, int month, int year) {
        int res = 4;
        for (int i = 1971; i < year; i++) 
            res += 365 + is_leap(i);
        for (int i = 1; i < month; i++)
            res += get_days(year, i);
        res += day;
        res %= 7;
        return week[res];
    }
};
// @lc code=end



/*
// @lcpr case=start
// 31\n8\n2019\n
// @lcpr case=end

// @lcpr case=start
// 18\n7\n1999\n
// @lcpr case=end

// @lcpr case=start
// 15\n8\n1993\n
// @lcpr case=end

 */

