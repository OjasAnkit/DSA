#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>

using namespace std;

void reverseKElements(queue<int> q, int k)
{
    // push k elements to stack
    // pop elements from stack and insert to queue
    // pop the remaining elements from queue (that aren't reversed) & push the popped elements back
    stack<int> s;
    int qSize = q.size();
    for (int i = 0; i < k; i++)
    {
        int ele = q.front();
        s.push(ele);
        q.pop();
    }

    while (!s.empty())
    {
        int ele = s.top();
        q.push(ele);
        s.pop();
    }

    for (int i = 0; i < qSize - k; i++)
    {
        int ele = q.front();
        q.pop();
        q.push(ele);
    }
    while (!q.empty())
    {
        int ele = q.front();
        cout << ele << " ";
        q.pop();
    }
}

void printQueue(queue<string> q)
{
    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
}

string returnKthElement(int k)
{
    // we basically have to return the kth largest element that we can generate using only 1 and 2.
    // the numbers we can generate are: 1,2,11,12,21,22,111,112,121,122,211,212,221,222 etc. If k = 5, ans -> 21
    // approach:
    // step 1: push "1" and "2" into queue
    // step 2: then pop them and append each popped element with "1" and "2" and push back
    // step 3: after popping k time, we will get the answer
    queue<string> q;
    q.push("1");
    q.push("2");

    // printQueue(q);

    for (int i = 1; i <= k; i++)
    {
        string s = q.front();
        if (i == k)
            return s;
        q.pop();
        string s1 = s + "1";
        string s2 = s + "2";
        q.push(s1);
        q.push(s2);

        // printQueue(q);
    }
}

string generateKthPalindrome(int k)
{
    // approach:
    // step 1: we generate the normal sequence, then push them to q.
    // step 2: Now we have another queue q2 containing the palindromes (11 and 22)
    // step 3: we will take s1 and s2 that we just pushed to q, and basically push into q2 s1 + reverse(s1) and s2 + reverse(s2).
    // step 4: now simply get the kth element from the front from q2 and return

    queue<string> q;
    queue<string> q2;

    q.push("1");
    q.push("2");
    q2.push("11");
    q2.push("22");

    for (int i = 1; i <= k; i++)
    {
        string s = q.front();
        q.pop();
        string s1 = s + "1";
        string s2 = s + "2";
        q.push(s1);
        q.push(s2);

        string s1rev = s1;
        string s2rev = s2;
        reverse(s1rev.begin(), s1rev.end());
        reverse(s2rev.begin(), s2rev.end());

        q2.push(s1 + s1rev);
        q2.push(s2 + s2rev);
    }

    for (int i = 1; i <= k; i++)
    {
        string s = q2.front();
        if (i == k)
            return s;
        q2.pop();
    }

    printQueue(q2);

    return "hi";

    // 11 22 1111 1221 2112 2222 111111 112211 121121 122221 211112 212212 221122 222222 11111111 11122111 11211211 11222211 12111121 12122121
}

int main()
{
    queue<int> q; // declaring queue

    q.push(3);
    q.push(10);
    q.push(2);
    q.push(12);
    q.push(19);
    q.push(6);
    q.push(8);
    q.push(10);
    q.push(14);

    // reverseKElements(q, 4);
    // cout << returnKthElement(6);
    cout << generateKthPalindrome(9);

    return 0;
}

/*
methods of queue :
1. queue::empty()	Returns whether the queue is empty. It return true if the queue is empty otherwise returns false. O(1)
2. queue::size()	Returns the size of the queue. O(1)
3. queue::swap()	Exchange the contents of two queues but the queues must be of the same data type, although sizes may differ.
4. queue::emplace()	Insert a new element into the queue container, the new element is added to the end of the queue. O(1)
5. queue::front()	Returns a reference to the first element of the queue. O(1)
6. queue::back()	Returns a reference to the last element of the queue. O(1)
7. queue::push(g) 	Adds the element ‘g’ at the end of the queue. O(1)
8. queue::pop() 	Deletes the first element of the queue. O(1)
*/

// Practical examples of queue:
// 1. Task scheduling: If your CPU has only 1 core doing taks, then tasks are scheduled and stored in queue -> they are then processed 1 after the other
