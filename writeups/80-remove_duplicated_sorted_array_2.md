# Remove Duplicated from Sorted Array 2 (80)
Given an integer array nums sorted in non-decreasing order, remove some duplicates in-place such that each unique element appears at most twice. The relative order of the elements should be kept the same.

Since it is impossible to change the length of the array in some languages, you must instead have the result be placed in the first part of the array nums. More formally, if there are k elements after removing the duplicates, then the first k elements of nums should hold the final result. It does not matter what you leave beyond the first k elements.

Return k after placing the final result in the first k slots of nums.

Do not allocate extra space for another array. You must do this by modifying the input array in-place with O(1) extra memory.

## First approach

Code for a generic max\_n, not just 2.

'''
int removeDuplicates(int* nums, int numsSize) {
   int j = 1; 
   int last_element = nums[0];
   int ctr = 1;
   int max_n = 2;
   for(int i = 1; i < numsSize; i++){
        if(nums[i] == last_element){
            ctr++;
            if(ctr<=max_n){
                nums[j] = nums[i];
                j++;
            }
        }else{
                nums[j] = nums[i];
                j++;
                last_element = nums[i];
                ctr = 1;
        }
   }
   return j;
}

'''

## Second approach

I probably should exploit the fact that it's only 2 positions. 

"""
int removeDuplicates(int* nums, int numsSize) {

    if (numsSize < 3)
        return numsSize;

    int j = 2;

    for(int i = 2; i < numsSize; i++){
        if(nums[i] != nums[j-2]){
            nums[j] = nums[i];
            j++;
        }
    }

    return j;
}
"""
