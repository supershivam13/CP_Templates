
/* struct Item{
    int value;
    int weight;
};   */

bool cmp(Item A,Item B)   // sorting the array in descending order of value density
{
    double r1=(double)A.value/(double)A.weight;
    double r2=(double)B.value/(double)B.weight;
    return r1>r2;
}

class Solution
{
    public:
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        sort(arr,arr+n,cmp);   //  sorting the array using comparator function
        double ans=0;
        for(int i=0;i<n;i++)
        {
            if(W>=arr[i].weight)   // when whole item can be taken
            {
                W-=arr[i].weight;
                ans+=arr[i].value;
            }
            else                   // when the fraction of object is taken
            {
                double fraction=(W*1.0)/arr[i].weight;
                ans+=arr[i].value*fraction;
                break;
            }   
        }
        return ans;
    }
};
