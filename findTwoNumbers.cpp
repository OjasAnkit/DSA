// in a series [1,2..n] one number is missing, and one number is repeated twice -> find both in O(n) TC and O(1) space
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> findTwoNumbers(vector<int> arr, int n)
{
    vector<int> ans{2, 0};
    long long sum_correct = (n);
    sum_correct *= (n + 1);
    sum_correct /= 2;
    long long sum_correct_sqr = (n);
    sum_correct_sqr *= (n + 1);
    sum_correct_sqr *= (2 * n + 1);
    sum_correct_sqr /= 6;
    long long actual_sum = 0;
    long long actual_sum_sqr = 0;
    for (int i = 0; i < n; i++)
    {
        actual_sum += arr[i];
        actual_sum_sqr += (arr[i] * arr[i]);
    }
    cout << "actual sum: " << actual_sum << endl;
    cout << "actual sum sqr: " << actual_sum_sqr << endl;
    cout << "sum correct: " << sum_correct << endl;
    cout << "sum correct sqr: " << sum_correct_sqr << endl;
    // repeating - missing will be the dif bw sum_correct & actual_sum
    int diff_sum = actual_sum - sum_correct;

    // repeating^2 - missing^2 will be the dif bw sum_correct & actual_sum
    int diff_sum_sqr = actual_sum_sqr - sum_correct_sqr;
    // repeating^2-missing^2 = (repeating-missing)*(repeating+missing)
    int sum_of_num = diff_sum_sqr / diff_sum;
    // now we have (repeating-missing) & (repeating+missing)
    int repeating = (sum_of_num + diff_sum) / 2;
    int missing = sum_of_num - repeating;
    ans[0] = repeating;
    ans[1] = missing;
    return ans;
}

vector<int> findTwoNumbersBetter(vector<int> arr, int n)
{
}

int main()
{
    vector<int> v;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        v.push_back(temp);
    }

    vector<int> ans = findTwoNumbers(v, n);

    for (int i : ans)
        cout << i << " ";

    return 0;
}
