class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.length()==0){
            return 0;
        }
        if(haystack.length()==0 ||needle.length()>haystack.length()){
            return -1;
        }
        int ans=-1,j=0;
        for(int i=0;i<haystack.length();i++){
            if(haystack[i]==needle[j]){
                ans=i;
                j++;
                if(j>=needle.length()){return ans;}
                for(int k=i+1;k<haystack.length();k++){
                    if(j>=needle.length()){return ans;}
                    else if(haystack[k]==needle[j]){
                        
                        j++;
                    }
                    else{ans=-1;j=0; break;}
                }
            }
            
        }
        if(j>=needle.length())
        return ans;
        else{
            return -1;
        }
    }
};
