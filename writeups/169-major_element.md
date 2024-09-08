# Major Element (169)

Given an array nums of size n, return the majority element.

The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.

## First approach

Code:

"""
int majorityElement(int* nums, int numsSize) {

    int elements[numsSize][2];
    int unique_elements = 0;

    if(numsSize == 1){
        return nums[0];
    }

    // Count them all (sigh)
    for (int i=0; i<numsSize; i++){
        bool found = false;
        for (int j=0; j < unique_elements; j++){
            if(elements[j][0] == nums[i]){
                found = true;
                elements[j][1] += 1;
                if(elements[j][1] >= ((numsSize+1) / 2)){
                    return nums[i];
                }
            }
        }
        if(!found){
            elements[unique_elements][0] = nums[i];
            elements[unique_elements][1] = 1;
            unique_elements++;
        }
    }

        for (int j=0; j < unique_elements; j++){
            printf("%d, %d", elements[j][0], elements[j][1]);
        }

    return -1;
}


// I want to solve it in linear time and O(1) space

// This means i have to trasverse it once and don't use any other array
// How can i keep track of how many times an array appears?
// Counting each numerosity till I find it it's stupid probably
// O(1) space means I can't even store numerosity
// Should i split?
// Should i recurse?
// How can i prove majority?

// I have in mind solutions with O(n) - O(n) or O(n^2) - O(1)
// But O(n) O(1) ...
// I just need to know i can
//  Let's just Implement it the normal way

// AAAAAH, it's majority, let's talk about some properties
// It's surely the most present in number in one of the two halves
// Still this involves counting them all
// It can't be something about the values (maybe transforming them into something...)
// Idk maybe transforming each value to a sum contribute of different value
// Interesting thing, this works with the most present value period (just use an array with ctrs at this point)

// This obviously can't involve sorting, it'd be crazy
"""

## Second approach

Althoug it seemed stupid initially, if i do use a majority candidate it will surely be mine at last, it's proved.
We can use boyer-moore algorithm.

"""
int majorityElement(int* nums, int numsSize) {
    int candidate;
    int boyer_moore_ctr = 0;

    for(int i = 0; i < numsSize; i++){
        if(boyer_moore_ctr == 0){
            candidate = nums[i];
            boyer_moore_ctr = 1;
        }
        else{
            if(nums[i] == candidate) boyer_moore_ctr++;
            else boyer_moore_ctr--;
        }
    }

    return candidate;
}
"""


