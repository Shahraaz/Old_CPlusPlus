#include <stdio.h>
#include <stdlib.h>
#include <math.h>
FILE *fin, *fout;
const int High = 1e9 + 7;

int mini(int a, int b)
{
    return (a < b) ? a : b;
}

int Dfs(int index, int size, int *Tree)
{
    if (index >= size)
        return High;
    return Tree[index] = mini(Tree[index], mini(Dfs(index * 2 + 1, size, Tree), Dfs(index * 2 + 2, size, Tree)));
}

int *maketree(int *arr, int n, int size)
{
    size = 1 << size;
    int *Tree = (int *)malloc(2 * size * sizeof(int));
    int i, start = size - 1;
    for (i = 0; i < size * 2; i++)
        Tree[i] = High;
    for (i = 0; i < n; i++)
        Tree[i + start] = arr[i];
    for (; i < size; i++)
        Tree[i + start] = High;
    Dfs(0, 2 * size, Tree);
    return Tree;
}

int find_Second(int *Tree)
{
    int curr = Tree[0];
    if (Tree[1] == curr)
    {
        if (Tree[3] == curr)
            return Tree[4];
        return Tree[3];
    }
    else
    {
        if (Tree[5] == curr)
            return Tree[6];
        return Tree[5];
    }
    return 0;
}

int main()
{
    fin = fopen("input.txt", "r");
    fout = fopen("output.txt", "w");
    if ((fin == NULL) || (fout == NULL))
    {
        printf("Unable to open files. Try again!!\n");
        return 0;
    }
    while (!feof(fin))
    {
        int arr[1000];
        char ch = '0';
        int cnt = 0, result = 0, flag = 0;
        while (ch != '\n' || !feof(fin))
        {
            ch = getc(fin);
            // printf("%c\n",ch);
            if (ch == '\n' || feof(fin))
            {
                if (flag)
                    arr[cnt++] = result;
                // printf("%d ",result);
                flag = 0;
                result = 0;
                break;
            }
            else if (ch == ' ')
            {
                if (flag)
                    arr[cnt++] = result;
                // printf("%d ",result);
                flag = 0;
                result = 0;
            }
            else if (ch <= '9' && ch >= '0')
            {
                result = result * 10 + (ch - '0');
                flag = 1;
            }
        }
        // printf("\ncount %d\n",cnt);
        int size = (int)ceil(log(cnt) / log(2));
        int *Tree = maketree(arr, cnt, size);
        fprintf(fout,"%d\n", find_Second(Tree));
    }
    return 0;
}