#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> nextPermutation(vector<int> &nums)
{
    int len = nums.size();
    bool changed = false;

    for (int i = len - 1; i > 0; i--)
    {
        if (!(nums[i - 1] >= nums[i]) && !changed)
        {
            int key = nums[i - 1];

            // finding the next biggest element
            int next_biggest_index = i;
            for (int j = i; j < len; j++)
            {
                if ((nums[j] > key) && (nums[j] < nums[next_biggest_index]))
                    next_biggest_index = j;
            }

            cout<<nums[i];

            // swapping key with next biggest
            swap(nums[i - 1], nums[next_biggest_index]);

            // sorting nums[i] till nums [len - 1] in ascending order after swapping
            sort(nums.begin() + i, nums.end());
            changed = true;
        }
    }

    if (!changed)
        reverse(nums.begin(), nums.end());

    return nums;
}

int main()
{
    vector<int> v = {1, 3, 2};
    vector<int> ans = nextPermutation(v);

    for (int i : ans)
        cout << i << "_";
    return 1;
}