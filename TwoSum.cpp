#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <vector>
using namespace std;

vector<int> twoSum(vector<int> &nums, int target)
{
    unordered_map<int, vector<int>> freqSet;
    vector<int> ans;
    for (int i = 0; i < nums.size(); i++)
    {
        if (freqSet[nums[i]].empty())
        {
            vector<int> index;
            index.push_back(i);
            freqSet[nums[i]] = index;
        }
        else
        {
            vector<int> index = freqSet[nums[i]];
            index.push_back(i);
            freqSet[nums[i]] = index;
        }
    }

    // for (auto i : freqSet)
    //     cout << i.first << "_" << i.second.size() << endl;

    for (int i = 0; i < nums.size(); i++)
    {
        int elementToCheck = target - nums[i];
        if (!freqSet[elementToCheck].empty())
        {
            if (elementToCheck == nums[i])
            {
                if (freqSet[elementToCheck].size() != 1)
                {
                    return freqSet[elementToCheck];
                }
            }
            else
            {
                ans.push_back(freqSet[nums[i]][0]);
                ans.push_back(freqSet[elementToCheck][0]);
                return ans;
            }
        }
    }
}

int main()
{
    vector<int> query;
    int len, target;
    cin >> len;
    cin >> target;
    for (int i = 0; i < len; i++)
    {
        int element;
        cin >> element;
        query.push_back(element);
    }

    vector<int> ans = twoSum(query, target);

    for (int i : ans)
        cout << "ANS:" << i << "_";

    return 0;
}
