class Solution {
public:
    int solve(int i,int j,string s1,string s2){
        if(i==s1.size()) return s2.size()-j;
        if(j==s2.size()) return s1.size()-i;
        if(s1[i]==s2[j] ) return 0+solve(i+1,j+1,s1,s2);
        int ins=1+solve(i,j+1,s1,s2);
        int del=1+solve(i+1,j,s1,s2);
        int rep=1+solve(i+1,j+1,s1,s2);
        return min({ins,del,rep});
    }
    int minDistance(string s1, string s2) {
        int i=0,j=0;
        return solve(i,j,s1,s2);
    }
};