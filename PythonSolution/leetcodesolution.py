'solutions of the LeetCode problems'

def twoSum(nums, target):
    """
    :type nums: List[int]
    :type target: int
    :rtype: List[int]
    """
    i = 0
    for a in nums:
        j=i+1
        for b in nums[j:]:
            if target==(a + b):
                return [i,j]
            j+=1
        i+=1
    return None

def addTwoNumbers(l1, l2):
    """
    :type l1: ListNode
    :type l2: ListNode
    :rtype: ListNode
    """
    s = 0
    n = 0
    while n>=0:
        s += (l1.val+l2.val)*(10**n)
        if l1.next is None:
            l1.val = 0
            if l2.next is None:
                n = -1
            else:
                l2 = l2.next
                n += 1
        else:
            l1 = l1.next
            if l2.next is None:
                l2.val = 0
            else:
                l2 = l2.next
            n += 1
    s = [int(x) for x in str(s)]
    s.reverse()
    rl = ListNode(s[0])
    prel = rl
    for d in s[1:]:
        prel.next = ListNode(d)
        prel = prel.next
    return rl

class ListNode:
    'Definition for singly-linked list.'
    def __init__(self, x):
        self.val = x
        self.next = None
