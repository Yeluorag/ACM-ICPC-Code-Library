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
	int getListLength(ListNode* head) {
		int cnt = 0;
		while(head) {
			head = head->next;
			cnt ++;
		}
		return cnt;
	}

	ListNode* addHead(ListNode* head, ListNode* Node) {
		Node->next = head;
		return Node;
	}

	ListNode* reverseKGroup(ListNode* head, int k) {
		int length = getListLength(head);
		ListNode tmpHead(-1);
		ListNode* pNode = &tmpHead;
		while(length >= k) {
			ListNode* pHead = NULL;
			for(int i = 0; i < k; i ++) {
				ListNode* tmp = head;
				head = head->next;
				tmp->next = NULL;
				pHead = addHead(pHead, tmp);
			}
			pNode->next = pHead;
			while(pNode->next != NULL) pNode = pNode->next;
			length -= k;
		}

		pNode->next = head;
		return tmpHead.next;
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