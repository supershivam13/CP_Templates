class Solution {
public:
    string decodeString(string s) {

        stack<string> chars;
        stack<int> nums;
        string res = "";
        int num = 0;

        // Only 4 options are there - 1) digit   2)alphabet  3) '['   4) ']'
        for (char c : s) {

            if (isdigit(c))
                num = num * 10 + (c - '0');
            else if (isalpha(c))
                res.push_back(c);
            else if (c == '[') {
                chars.push(res);
                nums.push(num);
                res = "";
                num = 0;
            }
            else if (c == ']') {
                string tmp = res;
                for (int i = 0; i < nums.top() - 1; i++)
                    res += tmp;

                // chars.top() store the previous required formatted string except this enclosed bracket part,
                // and 'res' has the required formatted string for this bracket, so adding both
                res = chars.top() + res;
                chars.pop();
                nums.pop();
            }
        }

        return res;
    }
};
