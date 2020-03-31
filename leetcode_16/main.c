int comp(const void *a, const void *b){
    return *(int *)a - *(int *)b;
}

int threeSumClosest(int* nums, int numsSize, int target){
    int cur, right, sum, result;
    
    right = numsSize - 1;

    qsort(nums, numsSize, sizeof(int), comp);
    result = nums[0] + nums[1] + nums[2];
    for(int k = 0; k < numsSize - 2; k++){
        cur = k + 1;
        right = numsSize - 1;
        while(cur < right){
            sum = nums[k] + nums[cur] + nums[right];
            if(sum == target) { //剪枝1，刚好相等提前返回
                return target;
            }
    
            int min = nums[k] + nums[cur] + nums[cur+1];  //剪枝2，提前返回
            if((target < min) && (abs(target - result) > abs(target - min))){
                result = min;
                break;
            }
            
            int max = nums[k] + nums[right-1] + nums[right]; //剪枝3，提前返回
            if((target > max) && (abs(target - result) > abs(target - max))){
                result = max;
                break;
            }
            
            if(abs(target - result) > abs(target - sum)){ //更新三数之和
                result = sum;
            }
            
            if(sum > target){ //双指针移动
                right--; 
            } else{
                cur++;
            }
        }
    }

    return result;
}