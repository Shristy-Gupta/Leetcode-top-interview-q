class Solution {
public:
    bool canJump(vector<int>& nums) {
       
        int n=nums.size();
        if(n==0 || n==1){
            return true;
        }
         if(nums[0]==0){
            return false;
        }
        bool dp[n];
        dp[0]=true;
        //LIS
        for(int i=1;i<n;i++){
             dp[i]=false;
            for(int j=i-1;j>=0;j--){
                if(dp[j]!=false && nums[j]+j>=i){
                    dp[i]=true;
                    break;
                }
            }
        }
        return dp[n-1];
    }
};
