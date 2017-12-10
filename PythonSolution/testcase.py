from leetcodesolution import *

def testTwoSum():
    arglist = []
    arglist.append({'nums':[1,2,3,4,5,6,7,8,9], 'target':17, 'answer':[7,8]})
    arglist.append({'nums':[1,2], 'target':3, 'answer':[0,1]})
    arglist.append({'nums':[51,26,44,65,66,79,96], 'target':110, 'answer':[2,4]})
    for arg in arglist:
        print('expected:',arg['answer'], 'output:', twoSum(arg['nums'], arg['target']))

def testAddTwoNumbers():
    init = [321, 321, 328, 132, 32, 132]
    lnl = []
    for s in init:
        s = [int(x) for x in str(s)]
        s.reverse()
        rl = ListNode(s[0])
        prel = rl
        for d in s[1:]:
            prel.next = ListNode(d)
            prel = prel.next
        lnl.append(rl)

    arglist = []
    arglist.append({'l1':lnl[0], 'l2':lnl[3], 'answer':[3,5,4]})
    arglist.append({'l1':lnl[1], 'l2':lnl[4], 'answer':[3,5,3]})
    arglist.append({'l1':lnl[2], 'l2':lnl[5], 'answer':[0,6,4]})
    for arg in arglist:
        rl = addTwoNumbers(arg['l1'], arg['l2'])
        result = [rl.val]
        while rl.next:
            rl = rl.next
            result.append(rl.val)

        print('expected:',arg['answer'], 'output:', result)
