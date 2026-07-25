// The rand7() API is already defined for you.
// int rand7();
// @return a random integer in the range 1 to 7

class Solution {
public:
    int rand10() {
        while(true){
            int row = rand7();
            int col = rand7();

            int num = (row-1)*7 + col;
            if(num <= 40) return (num-1)%10 + 1;
        }
    }
};