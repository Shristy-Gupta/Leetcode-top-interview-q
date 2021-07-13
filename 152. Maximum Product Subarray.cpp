class Solution {
public:
    int maxProduct(vector<int>& nums) {
        //kadane principle
        int res=INT_MIN,n=nums.size();
        int curMin=1,curMax=1;
        for(int i=0;i<n;i++){
            res=max(res,nums[i]);
        }
        for(int i=0;i<n;i++){
            if(nums[i]==0){
                //reset to 1
                curMin=1;curMax=1;
                continue;
            }
            int temp=curMax*nums[i];
            curMax=max(curMax*nums[i],max(curMin*nums[i],nums[i]));
            curMin=min(temp,min(curMin*nums[i],nums[i]));
            res=max(curMax,res);
        }
        return res;
    }
};
