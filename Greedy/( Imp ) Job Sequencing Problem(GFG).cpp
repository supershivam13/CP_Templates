// Time Complexity - O( NlogN + Nlog(100) ) = O(NlogN)


// ***************************************************************************


/*
struct Job
{
    int id;  // Job Id
    int dead; // Deadline of job
    int profit; // Profit if job is over before or on deadline
};
*/

// Comparator function to sort in decreasing order on the basis of Profit
bool comp(Job a, Job b) {
    return a.profit > b.profit;
}

class Solution
{
public:
    vector<int> JobScheduling(Job arr[], int n) {

        // sorting in decreasing order on the basis of Profit
        sort(arr, arr + n, comp);

        // Variables to store the maximum profit and tasks taken
        int prof = 0;
        int take = 0;

        // Set to keep a track of all available days to take job
        // Initially all days are available (1 <= Deadline <= 100, given in Ques)
        set<int> s;
        for (int i = 1; i <= 100; i++)
            s.insert(i);

        for (int i = 0; i < n; i++) {
            int d = arr[i].dead;

            auto it = s.upper_bound(d);

            // when no day is available within the deadline, then 'it' will be pointing to the s.begin(),
            // then we can't take this task
            if (it == s.begin())
                continue;
            // else we decrement 'it' to get some value less or equal to 'd', and delete it from the set
            else {
                it--;
                s.erase(it);
                prof += arr[i].profit;
                take++;
            }
        }

        return {take, prof};
    }
};
