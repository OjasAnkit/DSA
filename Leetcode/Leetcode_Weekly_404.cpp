#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

int makeRows(int color1, int color2)
{
    int count = 0, row_1 = 1, row_2 = 2;

    while ((color1 - row_1 >= 0) || (color2 - row_2 >= 0))
    {
        // cout << color1 << "_" << color2 << "_" << row_1 << row_2 << endl;
        if (color1 - row_1 >= 0)
        {
            count++;
            color1 -= row_1;
            row_1 += 2;
        }
        else
            return count;

        if (color2 - row_2 >= 0)
        {
            count++;
            color2 -= row_2;
            row_2 += 2;
        }
        else
            return count;
    }
    return count;
}

int returnMax(vector<int> &nums, int k)
{
    int len = nums.size();
    int maxIndexInserted = -1, flag = 0;
    unordered_set<int> index;

    for (int i = 0; i < len - 1; i++)
    {
        if ((nums[i] + nums[i + 1]) % 2 == k)
        {
            if (maxIndexInserted == -1)
                maxIndexInserted = i + 1;

            if (flag)
            {
                if ((nums[i] + nums[maxIndexInserted]) % 2 == k)
                {
                    index.insert(i);
                    index.insert(i + 1);
                    if ((i + 1) > maxIndexInserted)
                        maxIndexInserted = i + 1;
                }
            }

            else
            {
                cout << i << "_" << i + 1 << maxIndexInserted << endl;
                index.insert(i);
                index.insert(i + 1);
                if ((i + 1) > maxIndexInserted)
                    maxIndexInserted = i + 1;
            }
        }
        index.insert(i);
        index.insert(i + 1);
        if ((i + 1) > maxIndexInserted)
            maxIndexInserted = i + 1;
        else
        {
            // checking if removal is needed
            if (((i + 2) < len) && ((nums[i + 1] + nums[i + 2]) % 2 == k))
            {
                if (index.find(i) != index.end())
                    index.erase(index.find(i));
                if (index.find(i + 1) != index.end())
                    index.erase(index.find(i + 1));
            }
            flag = 1;
        }
    }

    // for (auto i : index)
    //     cout << i << "_";
    return index.size();
}

int singleNonDuplicate(vector<int> &nums)
{
    int start = 0;
    int end = nums.size() - 1;
    int mid = start + (end - start) / 2;

    while (start <= end)
    {
        cout << start << "_" << end << "_" << mid << endl;
        if ((nums[mid] != nums[mid + 1]) && (nums[mid] != nums[mid - 1]))
            return nums[mid];

        else if (nums[mid] == nums[mid + 1])
        {
            if ((end - (mid + 2) + 1) % 2 == 0)
                end = mid - 1;
            else
                start = mid + 2;
        }

        else
        {
            if ((end - (mid + 1) + 1) % 2 == 0)
                end = mid - 2;
            else
                start = mid + 1;
        }

        mid = start + (end - start) / 2;
    }

    return -1;
}

int main()
{
    int red = 1;
    int blue = 13;
    // int ans = max(makeRows(red, blue), makeRows(blue, red));
    // cout << ans;
    // vector<int> v = {1, 2, 1, 1, 2, 1, 2};
    // vector<int> v = {1, 5, 9, 4, 2};
    // cout << max(returnMax(v, 0), returnMax(v, 1));
    // cout << returnMax(v, 0);
    int a;
    int m = a * a;
    vector<int> v = {1, 2, 2, 3, 3};
    cout << singleNonDuplicate(v);
    return 0;
}
