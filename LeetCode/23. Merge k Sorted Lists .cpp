#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
struct node {
    int val;
    int from;
};

class Solution {
public:
    void heapAdjust(node* heap, int i, int size) {
        int tmp = i;
        int leftChild = 2 * i + 1;
        int rightChild = 2 * i + 2;
        if(i < size / 2) {
            if(leftChild < size && heap[leftChild].val < heap[tmp].val) {
                tmp = leftChild;
            }
            if(rightChild < size && heap[rightChild].val < heap[tmp].val) {
                tmp = rightChild;
            }
            if(tmp != i) {
                swap(heap[tmp], heap[i]);
                heapAdjust(heap, tmp, size);
            }
        }
    }
    ListNode* mergeKLists(vector<ListNode*> &lists) {
        int K = lists.size();
        ListNode head(-1);
        ListNode* tmp = &head;
        if(K == 0) return head.next;
        node heap[K];
        for(int i = 0; i < K; i ++)
            heap[i].val = INT_MAX, heap[i].from = -1;
        for(int i = 0; i < K; i ++) {
            node thisNode;
            if(lists[i] != NULL) {
                thisNode.val = lists[i]->val;
            } else {
                thisNode.val = INT_MAX;
            }
            thisNode.from = i;
            heap[i] = thisNode;
        }
        for(int i = K / 2 - 1; i >= 0; i --)
            heapAdjust(heap, i, K);
        
        while(heap[0].val < INT_MAX) {
            int index = heap[0].from;
            tmp->next = lists[index];
            lists[index] = lists[index]->next;
            if(lists[index] != NULL) {
                heap[0].val = lists[index]->val;
                heap[0].from = index;
                heapAdjust(heap, 0, K);
            } else {
                heap[0].val = INT_MAX;
                heapAdjust(heap, 0, K);
            }
            tmp = tmp->next;
        } 
        return head.next;
    }
};

#define LOCAL
int main() {
#ifdef LOCAL
    freopen("/Users/apple/input.txt","r",stdin);
    //	freopen("/Users/apple/out.txt","w",stdout);
#endif
    Solution cc;
    vector<ListNode*> lists;
    ListNode head(1);
    ListNode* list = &head;
    list->val = 1;
    lists.push_back(list);
    ListNode* newlist = cc.mergeKLists(lists);
    while(newlist != NULL) {
        cout << newlist->val << endl;
        newlist = newlist->next;
    }
    
    return 0;
    
}