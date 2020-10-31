# problem name: Max Increase to Keep City Skyline
# problem link: https://leetcode.com/problems/max-increase-to-keep-city-skyline/
# contest link: (?)
# time: (?)
# author: ratul14


# other_tags: greedy
# difficulty_level: medium


class Solution:
    def maxIncreaseKeepingSkyline(self, grid: List[List[int]]) -> int:
        maxCols = []
        maxRows = []
        gridSz = len(grid)
        rng = range(gridSz)
        ans = 0
        
        #maxRows
        for row in grid:
            maxRows.append(max(row))
            
        #maxCols

        for i in rng:
            tlist = list()
            for row in grid:
                tlist.append(row[i])
            maxCols.append(max(tlist))
            
        for r in rng:
            for c in rng:
                ans += min(maxRows[r], maxCols[c]) - grid[r][c]
                
        return ans;
