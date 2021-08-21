#include <bits/stdc++.h>
using namespace std;

void towerOfHanoi(int n, char from_rod, char to_rod, char aux_rod) {

    // Base Condition
    if (n == 1) {
        cout << "Move disk 1 from rod " << from_rod << " to rod " << to_rod << endl;
        return;
    }

    // moving n - 1 rods from Source to Helper
    towerOfHanoi(n - 1, from_rod, aux_rod, to_rod);

    // Moving n-th disk from Source to Destination
    cout << "Move disk " << n << " from rod " << from_rod << " to rod " << to_rod << endl;

    // moving n - 1 rods from Helper to Destination
    towerOfHanoi(n - 1, aux_rod, to_rod, from_rod);
}


int main()
{
    int n = 4; // Number of disks

    // A = Source, C = Destination, B = Helper
    towerOfHanoi(n, 'A', 'C', 'B');

}
