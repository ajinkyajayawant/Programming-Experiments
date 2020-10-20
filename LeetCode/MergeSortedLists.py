# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def mergeTwoLists(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        return mergeLists(l1, l2)
            
            
def mergeLists(l1, l2):
    if l1 and l2:
        if l1.val <= l2.val:
            mergedList = l1
            mergedList.next = mergeLists(l1.next, l2)
        else:
            mergedList = l2
            mergedList.next = mergeLists(l1, l2.next)
    elif not l1:
        mergedList = l2
    else:
        mergedList = l1
    return mergedList
