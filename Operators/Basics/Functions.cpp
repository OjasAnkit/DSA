#include <iostream>
using std::cin;
using std::cout;
using std::endl;

void calculateAP(int n)
{
    cout << 3 * n + 7 << endl;
}

void calculateSetBits(int a, int b)
{
    int setBitsA = 0, setBitsB = 0;

    for (; a != 0 || b != 0; a = a >> 1, b = b >> 1)
    {
        if (a & 1 == 1)
        {
            setBitsA++;
        }

        if (b & 1 == 1)
        {
            setBitsB++;
        }
    }

    cout << "The number of set bits in 1st Number are:" << setBitsA << endl;
    cout << "The number of set bits in 2nd Number are:" << setBitsB << endl;
}

int calculateFibonacci(int n)
{
    int answer = 0;
    if (n == 1 || n == 2)
        return 1;
    else
        answer = calculateFibonacci(n - 1) + calculateFibonacci(n - 2);
    return answer;
}

int main()
{
    int n, a, b;
    // cin >> n;
    // calculateAP(n);

    // cin >> a >> b;
    // calculateSetBits(a, b);

    cin >> n;
    cout << "Fibonacci Number " << n << " is: " << calculateFibonacci(n);

    return 0;
    // calculateSetBits
}