//https://leetcode.cn/problems/sort-an-array
class Solution {
public:
    void heapInsert(vector<int>& arr,int i){
        while(arr[i]>arr[(i-1)/2]){
            swap(arr,i,(i-1)/2);
            i=(i-1)/2;
        }
    }
    void swap(vector<int>& arr,int a,int b){
        int temp=arr[a];
        arr[a]=arr[b];
        arr[b]=temp;
    }
    void heapify(vector<int>& arr,int i,int sz){
        int l=i*2+1;
        while(l<sz){
            int best=i*2+2<sz&&arr[i*2+2]>arr[i*2+1]?i*2+2:i*2+1;
            best=arr[best]>arr[i]?best:i;
            if(best==i) break;
            swap(arr,best,i);
            i=best;
            l=i*2+1;
        }
    }
    void heapSort(vector<int>& arr){
        int n=arr.size();
        for(int i=0;i<n;i++){
            heapInsert(arr,i);
        }
        int sz=n;
        while(sz>1){
            swap(arr,0,--sz);
            heapify(arr,0,sz);
        }
    }
    vector<int> sortArray(vector<int>& nums) {
        if(nums.size()>1){
            heapSort(nums);
        }
        return nums;
    }
};
