class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        unordered_set<string>st(bank.begin(),bank.end());
        if(!st.contains(endGene)) return -1;
        if(st.contains(startGene)) st.erase(startGene);
        vector<char>choices={'A','C','G','T'};
        queue<pair<string,int>>q;
        q.push({startGene,0});
        while(!q.empty()){
            string word=q.front().first;
            int steps=q.front().second;
            q.pop();
            if(word==endGene) return steps;
            for(int i=0;i<word.size();i++){
                char org_ch=word[i];
                for(char mutation:choices){
                    word[i]=mutation;
                    if(st.contains(word)){
                        st.erase(word);
                        q.push({word,steps+1});
                    }
                }
                word[i]=org_ch;
            }
        }
    return -1;
    }
};