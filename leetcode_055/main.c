int getMax(int a, int b){
    return a > b ? a : b;
}


bool canJump(int* nums, int numsSize){
    int max =0;
    int i;
    for(i=0; i<numsSize; i++){
        if(i>max){
            return false;
        }

        max = getMax(i+nums[i], max);
    }

    return true;
}