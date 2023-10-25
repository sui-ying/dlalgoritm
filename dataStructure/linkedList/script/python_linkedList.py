
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class LinkedList:
    def __init__(self):

        self.head = None

    def create(self, data):
        self.head = ListNode(0)   # 创建节点
        cur = self.head

        for i in range(len(data)):
            node = ListNode(data[i])
            cur.next = node
            cur = cur.next

    def printList(self):
        cur = self.head
        while cur:
            print(cur.val, end=" ")
            cur = cur.next
        print()

    def length(self):
        count = 0
        cur = self.head
        while cur:
            count += 1
            cur = cur.next
        return count

    # InsertElement

    def insertFront(self, val):
        node = ListNode(val)
        node.next = self.head
        self.head = node

    def insertBack(self, val):
        node = ListNode(val)
        cur = self.head
        while cur.next:
            cur = node.next
        cur.next = node

    def insertInside(self, index, val):
        """
        偏移到具体位置的节点时，新建一个节点连接上去
        """
        count = 0
        cur = self.head
        while cur and count < index - 1:
            count += 1
            cur = cur.next
        if not cur:
            return EOFError

        node = ListNode(val)
        node.next = cur.next
        cur.next = node

    def change(self, index, val):

        count = 0
        cur = self.head
        while cur and count < index:
            count += 1
            cur = cur.next
        if not cur:
            return "Error"

        cur.val = val

    # delete element
    def removeFront(self):
        if self.head:
            self.head = self.head.next

    def removeBack(self):
        if self.head is None:  # 链表为空 无须操作
            return

        if self.head.next == None:
            self.head = None
            return

        cur = self.head
        prev = None
        while cur.next:
            prev = cur
            cur = cur.next
        prev.next = None

    def removeInside(self, index):
        count = 0
        cur = self.head
        while cur.next and count < index-1:
            count += 1
            cur = cur.next
        if not cur:
            return "Error"

        del_node = cur.nex
        cur.next = del_node.next

    def reverse(self):
        """
        迭代，通过双指针实现
        """
        prev = None   # 指向None
        cur = self.head   # 指向头结点
        while cur:
            next_node = cur.next  # 暂存后继节点
            cur.next = prev  # 当前节点指向更改为prev
            prev = cur    # pre暂存当前节点
            cur = next_node  # 当前节点指向 next_node，即链表末尾
        self.head = prev


if __name__ == '__main__':
    llst = LinkedList()
    llst.create([1, 2, 3, 4, 6])
    llst.reverse()
    llst.printList()




