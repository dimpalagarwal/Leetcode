class TreeAncestor {
public:
//classic ques of binart lifting
    vector<int> par;
    vector<vector<int>> ancestorTable;
    int row;
    int col;

    TreeAncestor(int n, vector<int>& parent) {
        par = parent;
        row = n;
        col = log2(n) + 1;
        ancestorTable.assign(row, vector<int>(col, -1));

        for(int i=0; i<row; i++){
            ancestorTable[i][0] = parent[i];
        }

        for(int j=1; j<col; j++){
            for(int i=0; i<row; i++){
                int temp = ancestorTable[i][j-1];
                if(temp != -1){
                    ancestorTable[i][j] = ancestorTable[temp][j-1];
                }else{
                    ancestorTable[i][j] = -1; 
                }
            }
        }
    }
    
    int getKthAncestor(int node, int k) {
        if(k==0) return node;
        if (k > row) return -1;

        for(int j=0; j<col; j++){
            if(k&(1<<j)){
                node = ancestorTable[node][j];

                if(node==-1) return -1;
            }
        }

        return node;
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */