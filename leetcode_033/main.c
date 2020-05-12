int search(int* nums, int numsSize, int target){
    int low = 0;
    int high = numsSize-1;

    if(numsSize==0){
        return -1;
    }

    while(low <= high){
        int mid = (low+high)/2;
        if(nums[mid] == target){
            return mid;
        }

        if(nums[low]<=nums[mid]){ //左边是有序的
            if(nums[low]<=target && nums[mid]>=target){
                high = mid-1; //目标值在左边
            }else{
                low = mid+1;
            }
        }

        else{ //右边有序
            if(nums[mid]<=target && nums[high]>=target){
                low = mid+1;//目标值在右边
            }else{
                high = mid-1;
            }
        }
    }

    return -1;
}