// problem name: Discover the Web
// problem link: http://lightoj.com/volume_showproblem.php?problem=1113
// contest link: (?)
// time: (?)
// author: reyad

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 110
#define UMAX 60
 
struct st_stack {
    char *buf[MAX];
    int top;
};
typedef struct st_stack __stack;
 
__stack *create_stack() {
    __stack *ps = (__stack *) malloc(sizeof(__stack));
    ps->top = 0;
    return ps;
}
void push(__stack *ps, char *str) {
    ps->buf[(ps->top)++] = str;
}
char *pop(__stack *ps) {
    if(ps->top == 0) return NULL;
    return ps->buf[--(ps->top)];
}
void stack_flush(__stack *ps) {
    while(ps->top != 0) {
        free(ps->buf[--(ps->top)]);
    }
}
 
int main() {
    int i, tc;
    char *pu, *tu, command[6];
    __stack *f, *b;
   
    b = create_stack();
    f = create_stack();
    scanf("%d", &tc);
    i = 0;
    while(i < tc) {
        printf("Case %d:\n", i+1);
        pu = (char *)malloc(UMAX * sizeof(char));
        strcpy(pu, "http://www.lightoj.com/");
       
        scanf("%s", command);
        while(strcmp(command, "QUIT") != 0) {
            if(strcmp(command, "VISIT") == 0) {
                tu = (char *)malloc(UMAX * sizeof(char));
                scanf("%s", tu);
                push(b, pu);
                pu = tu;
                stack_flush(f);
                printf("%s\n", pu);
            }
            else if(strcmp(command, "BACK") == 0) {
                if(b->top == 0) {
                    printf("Ignored\n");
                }
                else {
                    push(f, pu);
                    pu = pop(b);
                    printf("%s\n", pu);
                }
            }
            else {
                if(f->top == 0) {
                    printf("Ignored\n");
                }
                else {
                    push(b, pu);
                    pu = pop(f);
                    printf("%s\n", pu);
                }
            }
            scanf("%s", command);
        }
        stack_flush(b);
        stack_flush(f);
        i++;
    }
    free(b);
    free(f);
    return 0;
}
