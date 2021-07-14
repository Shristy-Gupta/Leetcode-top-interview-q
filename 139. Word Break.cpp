#include <string.h>
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n=s.length();
        int dictlen=wordDict.size();
        vector<bool>dp(n+1,false);
        //base case
        dp[n]=true;
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<dictlen;j++){
                if(i+wordDict[j].length()<=n && s.substr(i,wordDict[j].length())==wordDict[j]){
                    dp[i]=dp[i+wordDict[j].length()];
                }
                if(dp[i]==true){break;}
            }
        }
        return dp[0];
    }
};
