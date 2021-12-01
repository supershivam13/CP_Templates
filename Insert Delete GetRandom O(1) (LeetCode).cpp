class RandomizedSet {
public:
    vector<int> nums;
    unordered_map<int, int> m;

    RandomizedSet() { }

    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {

        if (m.find(val) != m.end())
            return false;

        nums.push_back(val);
        m[val] = nums.size() - 1;
        return true;
    }

    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if (m.find(val) == m.end())
            return false;

        int last = nums.back();
        // update in map
        m[last] = m[val];
        // update in nums vector
        nums[m[val]] = last;
        
        nums.pop_back();
        m.erase(val);
        return true;
    }

    int getRandom() {
        return nums[rand() % nums.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
