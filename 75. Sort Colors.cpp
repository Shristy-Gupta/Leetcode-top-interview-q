class Solution {
public:
    void sortColors(vector<int>& nums) {
        int nums0=0,nums1=0,nums2=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]==0){
                nums0++;
            }
            else if(nums[i]==1){
                nums1++;
            }
            else if(nums[i]==2){
                nums2++;
            }
        }
        for(int i=0;i<n;){
            while(nums0--){
                nums[i++]=0;
            }
            while(nums1--){
                nums[i++]=1;
            }
            while(nums2--){
                nums[i++]=2;
            }
        }
    }
};
