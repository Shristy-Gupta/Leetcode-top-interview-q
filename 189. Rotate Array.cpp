class Solution {
public:
    void rotatehelper(vector<int>& nums, int start, int end){
        if(start<0 || end>nums.size() || start>=end){
            return;
        }
        while(start<end){
            swap(nums[start++],nums[end--]);
        }
    }
    void rotate(vector<int>& nums, int k) {
        int n=nums.size();
        if(n<=1){return;}
        if(k>n){
            k=k%n;
        }
        rotatehelper(nums,0,n-k-1);
        rotatehelper(nums,n-k,n-1);
        rotatehelper(nums,0,n-1);
        
    }
};
