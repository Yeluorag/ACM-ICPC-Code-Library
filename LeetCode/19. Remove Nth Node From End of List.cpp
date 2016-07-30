#include <iostream>
#include <cstdio>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* removeNthFromEnd(ListNode* head, int n) {
        int index = 1;
        ListNode* node = head;
        ListNode* pre = head;
       	int cnt = 1;
       	while(node->next != NULL) {
       		node = node->next;
       		cnt ++;
       	}
       	node = head;
       	int num = cnt + 1 - n;

       	for(index = 1; index < num; index ++) {
       		if(index > 1) pre = pre->next;
       		node = node->next;
       	}

       	if(index == 1) head = head->next;
       	else pre->next = node->next;
       	delete node;
       	return head;
    } 
};

#define LOCAL
int main() {
#ifdef LOCAL
    freopen("/Users/apple/input.txt","r",stdin);
    //	freopen("/Users/apple/out.txt","w",stdout);
#endif
	Solution cc;


	return 0;

}