#include <sstream>
class Solution {
public:
    vector<string> mp(char digit){
        vector<string> ans;
        switch(digit){
        case '0':return ans; break;
        case '1':return ans; break;
        case '2': return ans={"a","b","c"}; break;
        case '3': return ans={"d","e","f"}; break;
        case '4': return ans={"g","h","i"}; break;
        case '5': return ans={"j","k","l"}; break;
        case '6': return ans={"m","n","o"}; break;
        case '7': return ans={"p","q","r","s"}; break;
        case '8': return ans={"t","u","v"}; break;
        case '9': return ans={"w","x","y","z"}; break;
        default: return ans;
        }
        
    }
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if(digits.length()==0){
            return ans;
        }
        if(digits.length()==1){
            return mp(digits[0]);
        }
        vector<string> smallans=letterCombinations(digits.substr(1));
        vector<string> induction=mp(digits[0]);
        if(smallans.size()==0){
            return induction; 
        }
        for(int i=0;i<induction.size();i++){
           for(int j=0;j<smallans.size();j++){
                 ans.push_back(induction[i]+smallans[j]); 
            } 
        }
        return ans;
    }
};
