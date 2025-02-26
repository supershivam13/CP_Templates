bool comparator(pair<int, int> a, pair<int, int> b ) {    // sorting the vector in ascending order of end time(JO PEHLE KHATAM HO RHA H USKO LE LO),
                                                          // if end time are equal, then in ascending order of the start time
    if (a.second == b.second)
        return a.first < b.first;
    
    return a.second < b.second;
}

class Solution {
public:
    int activitySelection(vector<int> start, vector<int> end, int n)
    {
        vector<pair<int, int>> v;

        for (int i = 0; i < start.size(); i++)  // storing the values as pair [start,end] in vector v
            v.push_back({start[i], end[i]});

        sort(v.begin(), v.end(), comparator);   // sorting the vector v using comparator function

        int take = 1;                // we took the first job
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
