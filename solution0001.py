class Solution(object):

    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        length = len(nums)
        for i in range(length):
            b = target - nums[i]
            for j in range(i+1, length):
                if b == nums[j]:
                    return [i, j]
        #         else:
        #             continue
        # return [i, j]

if __name__ == '__main__':
    nums = [1, 2, 3, 4, 5]
    target = 7
    s = Solution()
    print(s.twoSum(nums, target))
