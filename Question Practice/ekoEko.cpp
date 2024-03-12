#include <iostream>
#include <vector>
using namespace std;

bool isPossible(int mid, int reqdTrees, vector<int> heights)
{
    int woodObtained = 0;

    for (int i = 0; i < heights.size(); i++)
    {
        int wood = heights[i] - mid;
        if (wood > 0)
        {
            woodObtained += wood;
            if (woodObtained >= reqdTrees)
                return 1;
        }
    }
    return 0;
}

int main()
{
    int n, m, input, max = -1;
    cin >> n >> m;
    vector<int> heights;
    for (int i = 0; i < n; i++)
    {
        cin >> input;
        if (input > max)
            max = input;
        heights.push_back(input);
    }

    int low = 1, high = max - 1, ans;
    int mid = low + (high - low) / 2;

    while (low <= high)
    {
        if (isPossible(mid, m, heights))
            low = mid + 1;

        else
            high = mid - 1;

        mid = low + (high - low) / 2;
    }

    cout << high;

    return 0;
}