class Solution {
public:
    int numSquares(int n) {
        if(n<=1){return n;}
        //LIS  variant
        int dp[n+1];
        memset(dp,0,sizeof(dp));
        dp[1]=1;
        for(int i=2;i<=n;i++){
            int val=INT_MAX;
            for(int j=1;j*j<=i;j++){
                int remaining=i-j*j;
                val=min(val,dp[remaining]);
            }
            dp[i]=val+1;
        }
        return dp[n];
    }
};
