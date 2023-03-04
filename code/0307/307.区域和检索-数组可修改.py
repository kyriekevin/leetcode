#
# @lc app=leetcode.cn id=307 lang=python3
# @lcpr version=21302
#
# [307] 区域和检索 - 数组可修改
#

# @lc code=start
class NumArray:
    def __init__(self, nums: List[int]):
        self.num = nums
        self.n = len(nums)
        self.tr = [0] * (self.n + 1)
        for i, x in enumerate(nums, 1):
            self.add(i, x)

    def update(self, index: int, val: int) -> None:
        self.add(index + 1, val - self.num[index])
        self.num[index] = val

    def sumRange(self, left: int, right: int) -> int:
        return self.query(right + 1) - self.query(left)
    
    def lowbit(self, x: int) -> int:
        return x & -x

    def add(self, x: int, v: int) -> None:
        i = x
        while i <= self.n:
            self.tr[i] += v
            i += self.lowbit(i)
    
    def query(self, x: int) -> int:
        res, i = 0, x
        while i:
            res += self.tr[i]
            i -= self.lowbit(i)
        return res



# Your NumArray object will be instantiated and called as such:
# obj = NumArray(nums)
# obj.update(index,val)
# param_2 = obj.sumRange(left,right)
# @lc code=end



#
# @lcpr case=start
# 
# @lcpr case=end

#


