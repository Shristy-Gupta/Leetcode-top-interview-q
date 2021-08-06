class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
       unordered_map<int,int> umap;
       int n=nums.size(); 
       for(int i=0;i<n;i++){
           umap[nums[i]]=0;
       }
       for(int i=0;i<n;i++){
           int a=nums[i];
           if(umap.find(a-1)!=umap.end()){
               umap[a]=a-1;
           }
           else{
               umap[a]=-1;
           }
       }
        int window_size=1;
        int ans=0;
        for(int i=0;i<n;i++){
                    window_size=1;
                    int a=nums[i];
                    if(umap[a]==-1){
                        while(umap.find(a+1)!=umap.end()){
                           window_size++;
                           a++;
                        }
                    }
            ans=max(ans,window_size);
        }
        return ans;
    }
};
