bool comparator(pair<int, int> a, pair<int, int> b ) {

    if (a.second == b.second)
        return a.first < b.first;
    
    return a.second < b.second;
}

class Solution {
public:
    int activitySelection(vector<int> start, vector<int> end, int n)
    {
        vector<pair<int, int>> v;

        for (int i = 0; i < start.size(); i++)
            v.push_back({start[i], end[i]});

        sort(v.begin(), v.end(), comparator);

        int take = 1;
        int last = v[0].second;

        for (int i = 1; i < v.size(); i++) {

            if (v[i].first > last) {
                take++;
                last = v[i].second;
            }
        }

        return take;
    }
};
