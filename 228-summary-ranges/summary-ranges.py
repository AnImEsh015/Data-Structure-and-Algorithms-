class Solution:
    def summaryRanges(self, nums: List[int]) -> List[str]:
        n = len(nums)
        if n < 1:
            return []
        result = []
        l = 0
        for i in range (1,n):
            if nums[i] - nums[i-1] != 1:
                if nums[l] == nums[i-1]:
                    result.append(str(nums[l]))
                else:
                    result.append(str(nums[l]) + "->" + str(nums[i-1]))
                l = i
        if l == n-1 :
            result.append(str(nums[l]))
        else:
            result.append(str(nums[l]) + "->" + str(nums[n-1]))
        return result