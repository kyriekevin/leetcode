class Solution:
    def findReplaceString(self, s: str, indices: List[int], sources: List[str], targets: List[str]) -> str:
        d = list(zip(indices, sources, targets))
        d.sort(key=lambda x: x[0], reverse=True)

        res = s
        for item in d:
            if s[item[0]:].startswith(item[1]):
                res = res[: item[0]] + item[2] + res[item[0] + len(item[1]):]
        
        return res
