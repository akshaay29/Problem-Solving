class Solution {
public:
    int numberOfSpecialChars(string s) {
        int ans=0;
        vector<int>v1(26,false) , v2(26,false);
        for(char c:s){
            if(c>='a' && c<='z') v1[c-'a']=true;
            else v2[c-'A']=true;
        }
        for(int i=0;i<26;i++) if(v1[i]==true && v2[i]==true) ans+=1;
        return ans;
    }
};