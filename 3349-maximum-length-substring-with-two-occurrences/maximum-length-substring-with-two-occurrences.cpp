class Solution {
public:
    int maximumLengthSubstring(string s) {
        int n = s.size();

        int l = 0;
        int r = 0;

        int maxLen = INT_MIN;

        vector<int> freq(26, 0);
        while(r<n){
            freq[s[r]-'a']++;
            bool valid = true;
            for(int i=0; i<26; i++){
                if(freq[i]>2){
                    valid = false;
                    break;
                }
            }

            while(valid == false){
                maxLen = max(maxLen, r-l);
                freq[s[l]-'a']--;
                l++;
                valid = true;
                for(int i=0; i<26; i++){
                    if(freq[i]>2){
                        valid = false;
                        break;
                    }
                }
            }

            r++;
        }

        maxLen = max(maxLen, r-l);

        return maxLen;
    }
};