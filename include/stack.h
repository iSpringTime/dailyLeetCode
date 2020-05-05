/******************************************************************************
 * Copyright (c) JingMingGroup All rights reserved.
-------------------------------------------------------------------------------
  File name     : stack.h
  Author        : iSpringTime
  Create        : 2020.05.05
  Description   : stack operation (demo)
******************************************************************************/


#ifndef  __STACK_H__
#define  __STACK_H__

typedef char DataType;
typedef struct node{
    DataType data;
    struct node * next;
}Stack;

static inline Stack* CreateStack();               //创建栈
static inline void StackEmpty(Stack* );           //清空栈
static inline void DestoryStack(Stack*);          //撤销(删除)栈
static inline int IsStackEmpty(Stack*);           //判空
static inline int PushStack(Stack*, DataType);    //入栈
static inline int PopStack(Stack*);               //出栈
static inline DataType GetTopElement(Stack*);     //取栈顶元素

/*
    一个基于链表实现的栈的简单例子，没有做逆向增长，固定长度等限制。此外，利用数组等也可实现栈。
    仅用来演示栈先进后出的原理。第一个元素存储在 stack->next 中
*/

#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

//创建栈，此时栈中没有任何元素
static inline Stack* CreateStack()
{
    Stack *stack = (Stack*)malloc(sizeof(Stack));
    if(NULL != stack)
    {
        stack->next = NULL;
        return stack;
    }
    printf("out of place.\n");
    return NULL;
}

//清空栈
static inline void StackEmpty(Stack* stack)
{
    while(!IsStackEmpty(stack))
    {
        PopStack(stack);
    }
    printf("now stack is empty. \n");
}

//撤销栈
static inline void DestoryStack(Stack* stack)
{
    free(stack);
    printf("now stack is destoryed. \n");
    exit(0);
}

static inline int IsStackEmpty(Stack* stack)
{
    return (stack->next == NULL);
}

//入栈，成功返回1，失败返回0， 把元素 data 存入 栈 stack 中
static inline int PushStack(Stack* stack, DataType data)
{
    Stack* newst = (Stack*)malloc(sizeof(Stack));
    if(NULL != newst)
    {
        newst->data = data;
        newst->next = stack->next;  //s->next = NULL;
        stack->next = newst;
        return 1;
    }
    printf("out of place PushStack.\n");
    return 0;
}

/*
    出栈，成功返回1，失败返回0，出栈不取出元素值，只是删除栈顶元素。
    如出栈要实现，取出元素值，并释放空间，可结合取栈顶元素函数做修改，这里不再给出。
 */
static inline int PopStack(Stack* stack)
{
    Stack* tmpst;
    if(!IsStackEmpty(stack))
    {
        tmpst = stack->next;
        stack->next = tmpst->next;
        free(tmpst);
        return 1;
    }
    return 0;
}

//取栈顶元素，仅取出栈顶元素的值，取出之后，该元素，任然存在栈中。成功返回元素值，失败输出提示信息，并返回 -1
static inline DataType GetTopElement(Stack* stack)
{
    if(!IsStackEmpty(stack))
    {
        return stack->next->data;
    }
    printf("stack is empty GetTopElement.\n");
    return -1;
}


#endif