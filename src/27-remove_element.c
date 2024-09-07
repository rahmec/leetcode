#include <stdio.h>

void swap(int *a, int* b){
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

int removeElement(int* nums, int numsSize, int val) {
    int k=numsSize-1;

    for(int i=0; i<numsSize; i++){
        if(nums[i] == val){
            while(k >= 1 && nums[k] == val){
                k --;
            }
    	    if(k>i){
	    	swap(&nums[i], &nums[k]);
	    	k --;
            }
        }
    }

    return numsSize-k;
}

int main() {
	int nums[] = {3,2,2,3,4};
	int val=3;
	int numsSize = sizeof(nums) / sizeof(nums[0]);
	removeElement(nums, numsSize, 3);
	for(int i=0; i < numsSize; i++){
		printf("%d", nums[i]);
	}
	return 0;
}
