//https://www.youtube.com/watch?v=WiEqhI7v2FY
class Solution {
public:
    int liphelper(vector<vector<int>>& matrix, vector<vector<int>>& dp, int x, int y){
      int n=matrix.size();
      int m=matrix[0].size();
      if(x<0 || x>=n || y<0 || y>=m){
          return 0;
      }
      if(dp[x][y]!=-1){
          return dp[x][y];
      }
      // up, down , left , right  
      int axis[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
      int ans=0;  
      for(int k=0;k<4;k++){
         int new_x=x+axis[k][0];
         int new_y=y+axis[k][1];
         if(new_x>=0 && new_x<n && new_y>=0 && new_y<m && matrix[new_x][new_y]>matrix[x][y]){
             ans=max(ans,liphelper(matrix,dp,new_x,new_y));
         } 
      }
        return dp[x][y]=1+ans;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        if(n==0 && n==0){
            return 0;
        }
        vector<vector<int>> dp(n,vector<int>(m,-1));
        int ans=1;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                ans=max(ans,liphelper(matrix,dp,i,j));
            }
        }
        return ans;
    }
};
