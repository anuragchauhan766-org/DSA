#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main()
{

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    char s[1000];
    scanf("%s", s);
    int i = 0;
    int a1 = 0, a2 = 0, a3 = 0, a4 = 0, a5 = 0, a6 = 0, a7 = 0, a8 = 0, a9 = 0, a0 = 0;

    while (s[i] != '\0')
    {
        if (s[i] == '0')
        {
            a0++;
        }
        if (s[i] == '1')
        {
            a1++;
        }
        if (s[i] == '2')
        {
            a2++;
        }
        if (s[i] == '3')
        {
            a3++;
        }
        if (s[i] == '4')
        {
            a4++;
        }
        if (s[i] == '5')
        {
            a5++;
        }
        if (s[i] == '6')
        {
            a6++;
        }
        if (s[i] == '7')
        {
            a7++;
        }
        if (s[i] == '8')
        {
            a8++;
        }
        if (s[i] == '9')
        {
            a9++;
        }
        i++;
    }
    printf("%d %d %d %d %d %d %d %d %d %d", a0, a1, a2, a3, a4, a5, a6, a7, a8, a9);
    return 0;
}
