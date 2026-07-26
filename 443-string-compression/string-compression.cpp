class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();

        // string s;
        int count = 1;
        int idx = 0;
        for(int i=1; i<n; i++){
            if(chars[i]==chars[i-1]) count++;
            else{
                char ch = chars[i-1];
                // s.push_back(ch);
                string str = to_string(count);
                // if(count!=1) s = s + str;
                chars[idx] = ch;
                idx++;
                if(count!=1){
                    for(int j=0; j<str.size(); j++){
                        chars[idx] = str[j];
                        idx++;
                    }
                }
                count = 1;
            }
        }

        char ch = chars[n-1];
        // s.push_back(ch);
        string str = to_string(count);
        // if(count!=1) s = s + str;
        chars[idx] = ch;
        idx++;
        if(count!=1){
            for(int j=0; j<str.size(); j++){
                chars[idx] = str[j];
                idx++;
            }
        }

        return idx;
    }
};