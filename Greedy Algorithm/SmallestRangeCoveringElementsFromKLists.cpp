//https://leetcode.cn/problems/smallest-range-covering-elements-from-k-lists/description/
class Solution {
public:
    struct Node{
        int v; //值
        int i; //值在第i个列表
        int j; //值在列表的第j个
    };
    struct cmp{
        bool operator()(const Node&a,const Node&b)const{
            if(a.v!=b.v){
                return a.v<b.v;
            }
            return a.i<b.i;
        }
    };
    vector<int> smallestRange(vector<vector<int>>& nums) {
        set<Node,cmp>s;
        int k=nums.size();
        //将各个列表的第一个值加入有序表
        for(int i=0;i<k;i++){
            Node x={nums[i][0],i,0};
            s.insert(x);
        }
        //有序表大小==k时循环
        int mn=INT_MAX;
        int left=0,right=0;
        while(s.size()==k){
            Node minNode=*s.begin();
            Node maxNode=*s.rbegin();

            if(maxNode.v-minNode.v<mn){ //若当前差小于mn，更新最小值
                mn=maxNode.v-minNode.v; //mn=最大值-最小值
                left=minNode.v;
                right=maxNode.v;
            }
            s.erase(s.begin()); 
            int i=minNode.i;
            int nextJ=minNode.j+1; 
            if(nextJ<nums[i].size()){
            Node x={nums[i][nextJ],i,nextJ};
            s.insert(x);
            }
        }
        //返回
        return {left,right};
    }
};
