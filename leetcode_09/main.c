bool isPalindrome(int x){
    if(x < 0){
        return false;
    } 
    if(x == 0){
        return true;
    } 

    int i = 0;
    int a[100] = {'\0'};
    while(x!=0){
        a[i++] = x % 10;
        x = x / 10;
    }

    bool flag = true;
    for(int j=0; j< i/2; j++){
        if(a[j] != a[i-j-1]){
            flag = false;
            break;
        }
    }
    return flag;
}