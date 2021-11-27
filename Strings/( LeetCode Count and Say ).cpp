class Solution {
private:
    string countAndSay(string& str) {

        string result;
        int counter = 1;
        char curDigit = str[0];

        for (int i = 1; i < str.size(); i++) {

            if (str[i] == curDigit)
                counter++;
            else {
                result += to_string(counter);
                result.push_back(curDigit);
                curDigit = str[i];
                counter = 1;
            }
        }

        result += to_string(counter);
        result.push_back(curDigit);
        return result;
    }

// Solution starts here
public:
    string countAndSay(int n) {

        // Base case when n = 1
        string result = "1";

        for (int i = 1; i < n; i++)
            result = countAndSay(result);

        return result;
    }
};
