#include<string.h>
class Solution {
public:
    string longestPalindrome(string s) {
        //https://www.youtube.com/watch?v=wuOOOATz_IA&list=PL_z_8CaSLPWekqhdCPmFohncHwz8TY2Go&index=26
        if(s.length()<1){return s;}
        if(s.length()==1){return s;}
        string t=s;
        reverse(t.begin(),t.end()); 
        string ans="";
        int n=s.length();
        int dp[n+1][n+1];
        for(int i=0;i<=n;i++){
            dp[i][0]=0;
            dp[0][i]=0;
        }
        //cout<<s<<" "<<t<<endl;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(s[i-1]==t[j-1]){
                    //cout<<s[i-1]<<" "<<t[j-1]<<endl;
                    //ans+=s[i-1];
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        int i=n,j=n;
        while(i>0 && j>0){
          if(s[i-1]==t[j-1]){
              ans+=s[i-1];
              i--;j--;
          }
            else{
                if(dp[i-1][j]>dp[i][j-1]){
                    i--;
                }
                else{
                    j--;
                }
            }
        }
        return ans;
        
    }
};
