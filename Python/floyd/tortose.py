# this is an execution of Floyd's Tortoise and the hare 
# search algorithm.

def findDuplicate(nums):
    slow = nums[0]
    fast = nums[0]

    while True:
        slow = nums[slow]
        fast = nums[nums[fast]]
        if slow == fast:
            break

    ptr1 = nums[0]
    ptr2 = slow
    while ptr1 != ptr2:
        ptr1 = nums[ptr1]
        ptr2 = nums[ptr2]

    return ptr1
# 3, 1, 3, 4, 2
print("Original list: {%(d1)d, %(d2)d, %(d1)d, %(d3)d, %(d4)d}" 
        % {'d1':3, 'd2':1, 'd3':4, 'd4':2})
print(findDuplicate([3,1,3,4,2]))
