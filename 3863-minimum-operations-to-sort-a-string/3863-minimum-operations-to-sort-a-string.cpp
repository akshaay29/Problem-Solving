class Solution {
public:
    int minOperations(string s) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int n=s.size();
        string target=s;
        sort(target.begin(),target.end());
        if(s==target) return 0;
        if(n==2) return -1;
        if(s[0]==target[0] || s[n-1]==target[n-1]) return 1;
        int mini=0,maxi=0;
        for(char c:s){
            if(c==target[0]) mini+=1;
            else if(c==target[n-1]) maxi+=1;
        }
        if(mini==1 && maxi==1 && s[n-1]==target[0] && s[0]==target[n-1]) return 3;
        return 2;
    }
};