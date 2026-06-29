class Solution:
    def findDisappearedNumbers(self, nums: List[int]) -> List[int]:
        # Phase 1: Mark existing numbers as negative
        for num in nums:
            idx = abs(num) - 1
            if nums[idx] > 0:
                nums[idx] = -nums[idx]
                
        # Phase 2: Collect positive indices
        return [i + 1 for i, num in enumerate(nums) if num > 0]
