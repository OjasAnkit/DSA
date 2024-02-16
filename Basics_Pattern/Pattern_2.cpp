#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main()
{
    int n;
    cin >> n;

    int j;

    for (int i = 1; i <= n; i++)
    {
        j = 1;
        // 1st loop
        while (j <= n - i + 1)
        {
            cout << j << " ";
            j++;
        }

        int stars = i - 1;
        // 1st star pattern
        while (stars >= 1)
        {
            cout << "* ";
            stars--;
        }

        int second_j = n - i + 1, stars_2 = i - 1;
        // 2nd star pattern
        while (stars_2 >= 1)
        {
            cout << "* ";
            stars_2--;
        }
        // 2nd loop
        while (second_j >= 1)
        {
            cout << second_j << " ";
            second_j--;
        }

        cout << endl;
    }

    return 0;
}