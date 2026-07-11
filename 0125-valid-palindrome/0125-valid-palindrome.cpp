class Solution {
public:
    bool isalphanum(char c){
        if((tolower(c)>='a' && tolower(c)<='z')||( c>='0' && c<='9')) return true;
        return false;
    }
    bool isPalindrome(string s) {
        int i=0,j=s.size()-1;
        while(i<j){
            if(!isalphanum(s[i])){
                i+=1;
                continue;
            }
            if(!isalphanum(s[j])){
                j-=1;
                continue;
            }
            if(tolower(s[i++])!=tolower(s[j--])) return false;
        }
        return true;
    }
};