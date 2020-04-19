int reverse(int x){
    int y = 0;
    while(x!=0){
        int n = x % 10;
        if(y>INT_MAX / 10 || y<INT_MIN / 10){
            return 0;
        }
        y = y*10 + n;
        x = x / 10;
    }
    return y;
}