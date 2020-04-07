int isSubsequence(char * s, char * t){
    int length = strlen(t);
    int slength = strlen(s);
    int pos = 0;
    int isFind = 0;
    int i,j;

    if (slength == 0) {
        return 1;
    }

    if (length < slength) {
        return isFind;
    }

    for (i = 0;i < slength;i++) {
        for (j = pos;j < length;j++) {
            if (s[i] == t[j]) {
                pos = j + 1;
                isFind = 1;
                break;
            }
        }
        if (isFind == 0) {
            break;
        } else if (i != slength - 1) {
            isFind = 0;
        }
    }
    return isFind;
}