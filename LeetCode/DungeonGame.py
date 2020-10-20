# 41/45 test cases passed but time limit exceeded

class Solution(object):
    def calculateMinimumHP(self, dungeon):
        """
        :type dungeon: List[List[int]]
        :rtype: int
        """
        m = len(dungeon)
        n = len(dungeon[0])
        min_cur_l = calculateHealth(dungeon, m-1, n-1, m, n)
        min_cur_f = getMinCur(min_cur_l)
        return max(-min_cur_f[0] + 1, 1)
        
        
def calculateHealth(dg, i, j, m, n):
    # current is only for comparing, min is essential
    val = dg[i][j]
    
    if i > 0 and j > 0:
        min_cur_l = calculateHealth(dg, i, j-1, m, n)
        min_cur_l1 = updateMinCurList(min_cur_l, val)

        min_cur_l = calculateHealth(dg, i-1, j, m, n)
        min_cur_l2 = updateMinCurList(min_cur_l, val)

        min_cur_l3 = min_cur_l1 + min_cur_l2

        min_cur_lf = pruneList(min_cur_l3)
    elif i == 0 and j > 0:
        min_cur_l = calculateHealth(dg, i, j-1, m, n)
        min_cur_lf = updateMinCurList(min_cur_l, val)
        # min_cur_lf = pruneList(min_cur_l2)
    elif i > 0 and j == 0:
        min_cur_l = calculateHealth(dg, i-1, j, m, n)
        min_cur_lf = updateMinCurList(min_cur_l, val)
        # min_cur_lf = pruneList(min_cur_l2)
    elif i == 0 and j == 0:
        min_cur_lf = [[val, val]]
    else:
        raise ValueError("Out of bounds")
    
    return min_cur_lf

def getMinCur(min_cur_l):
    max_h = min_cur_l[0][0]
    max_id = 0
    
    for el_id, el in enumerate(min_cur_l):
        if el[0] > max_h:
            max_h = el[0]
            max_id = el_id
    
    return min_cur_l[max_id]

def pruneList(l):
    l_mark = [True]*len(l)
    for el in l:
        for sc_id, screen in enumerate(l):
            if screen[0]<el[0] and screen[1]<el[1]:
                l_mark[sc_id] = False

    l_new = []
    for el_id, el in enumerate(l):
        if l_mark[el_id] == True:
            l_new.append(el)
    
    return l_new

def updateMinCurList(min_cur_in, val):
    for el in min_cur_in:
        minCurUpdateTuple(el, val)
    return min_cur_in

def minCurUpdateTuple(min_cur_l, val):
    min_cur_l[1] = min_cur_l[1] + val

    if min_cur_l[1] < min_cur_l[0]:
        min_cur_l[0] = min_cur_l[1]
        
    return min_cur_l
        
def minCurUpdate(min_h, cur_h, val):
    cur_hf = cur_h + val

    if cur_hf < min_h:
        min_hf = cur_hf
    else:
        min_hf = min_h
        
    return min_hf, cur_hf
