# Jump Game 2 (45)

## Description 

You are given a 0-indexed array of integers nums of length n. You are initially positioned at nums[0].

Each element nums[i] represents the maximum length of a forward jump from index i. In other words, if you are at nums[i], you can jump to any nums[i + j] where:

    0 <= j <= nums[i] and
    i + j < n

Return the minimum number of jumps to reach nums[n - 1]. The test cases are generated such that you can reach nums[n - 1].

## Reasoning

In this jump game I know for sure that I can reach the end.
One immediate way that come to my mind is starting from the end and analyzing each time I reached the further jump position that actually make arrive to the end.

What i mean is that there are jumps that make me go further.

Now i gotta take into account WHERE I fall.

Maybe I need to address from the end the furthest point that make 

At the end of the day it's only a matter of choosing jump by jump.

We only need to trasverse once, but keep track each time of the furthest jump, so we can choose that as the following checkpoint.
This actually also basically gives you the position you are jumping in, so giving an example of shortes path.

WAIT, I GOT IT, DIFFERENT THO.
WE TRASVERSE THE ARRAY, TAKE INTO ACCOUNT CURRENT REACHING POINT, THEN WHEN WE REACHED IT WE GO TO THE NEW REACHING POINT AND AGAIN, INCREASING EACH TIME BY 1.

## Code

int jump(int* nums, int numsSize) {

    int jumps = 0;
    int reachable_index = 0;
    int current_reachable_index = 0;

    for(int i=0; i<numsSize - 1; i++){

        if(i + nums[i] > reachable_index){
            reachable_index = i + nums[i];
            if(reachable_index >= numsSize - 1){
                jumps++;
                break;
            }
        }

        if(i==current_reachable_index){
            jumps++;
            current_reachable_index = reachable_index;
        }
    }
    return jumps;
}

