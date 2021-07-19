class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int row=matrix.size();
        int col=matrix[0].size();
        vector<vector<int>> zero;
        int k=0;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(matrix[i][j]==0){
                    zero.push_back({i,j});
                }
            }
        }
        for(int i=0;i<zero.size();i++){
            for(int k=0;k<col;k++){
                matrix[zero[i][0]][k]=0;
            }
            for(int k=0;k<row;k++){
                matrix[k][zero[i][1]]=0;
            }
        }
        
    }
};
