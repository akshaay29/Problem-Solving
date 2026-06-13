class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string res="";
        for(auto word:words){
            int sum=0;
            for(char c:word) sum+=weights[c-'a'];
            sum%=26;
            res+='z'-sum;
        }
        return res;
    }
};