#include <stdio.h>
#include <string.h>

#define MAX 300

int t[MAX];
void shiftable(char p[])
{
    int m, i, j;

    m = strlen(p);

    for (i = 0; i < MAX; i++)
    {
        t[i] = m;
    }

    for (j = 0; j < m - 1; j++)
    {
        t[p[j]] = m - 1 - j;
    }
}

int horspool(char s[], char p[])
{
    int i, n, m, k;

    n = strlen(s);
    m = strlen(p);
    i = m - 1;
    while (i < n)
    {
        k = 0;
        while ((k < m) && (p[m - 1 - k] == s[i - k]))
            k++;

        if (k == m)
            return i - m + 1;
        else
            i = i + t[s[i]];
    }

    return -1;
}
int main(void)
{
    char text[MAX];
    char pattern[MAX];
    int found;
    puts("text pl;s ");
    fgets(text, MAX, stdin);
    puts("pattern plis ");
    fgets(pattern, MAX, stdin);

    shiftable(pattern);
    found = horspool(text, pattern);

    if (found == -1)
        printf("oops");
    else
        printf("pos,  %d", found + 1);

    return 0;
}
