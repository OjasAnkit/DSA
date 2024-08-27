#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Nth stairs
int stairHelper(int n, int dp[])
{
    cout << "Inside for n value: " << n << endl;
    if (n == 1 || n == 2)
        return n;
    if (dp[n] != -1)
        return dp[n]; // memoization

    cout << dp[n] << endl;
    cout << "Processing for n value: " << n << endl;

    int nMinus1 = stairHelper(n - 1, dp);
    int nMinus2 = stairHelper(n - 2, dp);

    dp[n] = nMinus1 * 1 + nMinus2 * 1;
    return dp[n];
}

int climbStairs(int n)
{
    int dp[n + 1];
    fill(dp, dp + n + 1, -1);

    return stairHelper(n, dp);
}

// Min perfect squares for sum N
int perfectSquaresHelper(int n, int dp[])
{
    int ans = INT_MAX;
    // if (n == 0)
    // return 1;
    if (n == 0 || n == 1 || n == 2 || n == 3)
        return n;

    if (dp[n] != -1)
        return dp[n];

    for (int i = 1; i * i <= n; i++)
    {
        int val = perfectSquaresHelper(n - i * i, dp) + 1;
        if (val < ans)
        {
            // cout << ans << ", " << dp[n] << " for value of n: " << n << endl;
            ans = val;
        }
    }
    cout << "Answer for n value " << n << " is: " << ans << endl;

    dp[n] = ans;
    return dp[n];
}

int perfectSquares(int n)
{
    int dp[n + 1];
    fill(dp, dp + n + 1, -1);

    return perfectSquaresHelper(n, dp);
}

// Unique Paths
int uniquePathsHelper(int m, int n, vector<vector<int>> &dp)
{
    // base case
    if (m == 0)
        return 1;
    if (n == 0)
        return 1;

    if (dp[m][n] != -1)
        return dp[m][n];

    int pathsBeforeRight = uniquePathsHelper(m - 1, n, dp);
    int pathsBeforeDown = uniquePathsHelper(m, n - 1, dp);

    dp[m][n] = pathsBeforeRight + pathsBeforeDown;
    return pathsBeforeRight + pathsBeforeDown;
}

int uniquePaths(int m, int n)
{
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));

    return uniquePathsHelper(m - 1, n - 1, dp);
}

// Unique Paths II
int uniquePaths2Helper(int m, int n, vector<vector<int>> &obstacleGrid, vector<vector<int>> &dp)
{
    // checking if this is a valid position (should be inbounds and not blocked)
    if (m < 0 || n < 0 || obstacleGrid[m][n] == 1)
        return 0;

    // base case
    if (m == 0 && n == 0)
        return 1;

    if (dp[m][n] != -1)
        return dp[m][n];

    int pathsBeforeRight = uniquePaths2Helper(m - 1, n, obstacleGrid, dp);
    int pathsBeforeDown = uniquePaths2Helper(m, n - 1, obstacleGrid, dp);

    dp[m][n] = pathsBeforeRight + pathsBeforeDown;

    return pathsBeforeRight + pathsBeforeDown;
}

int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
{
    int m = obstacleGrid.size();    // rows
    int n = obstacleGrid[0].size(); // cols

    vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));

    return uniquePaths2Helper(m - 1, n - 1, obstacleGrid, dp);
}

// Min Path Sum
int minPathHelper(int m, int n, vector<vector<int>> &grid, vector<vector<int>> &dp)
{
    // base case
    if (m < 0 || n < 0)
        return INT_MAX;

    if (m == 0 && n == 0)
        return grid[m][n];

    if (dp[m][n] != -1)
        return dp[m][n];

    int sumBeforeRight = minPathHelper(m - 1, n, grid, dp);
    int sumBeforeDown = minPathHelper(m, n - 1, grid, dp);

    dp[m][n] = min(sumBeforeRight, sumBeforeDown) + grid[m][n];

    return dp[m][n];
}

int minPathSum(vector<vector<int>> &grid)
{
    int m = grid.size();    // rows
    int n = grid[0].size(); // cols

    vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));

    return minPathHelper(m - 1, n - 1, grid, dp);
}

int main()
{
    // cout << climbStairs(5);
    // cout << perfectSquares(48);
    cout << uniquePaths(3, 3) << endl;

    vector<vector<int>> obstacles = {{0, 0, 0}, {0, 1, 0}, {0, 0, 0}};
    vector<vector<int>> grid = {{1, 3, 1}, {1, 5, 1}, {4, 2, 1}};

    cout << uniquePathsWithObstacles(obstacles);
    // cout << minPathSum(grid);

    return 0;
}

// DP - Dynamic Programming