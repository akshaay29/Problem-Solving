class Solution {
public:
    string reverseWords(string s) {
        vector<string> wordlist;
        stringstream ss(s);
        string word;
        while(ss>>word){
            wordlist.push_back(word);
        }
        int l=0,r=wordlist.size()-1;
        while(l<=r){
            swap(wordlist[l++],wordlist[r--]);
        }
        string result="";
        for(int i=0;i <= wordlist.size()-1;i++){
            if(i==wordlist.size()-1) result+=wordlist[i];
            else result+=wordlist[i]+" ";
        }
        return result;
    }
};