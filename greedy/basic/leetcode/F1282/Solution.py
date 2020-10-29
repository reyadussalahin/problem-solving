# problem name: 1282. Group the People Given the Group Size They Belong To
# problem link: https://leetcode.com/problems/group-the-people-given-the-group-size-they-belong-to/
# contest link: (?)
# time: 196ms
# author: ratul14


# other_tags: (?)
# difficulty_level: medium

#submission_link: https://leetcode.com/submissions/detail/405650239/

class Solution:
    def groupThePeople(self, groupSizes: List[int]) -> List[List[int]]:
        ans = list()
        gs = groupSizes
        def proc(gs: List[int]) -> any:
            if set(gs) == {-1}:
                return
            itm = 0
            for i in gs:
                if i == -1:
                    continue
                else:
                    itm = i
                    break
            
            tmpl = list()
            for _ in [0]*itm:
                idx = gs.index(itm)
                tmpl.append(idx)
                gs[idx] = -1
            ans.append(tmpl)
            proc(gs)
        proc(gs)
        return ans;
