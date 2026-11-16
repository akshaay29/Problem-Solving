class Solution {
public:
    string solve(string s,int k){
        string ans="";
        if(s.size()<=k) return s;
        for(int i=0;i<s.size();i+=k){
            string block=s.substr(i,k);
            int sum=0;
            for(char c: block){
                sum+=(c-'0');
            }
            ans+=to_string(sum);
        }
        s=ans;
        return solve(s,k);
    }
    string digitSum(string s, int k) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        return solve(s,k);
    }
};