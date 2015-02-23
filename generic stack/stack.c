//
//  stack.c
//  generic stack
//
//  Created by Shankul Jain on 18/02/15.
//  Copyright (c) 2015 Shankul Jain. All rights reserved.
//

#include "stack.h"
#include <stdlib.h>
#include <assert.h>
#include <string.h>


static void stackGrow(stack *s){
    s->alloclength *= 2;
    s->elem = realloc(s->elem, s->alloclength*s->elemsize);
}

void stackNew(stack *s, int size, void (*freefn)(void *)){
    s->alloclength = 4;
    s->logilength = 0;
    s->elemsize = size;
    s->freefn = freefn;
    s->elem = malloc(4*size);
    assert(s->elem != NULL);
}

void stackDispose(stack *s){
    if (s->freefn != NULL) {
        for (int i =0; i<s->logilength; i++) {
            s->freefn((char *)s->elem + i*s->elemsize);
        }
    }
    
    free(s->elem);
}

void stackPush(stack *s, void *elemaddr){
    if (s->logilength == s->alloclength ) {
        stackGrow(s);
    }
    
    void *target = (char *)s->elem + s->logilength*s->elemsize;
    memcpy(target, elemaddr, s->elemsize);
    s->logilength++;
    
}

void stackPop(stack *s, void *elemaddr){
    s->logilength--;
    void *source = (char *)s->elem + s->logilength*s->elemsize;
    memcpy(elemaddr, source, s->elemsize);
    
}