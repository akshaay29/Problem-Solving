class TrieNode{
public:
    bool isEnd;
    TrieNode* children[26];
    int childCount;
    TrieNode(){
        for(int i=0;i<26;i++) children[i]=NULL;
        isEnd=false;
        childCount=0;
    }
};
class Solution {
public:
    TrieNode* root=new TrieNode;
    void insert(string s){
        TrieNode* curr=root;
        for(char c:s){
            if(curr->children[c-'a']==NULL){
                curr->children[c-'a']=new TrieNode;
                curr->childCount+=1;
            }
            curr=curr->children[c-'a'];
        }
        curr->isEnd=true;
    }
    string longestCommonPrefix(vector<string>& strs) {
        for(auto word:strs){
            if(!word.empty()) insert(word);
            else return "";
        }
        TrieNode* curr=root;
        string firstWord=strs[0], res="";
        for(char c:firstWord){
            if(curr->childCount==1 && !curr->isEnd){
                curr=curr->children[c-'a'];
                res+=c;
            }
            else break;
        }
        return res;
    }
};