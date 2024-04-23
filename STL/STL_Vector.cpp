#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
{

    vector<int> nums_temp(nums1);

    int pos_1 = 0, pos_2 = 0, pos_temp = 0;

    while (pos_temp < m && pos_2 < n)
    {
        if (nums_temp[pos_temp] <= nums2[pos_2])
        {
            nums1[pos_1] = nums_temp[pos_temp];
            pos_temp++;
            pos_1++;
        }

        else
        {
            nums1[pos_1] = nums2[pos_2];
            pos_2++;
            pos_1++;
        }
    }

    for (int i : nums1)
        cout << i << " ";
}
void rotate(vector<int> &nums, int k)
{
    vector<int> ans(nums);
    for (int i = 0; i < k; i++)
    {
        nums[i] = ans[ans.size() - k + i];
    }

    for (int i = k; i < ans.size(); i++)
    {
        nums[i] = ans[i - k];
    }
}

void findArraySum(vector<int> &a, int n, vector<int> &b, int m)
{
    int a_num = 0, b_num = 0;
    int multiplier = 1;

    while (n > 0)
    {
        int lastDigit = a[n - 1];
        a_num += (lastDigit * multiplier);

        multiplier *= 10;
        n--;
    }

    multiplier = 1;

    while (m > 0)
    {
        int lastDigit = b[m - 1];
        b_num += (lastDigit * multiplier);

        multiplier *= 10;
        m--;
    }
    int ans = a_num + b_num;
    vector<int> ansVector;

    while (ans != 0)
    {
        int lastDigit = ans % 10;
        ansVector.push_back(lastDigit);

        ans /= 10;
    }

    for (int i : ansVector)
        cout << i << " ";
}

vector<int> reverse(vector<int> a, int begin, int end)
{
    while (begin < end)
    {
        swap(a[begin], a[end]);
        begin++;
        end--;
    }

    return a;
}

vector<int> rotateInPlace(vector<int> a, int k)
{
    k %= a.size();
    vector<int> ans;
    ans = reverse(a, 0, a.size() - 1);
    ans = reverse(ans, 0, k - 1);
    ans = reverse(ans, k, a.size() - 1);

    return ans;
}

int main()
{
    // vector<int> v;

    // v.push_back(74);
    // v.push_back(23);

    // // cout << "Size >" << v.size() << endl;

    // v.push_back(232);
    // v.push_back(232);
    // v.push_back(232);
    // v.push_back(232);
    // v.push_back(232);
    // v.push_back(232);

    // // cout << "Size > " << v.size(); // size returns the number of elements the vector is currently holding

    // for (int i : v)
    //     // cout << i << " ";

    //     // cout << "Capacity > " << v.capacity(); // capacity returns the capacity or the memory currently allocated to the vector

    //     v.clear(); // clear makes the vector empty or size = 0, but the capacity remains the same

    // // cout << "Size > " << v.size();
    // // cout << "Capacity > " << v.capacity();

    // // for (int i : v)
    // //     cout << i << " ";

    int m = 5, n = 6;
    vector<int> nums = {-1};
    vector<int> nums1 = {1, 3, 5, 6, 7, 0, 0, 0, 0, 0, 0};
    vector<int> nums2 = {1, 2, 3, 7, 8, 9};

    vector<int> a = {1, 4, 5};
    vector<int> b = {2, 6};

    // findArraySum(a, 3, b, 2);

    // rotate(nums, 2);

    // for (int i : nums)
    //     cout << i << " ";

    // char ch = 'B';
    // ch = ch - 'A' + 'a';
    // cout << " " << ch;
    vector<int> arr = {1, 2, 3, 7, 8, 9};
    int k = 9;
    for (int i : arr)
        cout << i << " ";
    cout << "\nAfter rotating " << k << " times:" << endl;
    vector<int> rotatedArr = rotateInPlace(arr, k);
    for (int i : rotatedArr)
        cout << i << " ";
}