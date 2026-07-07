class Solution {
public:
    long long sumAndMultiply(int n) {
        int div=n;
        long long sum=0;
        int ans=0 , mul=1;
        while(div>0){
            int rem=div%10;
            if(rem!=0){
                sum+=rem;
                ans=ans + rem*mul;
                mul=mul*10;
            }
            div=div/10;
        }
        return ans*sum;
    }
};