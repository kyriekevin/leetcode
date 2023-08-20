class Solution:
    def canChange(self, start: str, target: str) -> bool:
        if start.replace('_', '') != target.replace('_', ''):
            return False

        j = 0
        for i, ch in enumerate(start):
            if ch == '_':
                continue
            while target[j] == '_':
                j += 1

            if i != j and (ch == 'L') == (i < j):
                return False
            j += 1

        return True 
