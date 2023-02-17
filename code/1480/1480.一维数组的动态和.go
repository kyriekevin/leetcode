/*
 * @lc app=leetcode.cn id=1480 lang=golang
 * @lcpr version=21801
 *
 * [1480] 一维数组的动态和
 */

// @lc code=start
func runningSum(nums []int) []int {
	n := len(nums)
	for i := 1; i < n; i++ {
		nums[i] += nums[i - 1]
	}

	return nums
}
// @lc code=end

// @lcpr-div-debug-arg-start
// funName=
// paramTypes= []
// returnType=
// @lcpr-div-debug-arg-end


/*
// @lcpr case=start
// [1,2,3,4]\n
// @lcpr case=end

// @lcpr case=start
// [1,1,1,1,1]\n
// @lcpr case=end

// @lcpr case=start
// [3,1,2,10,1]\n
// @lcpr case=end

 */


