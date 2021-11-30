class Solution {
public:
    int longestConsecutive(vector<int> &num) {

        if (num.size() == 0)
            return 0;

        int ans = 1;
        unordered_set<int> record;
        for (int x : num)
            record.insert(x);

        for (int x : num) {

            if (record.find(x) == record.end())
                continue;

            record.erase(x);
            int prev = x - 1, next = x + 1;

            while (record.find(prev) != record.end())
                record.erase(prev--);
            while (record.find(next) != record.end())
                record.erase(next++);

            // prev and next are decremented and incremented one more time before exiting the while loop
            // so length of the Longest Consecutive Sequence is (next - prev - 1)
            ans = max(ans, next - prev - 1);
        }

        return ans;
    }
};
