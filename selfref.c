#include <stdio.h>

struct S1 {
    char *s;
    int i;
    struct S1 *s1p;
};

int main(){
    static struct S1 a[ ]= {
        {"abcd", 1, a+1},
        {"efgh, 2, a+2"},
        {"ijkl", 3, a}
    };
    struct S1 *p = a;
    int i;

    printf("%s %s %s\n", a[0].s, p->s,a[2].s1p->s);

    for (i=0; i<2; i++)
    {
        printf("%d\n", --a[i].i);
       // printf("%c\n", ++a[i].s[3]);
    }

}