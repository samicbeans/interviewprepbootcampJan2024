class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        map1 = {} #dict is going to 
        indices= [0] * 3
        sorted(nums)
        for i in nums:
            for j in nums:
                for k in nums:
                    sum = nums[i] + nums[j] + nums[k]
                    if(k != i and k!= j) and ( sum == 0):
                        indices = [nums[i],nums[j],nums[k]]
                        if indices not in map1.keys():
                            map1[indices].append(indices)
        return map1.values()