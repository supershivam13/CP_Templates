class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        map<string, vector<string>> m;      // map of { key :[anagrams] }, where key is the sorted string
        vector<vector<string>> ans;  

        for(int i=0;i<strs.size();i++){

            string key = strs[i];           // taking the string one-by-one
            sort(key.begin(), key.end());   // sorting to make the anagrams'key as sorted string(key)

            // if present, it will add the anagrams to the vector
            // if not present, it will create a pair with key and push the anagrams to the vector
            m[key].push_back(strs[i]);                   
        }

        for(auto p : m)   // adding all the vectos to the final ans vector
            ans.push_back(p.second);

    return ans;
    }
};
