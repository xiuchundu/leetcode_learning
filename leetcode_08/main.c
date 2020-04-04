int myAtoi(char* str) {
    long ret = 0;
    int flag = 1;//默认正数
    //去除空格及判断符号位
    for (; *str == 32; str++);
    switch (*str) {
    case 45:
        flag = -1;
    case 43:
        str++;
    }
    //排除非数字的情况
    if (*str < 48 || *str>57) return 0;
    
    while (*str >= 48 && *str <= 57) {
        ret = ret * 10 + (*str - 48);
        //判断溢出
        if ((int)ret != ret) {
            return (flag == 1) ? (INT_MAX) : (INT_MIN);
        }
        str++;
    }
    ret *= flag;
    return (int)ret;
}
