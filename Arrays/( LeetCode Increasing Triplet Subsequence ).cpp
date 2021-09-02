class Solution {
public:
    bool increasingTriplet(vector<int>& a) {

        if (a.size() < 3)
            return false;

        int first = INT_MAX, second = INT_MAX;

        for (int i = 0; i < a.size(); i++) {

            // it stores the smallest value occured in the array
            if (a[i] <= first)
                first = a[i];
            // if reaches here, then it means a[i]>first, can be potential candidate for second and third
            else if (a[i] <= second)
                second = a[i];
            // if reaches here, then it means a[i]>second and a[i]>first, so our conditions are met, return true
            else
                return true;
        }

        return false;

    }
};
