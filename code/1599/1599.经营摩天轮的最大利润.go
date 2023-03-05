/*
 * @lc app=leetcode.cn id=1599 lang=golang
 * @lcpr version=21801
 *
 * [1599] 经营摩天轮的最大利润
 */

// @lc code=start
func minOperationsMaxProfit(customers []int, boardingCost int, runningCost int) int {
	wait, i := 0, 0
	t, mx := 0, 0
	res := -1

	for wait > 0 || i < len(customers) {
		if i < len(customers) {
			wait += customers[i]
		}
		up := min(4, wait)
		wait -= up
		t += up * boardingCost - runningCost
		i++
		if t > mx {
			mx = t
			res = i
		}
	}

	return res
}

func min(a, b int) int {
	if a > b {
		return b
	}

	return a
}
// @lc code=end

// @lcpr-div-debug-arg-start
// funName=
// paramTypes= []
// returnType=
// @lcpr-div-debug-arg-end


/*
// @lcpr case=start
// [8,3]\n5\n6\n
// @lcpr case=end

// @lcpr case=start
// [10,9,6]\n6\n4\n
// @lcpr case=end

// @lcpr case=start
// [3,4,0,5,1]\n1\n92\n
// @lcpr case=end

 */


