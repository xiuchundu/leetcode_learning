char * longestPalindrome(char * s){
    //中心扩散法
    if(strlen(s)==0||strlen(s)==1)
        return s;
    int i,start,left,right,count,len;
    start = len =0;

    for(i=0;s[i]!='\0';i+=count){
        count = 1;
        left=i-1;
        right = i+1;
        //从第0个元素的右边查找重复的字符串，遇到和s[i]相等的移动+1，直到遇到不相同的/字符串结束停止
        while(s[right]!='\0'&&s[i]==s[right]){ //处理重复字符串
            right++;
            count++;
        } 
    
        //左右扩散，如果左边和右边相等，right++，left--
        while(left>=0 && s[right]!='\0' && s[left] == s[right]){
            left--;
            right++;
        }

        if(right-left-1>len){
            start = left+1;
            len = right-left-1; //更新最长回文串的长度
        }
    }

    s[start + len] = '\0'; // 原地修改返回
    return s + start;
}