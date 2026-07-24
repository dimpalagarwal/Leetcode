class Solution {
public:
    string decodeString(string s) {
        int n = s.size();
        string res = "";

        stack<char> st;
        stack<int> numbers;

        int current_num = 0;
        for(int i=0; i<n; i++){
            if(isdigit(s[i])){
                current_num = current_num*10 + (s[i]-'0');
            }else if(s[i]=='['){
                numbers.push(current_num);
                current_num = 0;
                st.push('[');
            }else if(s[i]==']'){
                string str = "";
                while(st.top() != '['){
                    char ch = st.top();
                    str = ch + str;
                    st.pop();
                }
                st.pop();
                int num = numbers.top();
                numbers.pop();

                string original = str;
                while(num>1){
                    str = str + original;
                    num--;
                }

                for(char ch : str) {
                    st.push(ch);
                }
            }else{
                st.push(s[i]);
            }
        }

        while(!st.empty()) {
            res = st.top() + res;
            st.pop();
        }

        return res;
    }
};