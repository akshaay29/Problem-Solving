class Solution {
public:
    bool checkStrings(string s1, string s2) {
        unordered_map<char,int>even , odd;
        for(int i=0;i<s1.size();i++){
            if(i%2==0 ) even[s1[i]]+=1;
            else  odd[s1[i]]+=1;
        }
        for(int i=0;i<s2.size();i++){
            if(i%2==0 ) even[s2[i]]-=1;
            else  odd[s2[i]]-=1;
        }
        for(auto it:even){
            if(it.second != 0) return false; 
        }
        for(auto it:odd){
            if(it.second != 0) return false; 
        }
        return true;
    }
};