#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

double minimumAverage(vector<int> &nums)
{
    double min = 51.0;
    int len = nums.size();
    sort(nums.begin(), nums.end());

    for (int i = 0; i < len / 2; i++)
    {
        double avg = (nums[i] + nums[len - 1 - i]) / 2.0;
        if (avg < min)
            min = avg;
    }
    return min;
}

int minimumArea(vector<vector<int>> &grid)
{
    int maxX = -1, maxY = -1;
    int minX = 1001, minY = 1001;

    int rows = grid.size();
    int cols = grid[0].size();

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (grid[i][j] == 1)
            {
                if (i > maxX)
                    maxX = i;
                if (j > maxY)
                    maxY = j;
                if (i < minX)
                    minX = i;
                if (j < minY)
                    minY = j;
            }
        }
    }

    int ans = ((maxX - minX + 1) * (maxY - minY + 1));

    if (!ans)
        return 1;
    else
        return ans;
}
int main()
{
    vector<int> nums = {7, 8, 3, 4, 15, 13, 4, 1};
    vector<vector<int>> grid = {{0, 1, 0}, {0, 0, 0}, {0, 0, 0}};
    // cout << minimumAverage(nums);
    cout << minimumArea(grid);
    return 0;
}