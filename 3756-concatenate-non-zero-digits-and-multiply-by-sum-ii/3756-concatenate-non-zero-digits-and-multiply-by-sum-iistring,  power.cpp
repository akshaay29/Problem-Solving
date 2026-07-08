using ll=long long;
int const c=1e9+7;
class Solution {
public:
    ll power(ll base,ll exp){
        ll res=1;
        base=base%c;
        while(exp>0){
            if(exp%2 == 1) res=(base*res) % c;
            base=(base * base) %c;
            exp/=2;
        }
        return res % c;
    }
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int n=s.size();
        vector<int>cnt_prefix(n+1,0);
        vector<ll>sum_prefix(n+1,0);
        vector<ll>ans_prefix(n+1,0);

        int cnt=0;
        ll sum=0,ans=0;
        for(int i=0;i<n;i++){
            int rem=s[i]-'0';
            if(rem!=0){
                cnt+=1;
                sum+=rem%c;
                ans=(ans*10 + rem)%c;
            }
            cnt_prefix[i+1]=cnt;
            sum_prefix[i+1]=sum;
            ans_prefix[i+1]=ans;
        }
        vector<int>result;
        for(auto query:queries){
            int start=query[0] , end=query[1];
            int gap=cnt_prefix[end+1]-cnt_prefix[start];
            ll range_sum=( sum_prefix[end+1]-sum_prefix[start] + c) % c;
            ll range_ans=(ans_prefix[end+1] - ((ans_prefix[start] * power(10,gap)) % c) + c ) % c;
            ll final_ans=(range_ans*range_sum)%c;
            result.push_back(final_ans);
        }
        return result;

    }
};