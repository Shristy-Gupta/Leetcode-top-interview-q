struct comp {
   
   static bool  c(int a,int b){
        string order1=to_string(a)+to_string(b);
        string order2=to_string(b)+to_string(a);
        return a+b>b+a;
    }
};

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        //get the first digit of all the elements
            vector<string> asString;
            int n=nums.size(); 
           string ans="";
        sort(nums.begin(),nums.end(),[](int a,int b){
            string order1=to_string(a)+to_string(b);
            string order2=to_string(b)+to_string(a);
            return order1>order2;
        });
        
        for(int s:nums){
            ans+=to_string(s);
        }
        if(ans[0]=='0'){
            return "0";
        }
        return ans;
    }
};
