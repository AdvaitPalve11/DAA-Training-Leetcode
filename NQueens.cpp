class Solution {
public:
    int ans = 0;

    void solve(int row, int n, vector<bool>& col, vector<bool>& d1, vector<bool>& d2){
         
        if (row == n) {
            ans++;
            return;
        }

        for (int c = 0; c < n; c++) {
            
            int diag1 = row - c + n - 1;
            int diag2 = row + c;

            if (col[c] || d1[diag1] || d2[diag2])
                continue;

            col[c] = d1[diag1] = d2[diag2] = true;

            solve(row + 1, n, col, d1, d2);

            col[c] = d1[diag1] = d2[diag2] = false;
        }
    }

    int totalNQueens(int n) {

        ans = 0;

        vector<bool> col(n, false);
        vector<bool> d1(2 * n - 1, false);
        vector<bool> d2(2 * n - 1, false);

        solve(0, n, col, d1, d2);

        return ans;
    }
};