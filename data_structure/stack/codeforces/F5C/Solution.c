// problem name: Longest Regular Bracket Sequence
// problem link: https://codeforces.com/problemset/problem/5/C
// contest link: https://codeforces.com/contest/5
// author: reyad
// time: (?)

#include<stdio.h>
#define MAX 1000002
 
struct st_bracket{
    char container[MAX];
    int top;
} bstack;
 
struct st_count{
    int container[MAX];
    int top;
} cstack;
 
int flash_bstack()  {
    bstack.top = 0; return 0;
}
int flash_cstack()  {
    cstack.top = 0; return 0;
}
//      PUSH
int bpush(char ch)  {
    bstack.container[bstack.top++] = ch;
    if(bstack.top == MAX)   return 1;
    return 0;
}
int cpush(int count)    {
    cstack.container[cstack.top++] = count;
    if(cstack.top == MAX)   return 1;
    return 0;
}
//      POP
char bpop() {
    if(bstack.top == 0) return 0;
    else return bstack.container[--bstack.top];
}
int cpop()  {
    if(cstack.top == 0) return -1;
    else return cstack.container[--cstack.top];
}
 
int longest_sequence()  {
    char arr[MAX], ch, tch, ttch, tttch;
    int i, count, count2;
    
    flash_bstack(); flash_cstack(); bpush('.');
    scanf("%s", arr);   i = 0;
    while(ch = arr[i++])    {
        if(ch == '(')   bpush(ch);
        else    {
            if((tch = bpop()) == '(')   {
                count = 2;
                if((ttch = bpop()) == '-')  count += cpop();
                else    bpush(ttch);
                cpush(count);   bpush('-');
            }
            else if(tch == '-') {
                if((ttch = bpop()) == '(')  {
                    count = cpop()+2;
                    if((tttch = bpop()) == '-') count += cpop();
                    else    bpush(tttch);
                    cpush(count);   bpush('-');
                }
                else    bpush(ttch);
            }
            else    bpush(tch);
        }
    }
    return 0;
}
 
int main()  {
    int max = 0, temp, num;
    longest_sequence();
    for(temp = cpop(), num = 1; temp!=-1; temp = cpop())    {
        if(temp>max)    {
                max = temp; num = 1;
        }
        else if(temp == max) num++;
    }
    printf("%d %d",max, num);
    return 0;
}
