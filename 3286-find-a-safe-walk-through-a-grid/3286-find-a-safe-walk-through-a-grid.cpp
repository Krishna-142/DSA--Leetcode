class Solution {
public:
    void solve(vector<vector<int>>& grid, int h, int i, int j,
               int n, int m, vector<int>& dx, vector<int>& dy,
               vector<vector<int>>& dp) {

        if (h <= 0) return;
        if (dp[i][j] >= h) return;

        dp[i][j] = h;

        if (i == n - 1 && j == m - 1)
            return;

        for (int k = 0; k < 4; k++) {
            int nx = i + dx[k];
            int ny = j + dy[k];

            if (nx >= 0 && nx < n && ny >= 0 && ny < m) {

                int nh = h;
                if (grid[nx][ny] == 1)
                    nh--;

                solve(grid, nh, nx, ny, n, m, dx, dy, dp);
            }
        }
    }

    bool findSafeWalk(vector<vector<int>>& grid, int health) {

        int n = grid.size();
        int m = grid[0].size();

        if (grid[0][0])
            health--;

        if (health <= 0)
            return false;

        vector<int> dx = {-1, 1, 0, 0};
        vector<int> dy = {0, 0, -1, 1};

        vector<vector<int>> dp(n, vector<int>(m, -1));

        solve(grid, health, 0, 0, n, m, dx, dy, dp);

        return dp[n - 1][m - 1] > 0;
    }
};