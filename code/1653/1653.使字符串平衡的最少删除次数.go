/*
 * @lc app=leetcode.cn id=1653 lang=golang
 * @lcpr version=21801
 *
 * [1653] 使字符串平衡的最少删除次数
 */

// @lc code=start
func minimumDeletions(s string) int {
	del := strings.Count(s, "a")
	res := del

	for _, ch := range s {
		del += int((ch - 'a') * 2 - 1)
		if del < res {
			res = del
		}
	}

	return res
}
// @lc code=end

// @lcpr-div-debug-arg-start
// funName=
// paramTypes= []
// returnType=
// @lcpr-div-debug-arg-end


/*
// @lcpr case=start
// "aababbab"\n
// @lcpr case=end

// @lcpr case=start
// "bbaaaaabb"\n
// @lcpr case=end

 */


