class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();

        vector<int> prefixMatched(n, 0);
        int l = n - 1;
        int r = m - 1;
        
        while(l >= 0){
            if(r >= 0 && word1[l] == word2[r]){
                prefixMatched[l] = (l == n - 1) ? 1 : (1 + prefixMatched[l + 1]);
                r--;
            }else{
                prefixMatched[l] = (l == n - 1) ? 0 : prefixMatched[l + 1];
            }
            l--;
        }

        int i = 0;
        int j = 0;
        bool canChange = true;
        vector<int> seq;
        
        while(i < n && j < m){
            if(word1[i] == word2[j]){
                seq.push_back(i);
                j++;
            }else if(canChange == true && (j == m - 1 || (i + 1 < n ? prefixMatched[i + 1] : 0) >= m - j - 1)){
                seq.push_back(i);
                j++;
                canChange = false;
            }

            i++;
        }

        if(j >= m) return seq;

        return {};
    }
};