#include <stdio.h>
#include <stdbool.h>

bool backspaceCompare(char * S, char * T);

int main() {
    char *s1 = "ab#c";
    char *t1 = "ad#c";
    char *s2 = "ab##";
    char *t2 = "c#d#";
    char *s3 = "a##c";
    char *t3 = "#a#c";
    char *s4 = "a#c";
    char *t4 = "b";
    char *s5 = "xywrrmp";
    char *t5 ="xywrrmu#p";
    int ret = 0;

    ret = backspaceCompare(s1, t1);
    printf("ret:%d.\n", ret);
    ret = backspaceCompare(s2, t2);
    printf("ret:%d.\n", ret);
    ret = backspaceCompare(s3, t3);
    printf("ret:%d.\n", ret);
    ret = backspaceCompare(s4, t4);
    printf("ret:%d.\n", ret);
    ret = backspaceCompare(s5, t5);
    printf("ret:%d.\n", ret);

    return 0;
}


