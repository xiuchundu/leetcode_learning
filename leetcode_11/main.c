int getRectangle(int x, int y){
    return x * y;
}

int comp(int x, int y){
    if (x >= y) {
        return y;
    } else {
        return x;
    }
}

int comp1(int x, int y){
    if (x >= y) {
        return x;
    } else {
        return y;
    }
}


//解法1，双指针
int maxArea1(int* height, int heightSize){
    if (heightSize <= 1) {
        return 0;
    }

    int maxAr = 0;
    int curArea = 0;

    for(int i = 0 ; i < heightSize - 1; i++){
        for(int j = i + 1; j < heightSize; j++){
            curArea = getRectangle((j - i), comp(height[i], height[j]));
            if (maxAr <= curArea){
                maxAr = curArea;
            }
        }
    }

    return maxAr;
}


//解法2，两边向中间夹,效率更高
int maxArea(int* height, int heightSize){
    if (heightSize <= 1) {
        return 0;
    }

    int maxAr = 0;
    int curArea = 0;
    int left = 0;
    int right = heightSize - 1;

    while(left <= right){
        maxAr = comp1(maxAr, getRectangle((right - left), comp(height[left], height[right])));
        if (height[left] < height[right]){
            left++;
        } else{
            right--;
        }
    }

    return maxAr;
}