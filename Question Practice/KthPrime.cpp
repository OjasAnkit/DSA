#include <iostream>
#include <vector>
using namespace std;

vector<bool> sieve(100000000, 1);
vector<int> primeNumbers;

void createSieve()
{
    int n = sieve.size();
    sieve[0] = sieve[1] = false;
    primeNumbers.push_back(0);
    for (int i = 2; i * i < n; i++)
    {
        if (sieve[i] == true)
        {
            for (int j = i * i; j < n; j += i)
                sieve[j] = false;
        }
    }

    for (int i = 2; i < sieve.size(); i++)
    {
        if (sieve[i] == true)
            primeNumbers.push_back(i);
    }
}

int main()
{
    int t, n;
    createSieve();
    cin >> t;
    while (t)
    {
        cin >> n;
        cout << primeNumbers[n] << endl;
        t--;
    }
    return 0;
}