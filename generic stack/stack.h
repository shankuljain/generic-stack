//
//  stack.h
//  generic stack
//
//  Created by Shankul Jain on 18/02/15.
//  Copyright (c) 2015 Shankul Jain. All rights reserved.
//

#ifndef __generic_stack__stack__
#define __generic_stack__stack__

typedef struct{
    int logilength;
    int alloclength;
    int elemsize;
    void *elem;
    void (*freefn)(void *);
}stack;

void stackNew(stack *s, int size, void (*freefn)(void *));
void stackDispose(stack *s);
void stackPush(stack *s, void *elemaddr);
void stackPop(stack *s, void *elemaddr);

#endif /* defined(__generic_stack__stack__) */
