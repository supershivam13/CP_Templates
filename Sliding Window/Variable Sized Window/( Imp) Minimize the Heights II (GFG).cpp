// Variable Sized Sliding Window

class Solution {
public:
    int getMinDiff(int a[], int n, int k) {

        // vector to store all possible values after modification along with
        // their index as {value,index} pair
        vector<pair<int, int>> v;

        // to keep the track of the indexes present in the window
        vector<int> visited(n, 0);

        for (int i = 0; i < n; i++) {
            v.push_back({a[i] + k, i});

            // After modifying, height should be a non-negative integer
            if (a[i] - k >= 0)
                v.push_back({a[i] - k, i});
        }

        sort(v.begin(), v.end());
        int ele = 0, left = 0, right = 0;

        // Pre-Processing of first window with all indexes present atleast once (i.e ele = n)
        while (ele < n and right < v.size()) {

            if (visited[v[right].second] == 0)
                ele++;

            visited[v[right].second]++;
            right++;
        }

        // Calculating ans from first window with all indexes present atleast once (i.e ele = n)
        // since right is incremented before the loop breaks, so taking calculating ans
        // using (right-1)th element
        int ans = v[right - 1].first - v[left].first;


        // SLIDING WINDOW TECHNIQUE
        while (right < v.size()) {

            // Shrinking the window by 1
            if (visited[v[left].second] == 1)
                ele--;
            visited[v[left].second]--;
            left++;

            // Expanding the window till we get a potential window
            while (ele < n and right < v.size()) {

                if (visited[v[right].second] == 0)
                    ele++;

                visited[v[right].second]++;
                right++;
            }

            if (ele == n)
                ans = min(ans, v[right - 1].first - v[left].first);
        }

        return ans;
    }
};
