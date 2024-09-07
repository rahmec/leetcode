# Remove Duplicates from Sorted Array

Given an integer array nums sorted in non-decreasing order, remove the duplicates in-place such that each unique element appears only once. The relative order of the elements should be kept the same. Then return the number of unique elements in nums.

Consider the number of unique elements of nums to be k, to get accepted, you need to do the following things:

- Change the array nums such that the first k elements of nums contain the unique elements in the order they were present in nums initially. The remaining elements of nums are not important as well as the size of nums.
- Return k.

## Code

'''
int removeDuplicates(int* nums, int numsSize) {
   int new_array[numsSize];
   size_t length = 0;
   int last_elem;

   for(int i=0; i<numsSize; i++){
        if(nums[i] != last_elem){
            new_array[length] = nums[i];
            length++;
        }
        last_elem = nums[i];
        printf("%d", last_elem);
   }
   for(int i=0; i<length; i++){
        nums[i] = new_array[i];
   }

   return length;
}
'''

