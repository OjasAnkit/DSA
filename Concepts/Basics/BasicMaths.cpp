#include <iostream>
#include <vector>
using namespace std;

bool checkForPrime(int n)
{
    int factors = 0;

    for (int i = 1; i * i <= (n); i++)
    {
        if (n % i == 0)
        {
            if ((n / i) == i)
                factors++;
            else
                factors += 2;
        }
    }
    cout << "No. of factors : " << factors;

    if (factors == 2)
        return 1;
    else
        return 0;
}

int sieve(int n)
{
    int prime = 0;
    vector<bool> primes(n + 1, true);
    // 0 -> Non prime & 1 -> Prime

    primes[0] = primes[1] = false;

    for (int i = 2; i < n + 1; i++)
    {
        // cout << i << "_";
        if (primes[i])
        {
            prime++;
            for (int j = 2 * i; j < n + 1; j += i)
            {
                primes[j] = false;
            }
        }
    }
    return prime;
}

int GCD(int a, int b)
{
    if (a == 0)
        return b;
    if (b == 0)
        return a;

    // this is the iterative method of finding GCD. Basically we keep subtracting the smaller number from the bigger number
    // until the numbers become equal. Once the numbers are equal, the GCD becomes either one of those numbers.
    while (a != b)
    {
        if (a > b)
            a -= b;
        else
            b -= a;
    }
    return a;
}

int main()
{
    int n = 64;
    int ans = checkForPrime(n);
    // int a = 26, b = 156;
    // cout << GCD(a, b);
    return 0;
}
