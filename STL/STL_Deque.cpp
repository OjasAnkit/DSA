#include <iostream>
#include <deque>

using namespace std;

int main()
{
    deque<int> d;

    cout << "Empty or not: " << d.empty() << endl;
    d.push_back(2);
    d.push_front(3);
    d.push_back(4);
    cout << "Size of Deque is: " << d.size() << endl;
    d.push_back(7);
    d.pop_back();
    d.push_front(4);
    cout << "Empty or not: " << d.empty() << endl;

    d.push_back(5);
    d.pop_front();
    // 3 2 4 5

    // d.erase(d.begin(), d.begin() + 2);

    cout << d.back();

    return 0;
} // namespace std;
