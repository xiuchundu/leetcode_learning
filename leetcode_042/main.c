int trap(int* height, int heightSize){
    int water=0;
    int water_level=0;
    int max = 0;
    int max_index = 0;
    int i=0;

    // 获取最大值
    for(i=0; i<heightSize; i++){
        if(height[i] > max){
            max_index = i;
            max = height[i];
        }
    }

    for(i=0; i<max_index; i++){
        if(height[i]>water_level){
            water_level = height[i];
        }

        water += water_level - height[i];
    }

   water_level=0;

    for(i=heightSize-1; i>max_index; i--){
        if(height[i]>water_level){
            water_level = height[i];
        }
    
        water += water_level - height[i];
    }

    return water;
}