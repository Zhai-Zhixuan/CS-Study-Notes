//https://leetcode.cn/problems/similar-string-groups
class Solution {
public:
    vector<int>father;
    int sets=0;
    void build(int n){
        father.resize(n);
        for(int i=0;i<n;i++){
            father[i]=i;
        }
        sets=n;
    }
    int find(int i){
        if(father[i]!=i){
            father[i]=find(father[i]);
        }
        return father[i];
    }
    void unite(int x,int y){
        int fx=find(x),fy=find(y);
        if(fx!=fy){
            father[fx]=fy;
            sets--;
        }
    }
    int numSimilarGroups(vector<string>& strs) {
        int n=strs.size();
        build(n);
        int counts=0;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                int diff=0;
                for(int k=0;k<strs[0].size();k++){
                    if(strs[i][k]!=strs[j][k]){
                        diff++;
                    }
                }
                if(diff==0||diff==2){
                    unite(i,j);
                }
            }
        }
        return sets;
    }
};
