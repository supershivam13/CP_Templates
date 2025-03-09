class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {

        sort(intervals.begin(), intervals.end());       // sort the intervals

        vector<vector<int>> ans;        // to store the answer

        for(auto pair: intervals){

            if(ans.size()==0 || ans.back()[1] < pair[0]){  // if empty OR non-overlapping intervals
                ans.push_back(pair);
            }
            else{
                ans.back()[1] = max(ans.back()[1], pair[1]); // overlapping intervals, so taking bigger end of intervals
            }
        }
        return ans;
    }
};
