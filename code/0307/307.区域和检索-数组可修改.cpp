/*
 * @lc app=leetcode.cn id=307 lang=cpp
 * @lcpr version=21302
 *
 * [307] 区域和检索 - 数组可修改
 */

// @lc code=start
class NumArray {
public:
    int n;
    vector<int> tr, nums;

    int lowbit(int x) {
        return x & -x;
    }

    int query(int x) {
        int res = 0;
        for (int i = x; i; i -= lowbit(i))
            res += tr[i];
        return res;
    }

    void add(int x, int v) {
        for (int i = x; i <= n; i += lowbit(i))
            tr[i] += v;
    }

    NumArray(vector<int>& _nums) {
        nums = _nums;
        n = nums.size();
        tr.resize(n + 1);
        for (int i = 0; i < n; i++)
            add(i + 1, nums[i]);
    }
    
    void update(int index, int val) {
        add(index + 1, val - nums[index]);
        nums[index] = val;
    }
    
    int sumRange(int left, int right) {
        return query(right + 1) - query(left);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */
// @lc code=end



/*
// @lcpr case=start
// 
// @lcpr case=end

 */


