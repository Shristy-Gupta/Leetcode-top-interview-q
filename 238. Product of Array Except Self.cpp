class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        //O(n) space n time complex
         vector<int> leftsum,rightsum,totalsum;
        int n=nums.size();
        long long int left=1,right=1;
        for(int i=0;i<n;i++){
            leftsum.push_back(left);
            left*=nums[i];
        }
        for(int j=n-1;j>=0;j--){
            rightsum.push_back(right);
            right*=nums[j];
        }
        for(int i=0;i<n;i++){
            totalsum.push_back(leftsum[i]*rightsum[n-i-1]);   
        }
        return totalsum;
    }
};
