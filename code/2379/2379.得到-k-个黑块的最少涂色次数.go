/*
 * @lc app=leetcode.cn id=2379 lang=golang
 * @lcpr version=21801
 *
 * [2379] 得到 K 个黑块的最少涂色次数
 */

// @lc code=start
func minimumRecolors(blocks string, k int) int {
	cnt := strings.Count(blocks[: k], "W")
	res := cnt

	for i := k; i < len(blocks); i++ {
		if blocks[i] == 'W' {
			cnt++
		}

		if blocks[i - k] == 'W' {
			cnt--
		}

		if cnt < res {
			res = cnt
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
// "WBBWWBBWBW"\n7\n
// @lcpr case=end

// @lcpr case=start
// "WBWBBBW"\n2\n
// @lcpr case=end

 */


