from typing import List, Optional

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


def constructTree(l:list) -> Optional[TreeNode]:
    if not l: return None
    null = None
    head = TreeNode(val=l.pop(0))
    queue = [head]
    while l and queue:
        cur = queue.pop(0)
        lval = l.pop(0)
        if lval != None:
            curl = TreeNode(val=lval)
            queue.append(curl)
            cur.left = curl
        if l:
            rval = l.pop(0)
            if rval != None:
                curr = TreeNode(val=rval)
                queue.append(curr)
                cur.right = curr
#         print(queue)
    return head

def inorderTraversal(root):
    res = []
    def Traversal(subroot):
        if not subroot:
            return 
        Traversal(subroot.left)
        res.append(subroot.val)
        Traversal(subroot.right)
    Traversal(root)
    return res

def constructList(l: list) -> Optional[ListNode]:
    head = ListNode(val=l[0],next=None)
    
    idx = 1
    ptr = head
    while idx < len(l):
        cur = ListNode(val=l[idx],next=None)
        ptr.next = cur
        ptr = cur
        idx += 1
    
    return head

