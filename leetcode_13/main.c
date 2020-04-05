int roman_To_Integer(char c){
    switch(c){
        case 'I': 
            return 1;
        case 'V': 
            return 5;
        case 'X': 
            return 10;
        case 'L': 
            return 50;
        case 'C': 
            return 100;
        case 'D': 
            return 500;
        case 'M': 
            return 1000;
        default:
            return;
    }
}


int romanToInt(char * s){
    int len = strlen(s);
    int res=roman_To_Integer(s[0]);
    for(int i=1;i<len;i++){
        int prev = roman_To_Integer(s[i-1]);
        int cur = roman_To_Integer(s[i]);
        if(prev < cur){
            res = res - prev + (cur - prev);
        }
        else{
            res = res + cur;
        }
    }
    return res;
}