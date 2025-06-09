bool cmp(vector<int>& a, vector<int>& b){ // sorting the vector in ascending order of end time
                                          //(JO PEHLE KHATAM HO RHA H USKO LE LO),
    if(a[1]==b[1])          // if end times are equal, then in ascending order of start time
        return a[0]<b[0];
    
    return a[1] < b[1];
}

class Solution {
  public:
    int activitySelection(vector<int>& start, vector<int>& end) {
        
        int n = start.size();
        vector<vector<int>> pairs;
        for(int i=0; i<n; i++)          // storing the values as pair [start,end] in vector 'pairs'
            pairs.push_back({start[i], end[i]});
        
        sort(pairs.begin(), pairs.end(), cmp); // sorting the 'pairs' using comparator function
        
        int take = 1;               // we took the first job
        int last = pairs[0][1];
        
        for(int i=1; i<n; i++){
            if(last < pairs[i][0]){
                last = pairs[i][1];
                take++;
            }
        }
        
        return take;
    }
};
