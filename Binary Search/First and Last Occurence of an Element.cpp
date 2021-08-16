class Solution {
public:
    vector<int> searchRange(vector<int>& a, int target) {

        // variables to store the first and last occurence
        int first = -1;
        int last = -1;

        int n = a.size();
        int start = 0;
        int end = n - 1;

        // Binary Search for first occcurence of target element
        while (start <= end) {

            int mid = start + ((end - start) / 2);

            // Only difference is on founding the target element, we store the result
            // and keep our search continue on the left halve as we are looking for first occurence
            if (target == a[mid]) {
                first = mid;
                end = mid - 1;
            }
            else if (target > a[mid])
                start = mid + 1;
            else
                end = mid - 1;
        }

        // re-initialising the values of start and end
        start = 0;
        end = n - 1;

        // Binary Search for last occcurence of target element
        while (start <= end) {

            int mid = start + ((end - start) / 2);

            // Only difference is on founding the target element, we store the result
            // and keep our search continue on the right halve as we are looking for last occurence
            if (target == a[mid]) {
                last = mid;
                start = mid + 1;
            }
            else if (target > a[mid])
                start = mid + 1;
            else
                end = mid - 1;
        }

        vector<int> ans;
        ans.push_back(first);
        ans.push_back(last);

        return ans;


    }
};