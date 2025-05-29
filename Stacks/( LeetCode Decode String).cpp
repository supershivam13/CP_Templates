class Solution {
public:
    string decodeString(string s) {
        stack<char> st;
        string str = "";
        string count = "";

        for(int i = 0; i < s.length(); i++){

            if(s[i] == ']'){    // if close bracket, then do decoding till now

                // Collect the string inside the brackets
                while(st.top() != '['){
                    str = st.top() + str;
                    st.pop();
                }

                st.pop();       // Pop the '[' character

                while(st.size()>0 && isdigit(st.top())){    // Collect the numbers
                    count = st.top() + count;
                    st.pop();
                }

                int c = stoi(count);        
                while(c--)
                    for(char it : str)  // Push the decoded substring back onto the stack
                        st.push(it);    // char by char, as stack 'st' is of char, not string

                str = "";
                count = "";
            }
            else
                st.push(s[i]);
        }

        string ans = "";
        while(st.size()>0){
            ans+=st.top();
            st.pop();
        }
        
        reverse(ans.begin(),ans.end());

        return ans;
    }
};
