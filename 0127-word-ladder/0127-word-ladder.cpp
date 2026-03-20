class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string>st(wordList.begin(),wordList.end());
        if(st.find(endWord)==st.end()) return 0;
        queue<pair<string,int>>q;
        q.push({beginWord,1});
        if(st.contains(beginWord)) st.erase(beginWord);
        while(!q.empty()){
            auto it=q.front();
            string word=it.first;
            int steps=it.second;
            q.pop();
            if(word==endWord) return steps;
            for(int i=0;i<word.size();i++){
                char org=word[i];
                for(char ch='a';ch<='z';ch++){
                    word[i]=ch;
                    if(st.contains(word)){
                        st.erase(word);
                        q.push({word,steps+1});
                    }
                }
                word[i]=org;
            }
        }
        return 0;
    }
};