#include "string.h"
#include <stdio.h>
#include <stdbool.h>
#include "stdlib.h"
#include "stack.h"

char * calStr(Stack *stack, int strNum)
{
    int i = 0;
    char *outPut = NULL;

    outPut = (char*) malloc(sizeof(char) * strNum);
    memset(outPut,0,strNum+1);

    while (!IsStackEmpty(stack)) {
        outPut[i++] = GetTopElement(stack);
        PopStack(stack);
    }
    return outPut;

}

void findStr(char *s, char **outPut)
{

    Stack *stackPst = NULL;
    int i = 0;
    int num = 0;

    if (s == NULL) {
        return;
    }

    stackPst = CreateStack();
    while (s[i] != '\0') {
        if (s[i] != '#') {
            PushStack(stackPst, s[i]);
            i++;
            num++;
            continue;
        }
        if (IsStackEmpty(stackPst) != 1) {
            PopStack(stackPst);
        }
        i++;
    }

    *outPut = calStr(stackPst, num);
}

bool backspaceCompare(char * S, char * T){
    char **s = NULL;
    char **t = NULL;
    int ret = 0;

    if (S == NULL) {
        return false;
    }

    s = (char **)malloc(sizeof(char*));
    t = (char **)malloc(sizeof(char*));
    memset(s, 0, sizeof(s));
    memset(t, 0, sizeof(t));

    findStr(S, s);
    findStr(T, t);

    if ((s == NULL) && (t == NULL)) {
        return 1;
    }
    ret = strcmp(*s, *t);
    if (!ret) {
        ret = ~ret;
    } else {
        ret = 0;
    }
    free(s);
    free(t);

    return ret;
}
