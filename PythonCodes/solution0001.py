from functools import cache
class Solution:
    def rotatedDigits(self, n: int) -> int:
        check = [0, 0, 1, -1, -1, 1, 1, -1, 0, 1]
        digits = [int(digit) for digit in str(n)]

        @cache
        def dfs(pos: int, bound: bool, diff: bool) -> int:
            print(pos, bound, diff)
            if pos == len(digits):
                return int(diff)
            
            ret = 0
            for i in range(0, (digits[pos] if bound else 9) + 1):
                if check[i] != -1:
                    ret += dfs(
                        pos + 1,
                        bound and i == digits[pos],
                        diff or check[i] == 1
                    )
            
            return ret
            
        
        ans = dfs(0, True, False)
        dfs.cache_clear()
        return ans

if __name__ == '__main__':
    s = Solution()
    s.rotatedDigits(15)
