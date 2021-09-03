#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main() {

    int n, a, b;
    cin >> n;
    vector<pair<int, int>> v;

    // inserting all entry times with 1 and exit times with -1
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        v.push_back({a, 1});
        v.push_back({b, -1});
    }

    // sorting will be on the basis of time (first element of pair)
    sort(v.begin(), v.end());

    int count = 0, ans = 0;

    // if we found +1 in v[i].second, it means one customer entered,so increase the count of customer by 1
    // else if v[i]].second is -1, it means one customer exited, so decrement the count of customer by 1
    // keep track of maximum value achieved by the count
    for (int i = 0; i < v.size(); i++ ) {
        count += v[i].second;
        ans = max(ans, count);
    }

    cout << ans << endl;
}
