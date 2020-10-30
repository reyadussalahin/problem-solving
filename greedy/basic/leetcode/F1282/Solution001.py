# problem name: Group the People Given the Group Size They Belong To
# problem link: https://leetcode.com/problems/group-the-people-given-the-group-size-they-belong-to/
# contest link: (?)
# time: (?)
# author: ratul14


# other_tags: (?)
# difficulty_level: medium


class Solution:
    def groupThePeople(self, groupSizes: List[int]) -> List[List[int]]:
        groups = []
        tracker = {}
        
        for i in range(len(groupSizes)):
            size = groupSizes[i]
            
            if size not in tracker or tracker[size][1] == size:
                tracker[size] = [len(groups), 0]
                groups.append([])
            
            groups[tracker[size][0]].append(i) 
            tracker[size][1] += 1
            
        return groups
