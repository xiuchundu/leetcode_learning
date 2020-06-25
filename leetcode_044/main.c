bool isMatch(char * s, char * p){
    int i, j, k;
    // dp[i][j]表示s截止到第i个位置(s[i-1])的子串与p截止到第j个位置(p[j-1])的子串是否匹配
    bool **dp = malloc(sizeof(bool *) * (strlen(s) + 1));
    for(i=0; i<=strlen(s); i++){
        dp[i] = malloc(sizeof(bool) * (strlen(p) + 1));
        memset(dp[i], false, (strlen(p) + 1)*sizeof(bool));
    }

    // dp[0][0]表示 空s 和 空p 匹配
    dp[0][0] = true;

    // for循环的开始条件是i=1,也就是没考虑 空s 的匹配情况，dp[0][0]只考虑了 空s匹配空p
    // 但 空s 也可以匹配 *,**,而且对于 *abc*, 空s的匹配情况可以简化
    // 这里对空s的匹配情况进行初始化
    for(j=1; j<=strlen(p); j++){
        if(p[j-1] == '*'){
            // s匹配*,相当于s匹配空；s匹配**相当于s匹配*；s匹配*cb*相当于s匹配*cb
            dp[0][j] = dp[0][j-1];
        }
    }

// 注意 i,j表示的是s和p中第几个字符，对应的索引索引是i-1,j-1
    for(i=1; i<=strlen(s); i++){
        for(j=1; j<=strlen(p); j++){
            // 根据模式串的当前位置的字符来分类讨论
            // 当前位置是 *
            // * 可以匹配任意字符包括空字符，所以考虑 dp[i-1][j-1],dp[i-1][j],dp[i][j-1]这前面已处理过的三个结果
            // 但其实 dp[i-1][j-1]不用考虑，因为考虑dp[i-1][j]时也会执行这个if，还是会考虑到dp[i-1][j-1]
            if(p[j-1] == '*'){
                dp[i][j] = dp[i-1][j] || dp[i][j-1];
            } else if((p[j-1] == '?') || (p[j-1] == s[i-1])){
                // 当前位置是 ？,可以匹配任意单个字符，所以和前一个位置结果一样
                // p当前位置字符和s当前字符一样，所以跟前一个位置匹配结果一样
                dp[i][j] = dp[i-1][j-1];
            }
        }
    }

    return dp[strlen(s)][strlen(p)];
}

#https://leetcode-cn.com/problems/wildcard-matching/solution/tong-pei-fu-pi-pei-by-leetcode/#comment