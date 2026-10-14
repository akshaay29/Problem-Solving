class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        string res="";
        if(num * 9 <sum) return res;
        int nine=0;
        if(sum>=9) nine=sum/9;
        int rem=sum%9;
        for(int i=0;i<num;i++){
            if(i<nine) res.push_back('9');
            else{
                res.push_back(rem+'0');
                rem-=rem;
            }
        }
        return res;
    }
};