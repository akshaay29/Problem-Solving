class Solution {
public:
    bool isVowel(char &c){
        if(c=='a'|| c=='e' || c=='u' || c=='i' || c=='o') return true;
        return false;
    }
    int maxVowels(string s, int k) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        int left=0 , max_cnt=INT_MIN , cnt=0;
        for(int right=0;right<s.size();right++){
            if(isVowel(s[right])) cnt+=1;
            while( right-left+1 >k){
                if(isVowel(s[left])) cnt-=1;
                left+=1;
            }
            if(right-left+1 == k) max_cnt=max(cnt,max_cnt);
        }
        return (max_cnt==INT_MIN) ? 0:max_cnt;
    }
};