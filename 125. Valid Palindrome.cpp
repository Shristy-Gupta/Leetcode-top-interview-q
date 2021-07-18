class Solution {
public:
    bool isPalindrome(string s) {
        if(s.length()<=1){
            return s.length();
        }
        transform(s.begin(),s.end(),s.begin(),::tolower);

        string str="";
        for(int i=0;i<s.length();i++){
            if(s[i]!=' ' && ((s[i]>=48 && s[i]<=57) || (s[i]>=97 && s[i]<=122))){
                str+=s[i];
            }
        }
        int start=0, end=str.length()-1;
        while(start<end){
            if(str[start++]!=str[end--]){
                return false;
            }
        }
        return true;
    }
};
