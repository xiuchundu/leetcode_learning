/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* searchRange(int* nums, int numsSize, int target, int* returnSize){
    int low, mid, height, first, last, cur=-1, flag = 0;
    int *res = malloc(sizeof(int) *  2);
    memset(res, -1, sizeof(int)*2);
    low = 0;
    height = numsSize - 1;
    *returnSize = 2;
    if(numsSize==0 || nums[0] > target || nums[numsSize-1] < target){
        return res;
    }

    while(low<=height){
        mid = (low+height) / 2;
        if(nums[mid] == target){
            cur = mid;
            break;
        }

        if(nums[mid] < target){
            low = mid + 1;
        } else{
            height = mid - 1;
        }
    }

    if(cur==-1){
        return res;
    }else{
        first = cur;
        last = cur;
    }

    while(nums[first] == target || nums[last]==target){
        if(nums[first] == target && first > 0){
            first--;
            flag++;
        }
        if(nums[last] == target && last < numsSize-1){
            last++;
            flag++;
        }

        if(flag==0){
            break;
        }else{
            flag=0; //判断 有无加减，防止死循环
        }
    }

    if(nums[first]!=target && first>=0){
        first++; //找到第一个为target的位置
    }

    if(nums[last]!=target && last>0){
        last--;//找到最后一个为target的位置
    }

    res[0] = first;
    res[1] = last;
    return res;
}