// Here we need to return the indices of the vector if we found out the sum,
// For this purpose we need to create a map the by iterating all over the vector,
// we will try to find out the target like
// target = nums[i] + some previous value (stored in the map with their indices)
// where, some previous value = target - nums[i];
// Use find function (logN time) in the map to find this key
// if(mp.find(target-nums[i]) != mp.end())
// than just simply return this indices which are stored in map


// Time Complexity - O(NlogN)

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        unordered_map<int, int> mp;

        for (int i = 0; i < nums.size(); i++) {

            if (mp.find(target - nums[i]) != mp.end())
                return {mp[target - nums[i]], i};

            mp[nums[i]] = i;
        }

        return {};
    }
};