class Solution {
public:
    bool isPowerOfTwo(int n) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        if(n<=0) return false;
        return (n & (n-1))==0 ?true:false;
    }
};