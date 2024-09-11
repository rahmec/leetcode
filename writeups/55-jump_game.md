# Jump Game (55)

## Description

You are given an integer array nums. You are initially positioned at the array's first index, and each element in the array represents your maximum jump length at that position.

Return true if you can reach the last index, or false otherwise.

## Reasoning

bool canJump(int* nums, int numsSize) {
    int need = 1;

    for(int i = numsSize - 2 ; i>=0; i--){
        if(nums[i] >= need){
            need = 1;
        }else{
            need++;
        }
    }

    return need==1;

}


## Code 

'''
bool canJump(int* nums, int numsSize) {
    int need = 1;

    for(int i = numsSize - 2 ; i>=0; i--){
        if(nums[i] >= need){
            need = 1;
        }else{
            need++;
        }
    }
    if(need==1)
        return true;
    else
        return false;

}
'''

'''
bool canJump(int* nums, int numsSize) {

    if(numsSize<2){
        return true;
    }
    
    int reachable_position = 0;
    int current_position = 0;

    while(current_position <= reachable_position){
        if(reachable_position < (current_position + nums[current_position])){
                reachable_position = current_position + nums[current_position];
                if(reachable_position >= numsSize -1)
                    return true;
        }
        current_position++;
    }

    return false;
}

'''
'''
//Piccolo ma non si ferma prima
bool canJump(int* nums, int numsSize) {

    //int need = 1;
    int n = numsSize - 1;

    for(int i = numsSize - 2 ; i>=0; i--){
        if( n-i <= nums[i] )
            n=i;
    }

    return n==0;

}

'''
