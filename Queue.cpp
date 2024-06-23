#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main()
{
    queue<int> q; // declaring queue

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
// 1. Task scheduling: If your CPU has only core doing taks, then tasks are scheduled and stored in queue -> they are then processed 1 after the other
