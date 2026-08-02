//n 对情侣坐在连续排列的 2n 个座位上，想要牵到对方的手。
//人和座位由一个整数数组 row 表示，其中 row[i] 是坐在第 i 个座位上的人的 ID。
//情侣们按顺序编号，第一对是 (0, 1)，第二对是 (2, 3)，以此类推，最后一对是 (2n - 2, 2n - 1)。
//返回 最少交换座位的次数，以便每对情侣可以并肩坐在一起。 每次交换可选择任意两人，让他们站起来交换座位。
//https://leetcode.cn/problems/couples-holding-hands
class Solution {
public:
    const int maxn=31;
    int sets=0;
    vector<int>father;
    void build(int m){
        father.resize(maxn);
        for(int i=0;i<maxn;i++){
            father[i]=i;
        }
        sets=m;
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
    int minSwapsCouples(vector<int>& row) {
        int n=row.size();
        build(n/2);
        for(int i=0;i<n;i+=2){
            unite(row[i]/2,row[i+1]/2);
        }
        return n/2-sets;
    }
};
