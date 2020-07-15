int max(int a, int b){
    return a > b ? a : b;
}

int maxSubArray(int* nums, int numsSize){
    int i, result;
    int *dp = NULL;

    dp = malloc(sizeof(int) * numsSize);
    dp[0] = nums[0];
    result = dp[0];
    for(i=1; i<numsSize; i++){
        dp[i] = max(dp[i-1] + nums[i], nums[i]);
        result = max(dp[i], result);
    }

    return result;
}