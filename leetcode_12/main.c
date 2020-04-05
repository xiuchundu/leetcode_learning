//我想用整除获得低位的方式完成。获得低位数
//字后，除4，5和9需要特殊处理以外，其它数字每输出一个该分位对应的单位
//一（个位对应“I”，十位对应“X”），就自减一，重复循环，0跳出循环。

//最后，为了最后顺序输出字符串，我们申请一个字符数组进行逆序存储。
//罗马数在3888时取得最长的15位，为了节省空间，我们申请一个16位的数组。
//https://leetcode-cn.com/problems/integer-to-roman/solution/
//zheng-shu-zhuan-luo-ma-shu-zi-di-wei-kai-shi-by-je/#comment
char * intToRoman(int num){
    char *ret = NULL;
    if(num < 0 || num > 3999){
        return ret;
    }
    ret = (char *)malloc(sizeof(char)*16);
    if(ret == NULL){
        exit(0);
    }
    
    
    ret[15] = 0;
    char Rome[] = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};
    int i = 14, j = 0, m = 0;

    while(num){
        m = num % 10;
        num = num / 10;
        while(1){
            if (m == 9) {ret[i--] = Rome[j+2]; m = 1;}
            else if (m == 8) {ret[i--] = Rome[j]; m--;}
            else if (m == 7) {ret[i--] = Rome[j]; m--;}
            else if (m == 6) {ret[i--] = Rome[j]; m--;}
            else if (m == 5) {ret[i--] = Rome[j+1]; break;}
            else if (m == 4) {ret[i--] = Rome[j+1]; m=1;}
            else if (m == 3) {ret[i--] = Rome[j]; m--;}
            else if (m == 2) {ret[i--] = Rome[j]; m--;}
            else if (m == 1) {ret[i--] = Rome[j]; break;}
            else break;
        }
        j += 2;
    }
    return (ret + i + 1);
}

/*******************************/
//解法2 散列表法
struct hash
{
    int interger;
    char roman[4];
}Hash[13] = {
    1000, "M",
    900,  "CM", 
    500,  "D", 
    400,  "CD",
    100,  "C",
    90,   "XC",
    50,   "L",
    40,   "XL",
    10,   "X",
    9,    "IX",
    5,    "V",
    4,    "IV",
    1,    "I",
};

char * intToRoman1(int num){
    char cRoman[16] = {0x0};
    char* pcRoman = cRoman;
    char* res = cRoman;
    unsigned short uIndex = 0;
    unsigned short uLength = 0;
    char a[16] = {0};
    char* p = a;

    for(uIndex = 0; uIndex <= (13-1); uIndex++)
    {
        while(num >= Hash[uIndex].interger)
        {
            num = num - Hash[uIndex].interger;
            strcat(cRoman, Hash[uIndex].roman);
        }
    }

    return pcRoman;
}