class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int i=0,j=0,k=0;
        string result(spaces.size()+s.size(),' ');
        while(i<s.size()){
            if(j<spaces.size() && i==spaces[j]){
                k++;
                j+=1;
            }
            result[k++]=s[i++];
        }
        return result;
    }
};