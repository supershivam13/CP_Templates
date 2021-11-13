// Idea to Solve :
// If y = sum of the array and x = the value chosen,
// then it will have a y = x graph which is Monotonic, hence Binary Search can be applied.

class Solution {
public:
    // Helper function to find the abs. difference if mid is taken as the answer(value)
    int find(int mid, vector<int>&arr, int target) {
        int sum = 0;
        for (int i = 0; i < arr.size(); i++)
        {
            if (arr[i] >= mid)
                sum += mid;
            else
                sum += arr[i];
        }
        return abs(sum - target);
    }

    // Solution starts here
    int findBestValue(vector<int>& arr, int target) {

        int ans = 0, low = 0, high = 1e8, n = arr.size();

        sort(arr.begin(), arr.end());

        // Binary Search
        while (low <= high)
        {
            int mid = (low + high) >> 1;

            // we calculated dif2 using (mid+1) also, as to decide(make decision) whether side to move in Binary Search.
            int dif1 = find(mid, arr, target);
            int dif2 = find(mid + 1, arr, target);

            if (dif1 <= dif2)
            {
                ans = mid;
                high = mid - 1;
            }
            else
                low = mid + 1;
        }

        return ans;
    }
};
