# Remove Element(27)
Given an integer array nums and an integer val, remove all occurrences of val in nums in-place. The order of the elements may be changed. Then return the number of elements in nums which are not equal to val.

Consider the number of elements in nums which are not equal to val be k, to get accepted, you need to do the following things:

- Change the array nums such that the first k elements of nums contain the elements which are not equal to val. The remaining elements of nums are not important as well as the size of nums.
- Return k.

## Primo approccio

Swappiamo. Batte solo 30%.

'''
void swap(int* array, int i1, int i2){
    int temp = array[i1];
    array[i1] = array[i2];
    array[i2] = temp;
}

int removeElement(int* nums, int numsSize, int val) {
    int k = numsSize - 1;
    int i = 0;
    int non_val = 0;

    while(i<=k){
        if(nums[i]==val){
            while(k>=0 && nums[k]==val){
                k--;
            }
            if(k != -1 && k > i){
                swap(nums,i,k);
                non_val++;
            }
        }else{
            non_val++;
        }
        i++;
    }

    return non_val;
}
'''

## Secondo approccio

Copiamo solo a sinistra! (Batte 100%)

"""
int removeElement(int* nums, int numsSize, int val) {
    int k = numsSize - 1;
    int i = 0;
    int non_val = 0;

    while(i<=k){
        if(nums[i]==val){
            while(k>=0 && nums[k]==val){
                k--;
            }
            if(k >= 0 && k > i){
                nums[i] = nums[k--];
                non_val++;
            }
        }else{
            non_val++;
        }
        i++;
    }

    return non_val;
}

