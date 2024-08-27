#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

// given an array of int, print the kth smallest elements
void kthSmallest(vector<int> v, int k)
{
    priority_queue<int> pq;

    // adding the first k elements to max pq
    for (int i = 0; i < k; i++)
    {
        pq.push(v[i]);
    }

    /* iterate over next n-k elements, and compare with top of max pq,
    if bigger than max -> skip, else remove max and push element */
    for (int i = k; i < v.size(); i++)
    {
        if (v[i] < pq.top())
        {
            pq.pop();
            pq.push(v[i]);
        }
    }

    // pq will contain the kth smallest elements
    while (!pq.empty())
    {
        cout << k << " smallest element: " << pq.top() << endl;
        k--;
        pq.pop();
    }

    return;
}

int main()
{
    priority_queue<int> pq;                                // default definition will create a max pq
    priority_queue<int, vector<int>, greater<int>> min_pq; // syntax to create min pq

    vector<int> v = {4, 2, 7, 11, 5, 8, 5, 1, 12, 10, 9};
    kthSmallest(v, 4);

    return 0;
}

/* Syntax of min pq:
priority_queue <int, vector<int>, greater<int>> gq;
where ->
- ‘int’ is the type of elements you want to store in the priority queue. In this case, it’s an integer. You can replace int with any other data type you need.
- ‘vector<int>’ is the type of internal container used to store these elements. std::priority_queue is not a container in itself but a container adopter. It wraps other containers. In this example, we’re using a vector, but you could choose a different container that supports front(), push_back(), and pop_back() methods.
- ‘greater<int>‘ is a custom comparison function. This determines how the elements are ordered within the priority queue. In this specific example, greater<int> sets up a min-heap. It means that the smallest element will be at the top of the queue.

Function for priority_queue
1. priority_queue::empty()	Returns whether the queue is empty.
2. priority_queue::size() 	Returns the size of the queue.
3. priority_queue::top()	Returns a reference to the topmost element of the queue.
4. priority_queue::push(g) 	Adds the element ‘g’ at the end of the queue.
5. priority_queue::pop()	Deletes the first element of the queue.
6. priority_queue::swap()	Used to swap the contents of two queues provided the queues must be of the same type, although sizes may differ.
7. priority_queue::emplace()	Used to insert a new element into the priority queue container.
8. priority_queue value_type : Represents the type of object stored as an element in a priority_queue. It acts as a synonym for the template parameter.

*/