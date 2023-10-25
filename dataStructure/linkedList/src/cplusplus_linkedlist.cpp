#include "../../../utils/common.hpp"

/**
 * Definition for singly-linked list.
*/ 
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};



class Solution {
public:
    /**
     * 迭代，通过双指针实现
    */
    ListNode* reverseList(ListNode* head) {
        ListNode* cur = head;    // 指向头结点
        ListNode* pre = nullptr;  // 指向None
        while (cur != nullptr) {
            ListNode* tmp = cur->next;  // 暂存后继节点 cur.next
            cur->next = pre;   // 修改 next 引用指向
            pre = cur;   // pre 暂存 cur
            cur = tmp;   // cur 访问下一节点
        }
        return pre;
    }

    void printLinkedlist(ListNode* head) {
        ListNode* cur = head;
        while (cur != nullptr) {
            cout << cur->val << " ";
            cur = cur->next;
        }
        cout << endl;    
    }
};

int main(){
    ListNode* head = new ListNode(1);   // 创建链表头结点
    head->next = new ListNode(2);  // 链表添加新的节点

    Solution solution;
    solution.printLinkedlist(head);
    ListNode* reversedHead = solution.reverseList(head);
    cout << "After reverse: " << endl;
    solution.printLinkedlist(reversedHead);
}