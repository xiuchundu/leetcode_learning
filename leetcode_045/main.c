int jump(int* nums, int numsSize){
    int Maxposition = 0, step = 0, Curposition = 0, i;
    for(i = 0; i < numsSize-1; i++){
        Maxposition = Maxposition > (i+nums[i]) ? Maxposition : (i+nums[i]);
        if(i == Curposition){
            Curposition = Maxposition; 
            step++;
        }
    }
    return step;   
}