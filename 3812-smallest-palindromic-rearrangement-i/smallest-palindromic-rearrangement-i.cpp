class Solution {
public:
    string smallestPalindrome(string s) {
        int n = s.size();

        vector<int> freq(26,0);
        for(int i=0; i<n; i++){
            freq[s[i]-'a']++;
        }

        string ans = "";
        char havingOddCount = '\0';
        for(int i=0; i<26; i++){    
            int count = freq[i]/2;
            ans.append(count, i+'a');

            if(freq[i]%2!=0) havingOddCount = i+'a';
        }

        string res = ans;
        reverse(ans.begin(), ans.end());

        if(havingOddCount != '\0'){
            res.push_back(havingOddCount);
        }

        res = res + ans;

        return res;
    }
};