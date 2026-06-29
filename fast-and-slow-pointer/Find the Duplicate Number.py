class Solution:
    def findDuplicate(self, nums: list[int]) -> int:
        # Step 1: Find the intersection point of the two pointers
        slow = fast = nums[0]
        
        while True:
            slow = nums[slow]
            fast = nums[nums[fast]]
            if slow == fast:
                break
                
        # Step 2: Find the entrance to the cycle
        slow = nums[0]
        while slow != fast:
            slow = nums[slow]
            fast = nums[fast]
            
        return slow
