/*
 * @lc app=leetcode.cn id=724 lang=golang
 * @lcpr version=21801
 *
 * [724] 寻找数组的中心下标
 */

// @lc code=start
func pivotIndex(nums []int) int {
	tot := 0
	for _, v := range nums {
		tot += v
	}

	left := 0
	for i, v := range nums {
		if 2 * left + v == tot {
			return i
		}
		left += v
	}

	return -1
}
// @lc code=end

// @lcpr-div-debug-arg-start
// funName=
// paramTypes= []
// returnType=
// @lcpr-div-debug-arg-end


/*
// @lcpr case=start
// [1, 7, 3, 6, 5, 6]\n
// @lcpr case=end

// @lcpr case=start
// [1, 2, 3]\n
// @lcpr case=end

// @lcpr case=start
// [2, 1, -1]\n
// @lcpr case=end

 */


