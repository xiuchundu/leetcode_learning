int lengthOfLastWord(char * s){
    int len = strlen(s), lastWordLen = 0;
    if (len == 0) return 0;

    for (int i = len - 1; i >= 0; i--) {
        if (s[i] != ' ') lastWordLen++;
        if (s[i] == ' ' && lastWordLen > 0) break;
    }

    return lastWordLen;
}