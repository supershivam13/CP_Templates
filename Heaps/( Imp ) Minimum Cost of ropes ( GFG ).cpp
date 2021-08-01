class Solution
{
public:
    long long minCost(long long a[], long long n) {

        long long cost = 0;

        // MIN Heap of long long to avoid integer overflow
        priority_queue<long long, vector<long long>, greater<long long> > minh;

        // inserting all the elements into the min heap
        for (int i = 0; i < n; i++)
            minh.push(a[i]);

        // run this loop until there is only one or zero element is present in the heap
        while (minh.size() >= 2) {

            long f = minh.top();
            minh.pop();

            long s = minh.top();
            minh.pop();

            // cost of connecting two ropes of length 'f' and 'f'  is f+s
            cost += (f + s);

            // now we got a rope of length f+s , so inserting it in heap too
            minh.push(f + s);
        }

        return cost;

    }
};
