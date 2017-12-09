from leetcodesolution import *

def testTwoSum():
    arglist = []
    arglist.append({'nums':[1,2,3,4,5,6,7,8,9], 'target':17, 'answer':[7,8]})
    arglist.append({'nums':[1,2], 'target':3, 'answer':[0,1]})
    arglist.append({'nums':[51,26,44,65,66,79,96], 'target':110, 'answer':[2,4]})
    for arg in arglist:
        print('expected:',arg['answer'], 'output', twoSum(arg['nums'], arg['target']))
'''
def testAddTwoNumbers():
    arglist = []
    arglist.append({'l1':[1,2,3], 'l2':[2,3,1], 'answer':[3,5,4]})
'''