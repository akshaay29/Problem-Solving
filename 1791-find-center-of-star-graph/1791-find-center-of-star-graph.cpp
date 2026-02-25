class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        vector<int>relation(edges.size()+2,0);
        for(auto i:edges){
            int u=i[0] , v=i[1];
            relation[u]+=1;
            relation[v]+=1;
        }
        for(int i=1;i<=edges.size()+1;i++) if(relation[i]==edges.size()) return i;
        return 0;
    }
};