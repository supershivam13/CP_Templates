class Solution {
public:
    int singleNumber(vector<int>& nums) {
        
        //to store the frequency of each bit
        vector<int> freq(32, 0);

        for (auto e : nums)
        {   
            // HERE, it is given that integers can be negative as well, so we'll have
            // to use f(0,32) to also include the sign determing bit
            
            // However if it was given that all integers >=0 then
            // either from f(0,31) or f(0,32) it won't make any difference
            // because all the integers are given positive so the sign determing bit
            // will be same for every integer
            
            for (int j = 0; j < 32; j++)
            {
                if (e & (1 << j))
                    freq[j]++;
            }
        }

        int ans = 0;
        
        // Bits which are set in the answer element will have a frequency like 3n+1
        // so we will use this fact to calculate the answer
        for (int i = 0; i < 32; i++)
        {
            if (freq[i] % 3 == 1)
                ans += (1 << i);
        }
        return ans;
    }
};
