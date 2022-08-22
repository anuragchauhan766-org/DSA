#include <stdio.h>
#include <stdlib.h>
struct adtarray
{
    int max_size;
    int used_size;
    int *ptr;
};
void creatarray(struct adtarray *a, int tsize, int usize)
{
    a->max_size = tsize;
    a->used_size = usize;
    a->ptr = (int *)malloc(tsize * sizeof(int));
}
void setval(struct adtarray *a)
{
    for (int i = 0; i < a->used_size; i++)
    {
        printf("enter the element %d", i);

        scanf("%d", &(a->ptr)[i]);
    }
}
void show(struct adtarray *a)
{
    for (int i = 0; i < a->used_size; i++)
    {
        printf("%d\n", (a->ptr)[i]);
    }
}
int main()
{
    struct adtarray value;
    creatarray(&value, 10, 3);
    setval(&value);
    show(&value);

    return 0;
}