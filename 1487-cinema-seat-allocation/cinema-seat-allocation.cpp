class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int, vector<int>> mpp;

        int m = reservedSeats.size();
        for(int i=0; i<m; i++){
            int row = reservedSeats[i][0];
            int seat = reservedSeats[i][1];

            if(mpp.find(row) == mpp.end()){
                mpp[row] = vector<int>(3, 0);
            }

            if(seat==1 || seat==10) continue;
            else if(seat==2 || seat==3) mpp[row][0] = -1;
            else if(seat==4 || seat==5){
                mpp[row][0] = -1;
                mpp[row][1] = -1;
            }else if(seat==6 || seat==7){
                mpp[row][1] = -1;
                mpp[row][2] = -1;
            }else if(seat==8 || seat==9) mpp[row][2] = -1;
        }

        int total = 0;
        for(auto it:mpp){
            if(it.second[0]!=-1 && it.second[2]!=-1) total+=2;
            else if(it.second[0] != -1 || it.second[1] != -1 || it.second[2] != -1) total+=1;
        }

        int rem = n-mpp.size();
        total = total + rem*2;

        return total;
    }
};