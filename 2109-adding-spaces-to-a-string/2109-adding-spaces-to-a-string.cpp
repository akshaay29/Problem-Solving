class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int i=0,j=0;
        string result="";
        while(i<s.size()){
            if(j<spaces.size() && i==spaces[j]){
                result+=" ";
                j+=1;
            }
            result.push_back(s[i]);
            i+=1;
        }
        return result;
    }
};