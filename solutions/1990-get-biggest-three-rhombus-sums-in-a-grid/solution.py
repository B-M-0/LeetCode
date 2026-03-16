class Solution:
    def getBiggestThree(self, grid: List[List[int]]) -> List[int]:
        def getRhombusSum(grid, r, c, d):
            if d == 0:
                return grid[c][r]
            # 4 corners
            total = grid[c][r-d] + grid[c][r+d] + grid[c-d][r] + grid[c+d][r]
            
            # 4 edges
            for i in range(1, d):
                total += grid[c+(d-i)][r-i] 
                total += grid[c+(d-i)][r+i] 
                total += grid[c-(d-i)][r+i] 
                total += grid[c-(d-i)][r-i] 
                
            return total
        """
        :type grid: List[List[int]]
        :rtype: List[int]
        """
        x = len(grid[0])
        y = len(grid)
        ls = []
        rows, cols = len(grid), len(grid[0])
        ls = []

        for r in range(x):
            for c in range(y):
                max_d = min(r, x - 1 - r, c, y - 1 - c)
                
                for d in range(max_d + 1):
                    ls.append(getRhombusSum(grid, r, c, d))

        ls.sort()
        unique_sums = list(set(ls))
        unique_sums.sort(reverse=True)
        return unique_sums[:3]
        
  


        
        
