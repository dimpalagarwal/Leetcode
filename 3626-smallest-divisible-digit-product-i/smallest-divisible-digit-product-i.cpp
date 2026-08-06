class Solution {
public:
    int prodOfDigits(int n){
        int prod = 1;
        while(n>0){
            int rem = n%10;
            prod*=rem;
            n = n/10;
        }

        return prod;
    }

    int smallestNumber(int n, int t) {
        int i = n;
        while(1){
            int prod = prodOfDigits(i);
            if(prod % t == 0) return i;
            i++;
        }

        return -1;
    }
};