#include <bits/stdc++.h>
using namespace std;


int main()
{
    int n, x, y, ans = 0;
    cin >> n;

    // to store the frequencies of x and y co-ordinates
    map<int, int> freq_x;
    map<int, int> freq_y;

    vector<pair<int, int>> v;

    // building the frequency map
    while (n--) {
        cin >> x >> y;
        v.push_back({x, y});

        freq_x[x]++;
        freq_y[y]++;
    }


    for (auto p : v) {
        x = p.first;
        y = p.second;

        // for every coordinate, Triangles possible are (freq[x]-1)*(freq[y]-1)
        // subtracting one as to exclude the vertex that is being made pivot point
        ans += ((freq_x[x] - 1) * (freq_y[y] - 1));
    }

    cout << ans % 10000 << endl;

}
