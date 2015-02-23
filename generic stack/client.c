//
//  client.c
//  generic stack
//
//  Created by Shankul Jain on 18/02/15.
//  Copyright (c) 2015 Shankul Jain. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"

void freefn(void *a){
    free(*(char **)a);
}

int main(int argc, const char * argv[]) {
    
    const char *name[] = {"shankul","jain"};
    stack stringstack;
    stackNew(&stringstack, sizeof(char *), freefn);
    
    for (int i=0; i<2; i++) {
        char *string = strdup(name[i]);
        stackPush(&stringstack, &string);
    }
    
    char *names;
    for (int i=0; i<2; i++) {
        stackPop(&stringstack, &names);
        printf("%s\n",names);
        free(names);
    }
    stackDispose(&stringstack);
    
    
}
