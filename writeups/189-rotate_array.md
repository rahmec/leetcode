# 189 - Rotate Array

Given an integer array nums, rotate the array to the right by k steps, where k is non-negative.

E.g.

[1,2,3,4,5], k=3 -> [3,4,5,1,2]

## First approach

The first approach to this problem is just taking the last k mod numsSize positions putting them into the inital position.
This doesn't work in leetcode as this must be done inplace

"""
void rotate(int* nums, int numsSize, int k) {
     int new_array[numsSize];
     int rotation;

     for (int i=0; i<numsSize; i++){
        rotation = (i+k) % numsSize;
        new_array[rotation] = nums[i];
     }

     memcpy(nums, new_array, numsSize*sizeof(int));

}

"""

ma anche

"""
void rotate(int* nums, int numsSize, int k) {
     int new_array[numsSize];

     k = k % numsSize;

     memcpy(new_array, nums+(numsSize-k), k*sizeof(int));
     memcpy(new_array+k, nums, (numsSize-k)*sizeof(int));
     memcpy(nums, new_array, numsSize*sizeof(int));

}
"""

Soluzione interessante -> doppio reverse

reverse da 0 a n-k
reverse da n-k ad n
reverse di tutto
