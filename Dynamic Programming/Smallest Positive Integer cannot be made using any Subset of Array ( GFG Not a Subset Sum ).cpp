class Solution{   
public:
    long long findSmallest(long long arr[], int n) {
        
    long long res = 1; // Initialize result
    sort(arr, arr+n);

    // Traverse the array and increment 'res' if arr[i] is
    // smaller than or equal to 'res'.
    for (int i = 0; i < n && arr[i] <= res; i++)
        res = res + arr[i];

    return res;
    }
};
