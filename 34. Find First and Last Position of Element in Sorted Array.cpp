//https://youtu.be/zr_AoTxzn0Y
class Solution {
public:
    int endindex(vector<int>& nums, int target, int start, int end){
       int ans=-1;
        while(start<=end){
            int mid=start+(end-start)/2;
            if(nums[mid]==target){
                ans=mid;
                start=mid+1;   
            }
            else if(nums[mid]<target){
                start=mid+1;
            }
            else{
                end=mid-1;
            }
        }
        return ans; 
    }
    int startindex(vector<int>& nums, int target, int start, int end){
        int ans=-1;
        while(start<=end){
            int mid=start+(end-start)/2;
            if(nums[mid]==target){
                ans=mid;
                end=mid-1;
                
            }
            else if(nums[mid]<target){
                start=mid+1;
            }
            else{
                end=mid-1;
            }
        }
        return ans;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
     int n=nums.size();
     vector<int> ans;   
     if(n==0){
         ans.push_back(-1);
         ans.push_back(-1);
         return ans;
     }
        
       int start= startindex(nums,target,0,n-1);
       int end= endindex(nums,target,0,n-1);
       ans.push_back(start);
       ans.push_back(end);
         return ans;  
        
    }
};
