class Solution {
public:
    int mySqrt(int x) {

        //long long due to some of test cases overflows integer limit.
        long long s = 0, e = x, ans, mid;

        while (s <= e) {

            mid = s + ((e - s) / 2);

            if (mid * mid == x)
                return mid;
            else if (mid * mid < x) {
                s = mid + 1;
                //an extra pointer 'ans' is maintained to keep track of only lowest 'mid' value.
                ans = mid;
            }
            else
                e = mid - 1;
        }

        return ans;
    }
};
