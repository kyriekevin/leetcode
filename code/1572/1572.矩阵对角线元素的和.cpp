class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int n = mat.size(), res = 0, mid = n / 2;
        for (int i = 0; i < n; i++)
            res += mat[i][i] + mat[i][n - 1 - i];
        
        return res - mat[mid][mid] * (n & 1);
    }
};
