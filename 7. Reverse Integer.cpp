class Solution {
public:
    int reverse(int x) {
        if(x<10 && x>-10){
            return x;
        }
        if(x==INT_MIN || x==INT_MAX){
            return 0;
        }
        bool negative=false;
        if(x<0){
            negative=true;
            x*=-1;
        }
        long long int ans=0;
        while(x>0){
            int base=x%10;
            if(negative && ans*10+base-1>=INT_MAX ||
               !negative && ans*10+base>INT_MAX){
                return 0;
            }
            ans=ans*10+base;
            x=x/10;
        }
        if(negative){return ans*-1;}
        else{return ans;}
    }
};
