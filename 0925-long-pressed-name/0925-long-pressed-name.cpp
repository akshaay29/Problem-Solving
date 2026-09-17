class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int i=0 , j=0 , n1=name.size() , n2=typed.size();
        while(i<n1 && j<n2){
            if(name[i]==typed[j]){
                i+=1;
                j+=1;
            }
            else{
                if(j>0 && typed[j]==typed[j-1]) j+=1;
                else return false;
            }
        }
        while(j<n2){
            if(name[i-1]!=typed[j++])  return false;
        } 
        return (i==n1) ? true:false;
    }
};