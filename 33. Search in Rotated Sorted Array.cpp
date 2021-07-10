//https://youtu.be/Id-DdcWb5AU
class Solution {
public:
    int binarysearch(vector<int>& nums, int i, int j,int x){
        if(i==-1){i=0;}
        while(i<=j){
            int mid=i+(j-i)/2;
            if(nums[mid]==x){
                return mid;
            }
            if(nums[mid]<x){
                i=mid+1;
            }
            else{
                j=mid-1;
            }
        }
        return -1;
    } 
    int search(vector<int>& nums, int target) {
        //find pivot
        int pivot=-1,n=nums.size();
        if(nums[0]==target){return 0;}
        for(int i=1;i<n;i++){
            if(nums[i]==target){
                return i;
            }
            if(nums[i]<nums[i-1]){
                pivot=i;
                break;
            }
        }
        //present in the right half
        return binarysearch(nums,pivot,n-1,target);
    }
};
