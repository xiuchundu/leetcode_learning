char *longestCommonPrefix(char ** strs, int strsSize){
    if (strsSize <= 0) {
        return "";
    }

    char *ans = strs[0];
    int i, j;
    for (i=1; i < strsSize; ++i) {
        j= 0;
        for (; ans[j] != '\0' && strs[i][j] != '\0'; j++) {
            if (strs[i][j] != ans[j]) {
                break;
            }

        }
        ans[j] = '\0';
        if (ans == NULL) {
            return "";
        }
    }
    return ans;
}
