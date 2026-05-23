#include<bits/stdc++.h>
using namespace std;

// O(logn) - fails on negative numbers

int gcd(int a, int b)
{
    if(b==0) return a;
    return (b,a%b);
}

int main()
{
    cout<<gcd(-300,20);
}
