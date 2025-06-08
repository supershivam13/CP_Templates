bool cmp(pair<int, int>& a, pair<int, int>& b) {
    
    double r1 = (double)a.first / a.second;
    double r2 = (double)b.first / b.second;
    return r1 > r2;                         // Sort in descending order
}

class Solution {
public:
    double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
        int n = val.size();
        vector<pair<int, int>> items;

        for (int i = 0; i < n; i++)
            items.push_back({val[i], wt[i]});   // Build value-weight pairs

        sort(items.begin(), items.end(), cmp);  // Sort items by value-to-weight ratio

        double totalValue = 0.0;

        for (int i = 0; i < n && capacity > 0; i++) {
            int v = items[i].first;
            int w = items[i].second;

            if (capacity >= w) {
                totalValue += v;
                capacity -= w;
            } 
            else {
                totalValue += ((double)v / w) * capacity;
                break;
            }
        }

        return totalValue;
    }
};
