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

def isMatch(s, p):
    """
    :type s: str
    :type p: str
    :rtype: bool
    """
    memo = {}
    def dp(i, j):
        if (i, j) not in memo:
            if j == len(p):
                ans = i == len(s)
            else:
                fm = i < len(s) and p[j] in {s[i], '.'}
                if j+1 < len(p) and p[j+1] == '*':
                    ans = fm or dp(i, j+2) and dp(i+1, j)
                else:
                    ans = fm and dp(i+1, j+1)
            memo[i, j] = ans
        return memo[i, j]
    return dp(0, 0)

def maxArea(height):
    """
    :type height: List[int]
    :rtype: int
    """
    maxarea = 0
    l = 0
    r = len(height)-1
    while(r > l):
        maxarea = max(maxarea, min(height[l], height[r]) * (r-l))
        if height[l] > height[r]:
            r-=1
        else:
            l+=1
    return maxarea

def isValid(s):
    ':type s: str    :rtype: bool'
    pairs = {'{':'}', '[':']', '(':')'}
    stack = []
    for c in s:
        if c in pairs:
            stack.append(c)
        else:
            if len(stack)==0:
                return False
            elif c in pairs.values():
                if pairs[stack[-1]] == c:
                    stack.pop()
                else:
                    return False
            else:
                return False
    if len(stack)!=0:return False
    return True

def mergeTwoLists(l1, l2):
    ':type l1: ListNode    :type l2: ListNode    :rtype: ListNode'
    if not l1:return l2
    if not l2:return l1
    hl = None
    if l1.val < l2.val:
        hl = l1
        hl.next = mergeTwoLists(l1.next, l2)
    else:
        hl = l2
        hl.next = mergeTwoLists(l1, l2.next)
    return hl

def removeDuplicates(nums):
    ':type nums: List[int]    :rtype: int'
    n = len(nums)
    if n<2:return n
    i = 0
    for j in range(1,n):
        if nums[i]!=nums[j]:
            i+=1
            nums[i] = nums[j]
    print(nums)
    return i+1

def threeSumClosest(nums, target):
    ":type nums: List[int] :type target: int :rtype: int"
    nums.sort()
    ans = sum(nums[:3])
    ln = len(nums)
    for n in range(ln-2):
        l, r = n+1, ln-1
        while l<r:
            s = nums[n] + nums[r] + nums[l]
            d = s-target
            if d==0:
                return s
            elif d>0:
                r-=1
                if d<abs(ans-target):
                    ans = s
            else:
                l+=1
                if -d<abs(ans-target):
                    ans = s
    return ans

def letterCombinations(digits):
    if not digits:return []
    d={'2':'abc','3':'def','4':'ghi','5':'jkl','6':'mno','7':'pqrs','8':'tuv','9':'wxyz'}
    if digits[0] not in d:
        return []
    ans=[c for c in d[digits[0]]]
    for n in digits[1:]:
        l=[]
        try:
            for s in ans:
                for c in d[n]:
                    l.append(s+c)
        except KeyError:
            return []
        ans=l
    return ans


