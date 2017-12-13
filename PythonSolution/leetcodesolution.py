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

def findMedianSortedArrays(nums1, nums2):
    '''
    :type nums1: List[int]
    :type nums2: List[int]
    :rtype: float
    '''
    merge = nums1 + nums2
    merge.sort()
    l = len(merge)
    if (l % 2) == 0:
        lm = int(l/2)
        mid = (merge[lm] + merge[lm-1])/2.0
    else:
        lm = int((l-1)/2)
        mid = float(merge[lm])
    return mid

def longestPalindrome(s):
    """
    :type s: str
    :rtype: str
    """
    for width in range(len(s), 0, -1):
        for i in range(0, len(s)-width+1):
            sub = s[i:i+width]
            rsub = sub[::-1]
            if sub == rsub:
                return sub

def zigzagConvert(s, numRows):
    """
    :type s: str
    :type numRows: int
    :rtype: str
    """
    if numRows == 1 or numRows < len(s):
        return s
    zigzag = ['' for i in range(numRows)]
    i = 0
    flag = -1
    for c in s:
        zigzag[i] += c
        if 0 < i < (numRows-1):
            i += flag
        else:
            flag *= -1
            i += flag
    ans = ''
    for row in zigzag:
        ans += row
    return ans
