class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int m=matrix.size();
        int n=matrix[0].size();
    
        int top=0,down=m-1,left=0,right=n-1;
        int k=0;
        while(k<m*n){
            for(int i=left;i<=right;i++){
                ans.push_back(matrix[top][i]);
                k++;
            }
            top++;
            if(k<m*n){
            for(int j=top;j<=down;j++){
                ans.push_back(matrix[j][right]);
                k++;
            }
                right--;
            }
            
            if(k<m*n){
            for(int i=right;i>=left;i--){
                ans.push_back(matrix[down][i]);
                k++;
            }
                down--;
            }
            
            if(k<m*n){
            for(int j=down;j>=top;j--){
                ans.push_back(matrix[j][left]);
                k++;
            }
                left++;
            }
            
            
        }
        return ans;
    }
};
