int removeDuplicates(int* nums, int numsSize){
    if(numsSize <= 1){
        return numsSize;
    }
    
    int i=0, j, cnt = 1;
    while(i<numsSize){
        for(j=i+1; j < numsSize && nums[i] == nums[j]; j++){
            
        }
        if(j<numsSize){
            nums[cnt++] = nums[j];
        }

        i = j;
    }
    return cnt;
}