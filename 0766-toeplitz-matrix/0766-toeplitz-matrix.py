class Solution:
    def isToeplitzMatrix(self, matrix: List[List[int]]) -> bool:
        
        rowMax = len(matrix) - 1
        colMax = len(matrix[0]) - 1
        
        for i in range(rowMax):
            for j in range(colMax):
                if matrix[i][j] is not matrix[i + 1][j + 1]:
                    return False
                
        return True