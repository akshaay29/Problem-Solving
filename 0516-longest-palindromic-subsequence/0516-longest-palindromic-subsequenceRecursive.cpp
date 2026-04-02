class Solution {
public:
    int solve(int i,int j,string s){
        if(i>j) return 0;
        if(i==j) return 1;
        if(s[i]==s[j]) return 2+solve(i+1,j-1,s);
        return max(solve(i+1,j,s) , solve(i,j-1,s));
    }
    int longestPalindromeSubseq(string s) {
        return solve(0,s.size() - 1, s);
    }
};