class Solution {
public:
    int minimumPushes(string word) {
        int n = word.size();

        vector<int> freq(26,0);
        for(int i=0; i<n; i++){
            freq[word[i]-'a']++;
        }

        sort(freq.begin(), freq.end(), [](int a, int b){
            return a > b;
        });

        int sum = 0;
        for(int i=0; i<26; i++){
            int div = i/8;
            sum = sum + (div+1)*freq[i];
        }

        return sum;
    }
};