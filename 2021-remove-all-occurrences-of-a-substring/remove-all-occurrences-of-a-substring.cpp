class Solution {
public:
    bool check(stack<char> st, string part){
        int m = part.size();

        for(int i=m-1; i>=0; i--){
            if(part[i]!=st.top()) return false;
            st.pop();
        }

        return true;
    }

    string removeOccurrences(string s, string part) {
        stack<char> st;

        int n = s.size();
        int m = part.size();

        for(int i=0; i<n; i++){
            st.push(s[i]);

            if(st.size() >= m && check(st, part)){
                for(int j=0; j<m; j++){
                    st.pop();
                }
            }
        }

        string res = "";
        while(!st.empty()){
            res.push_back(st.top());
            st.pop();
        }

        reverse(res.begin(), res.end());

        return res;
    }
};