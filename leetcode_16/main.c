int comp(const void *a, const void *b){
    return *(int *)a - *(int *)b;
}

int threeSumClosest(int* nums, int numsSize, int target){
    int cur, right, result;
    
    right = numsSize - 1;

    qsort(nums, numsSize, sizeof(int), comp);
    result = nums[0] + nums[1] + nums[2];
    for(int k = 0; k < numsSize - 2; k++){
        cur = k + 1;
        right = numsSize - 1;
        while(cur < right){
            if (abs(target - result) > abs(target - (nums[k] + nums[cur] + nums[right]))){
                result = nums[k] + nums[cur] + nums[right];
            }
            
            if((nums[k] + nums[cur] + nums[right]) > target){
                right--; 
            } else{
                cur++;
            }
        }
    }

    return result;
}