//https://www.nowcoder.com/share/jump/1997206311789113011251
/**
 * struct ListNode {
 *	int val;
 *	struct ListNode *next;
 *	ListNode(int x) : val(x), next(nullptr) {}
 * };
 */
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        //小根堆
        auto cmp=[](ListNode* a,ListNode* b){
            return a->val>b->val;
        };
        priority_queue<ListNode*,vector<ListNode*>,decltype(cmp)>heap(cmp);

        for(ListNode* h:lists){
            if(h!=nullptr){
                heap.push(h);
            }
        }
        if(heap.empty()){
                return nullptr;
        }
        ListNode* h=heap.top();
        heap.pop();
        ListNode* pre=h;
        if (pre->next!=nullptr){
            heap.push(pre->next);
        }
        while(!heap.empty()){
            ListNode* cur=heap.top();
            heap.pop();
            pre->next=cur;
            pre=cur;
            if(pre->next!=nullptr){
                heap.push(pre->next);
            }
        }
        return h;

    }

};
