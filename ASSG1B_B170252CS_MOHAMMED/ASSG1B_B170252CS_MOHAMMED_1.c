#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
FILE *fin, *fout;

typedef struct Node
{
    char ch;
    int freq;
    struct Node *left, *right;
} Node;

Node *newnode(char ch, int freq)
{
    Node *newi = (Node *)malloc(sizeof(Node));
    newi->ch = ch;
    newi->freq = freq;
    newi->left = newi->right = NULL;
    return newi;
}

Node **insert(Node **Tree, int *size, char ch, char freq, Node *l, Node *r)
{
    Node *newi = newnode(ch, freq);
    Tree[*size] = newi;
    int j = *size - 1;
    while (j >= 0 && ((newi->freq < Tree[j]->freq) || ((newi->freq == Tree[j]->freq) && (newi->ch != '$') && (Tree[j]->ch == '$' || (newi->ch < Tree[j]->ch)))))
    {
        Tree[j + 1] = Tree[j];
        j--;
    }
    newi->left = l;
    newi->right = r;
    Tree[j + 1] = newi;
    *size = *size + 1;
    return Tree;
}

Node *Min;
Node **Extractmin(Node **Tree, int *size)
{
    Min = Tree[0];
    for (int i = 0; i < (*size-1); i++)
        Tree[i] = Tree[i+1];
    *size = *size - 1;
    return Tree;
}

Node **find_tree(char *str)
{
    int i = 0, length = strlen(str);
    int freq[26] = {0};
    for (i = 0; i < length; i++)
        freq[str[i] - 'a']++;
    Node **Tree = (Node **)malloc(sizeof(Node *) * 1000);
    int size = 0;
    for (i = 0; i < 26; i++)
        if (freq[i])
            Tree = insert(Tree, &size, i + 'a', freq[i], NULL, NULL);
    // for (i = 0; i < size; i++)
        // printf("%c %d\n", Tree[i]->ch, Tree[i]->freq);
    while (size != 1)
    {
        Tree = Extractmin(Tree, &size);
        Node *min1 = Min;
        Tree = Extractmin(Tree, &size);
        Node *min2 = Min;
        //printf("Min1 %c %d , Min2 %c %d :: %c %d\n", min1->ch, min1->freq, min2->ch, min2->freq, '$', min1->freq + min2->freq);
        Tree = insert(Tree, &size, '$', min1->freq + min1->freq, min1, min2);
    }
    //printf("\n");
    return Tree;
}

char Code[26][100];
void print(Node *temp, char *code)
{
    if (temp->left == NULL && temp->right == NULL)
    {
        // printf("char %c code %s\n",temp->ch,code);
        strcpy(Code[temp->ch - 'a'], code);
        return;
    }
    int length = strlen(code);
    char leftcode[100], rightcode[100];
    strcpy(leftcode, code);
    strcpy(rightcode, code);
    leftcode[length] = '0';
    leftcode[length + 1] = '\0';
    rightcode[length] = '1';
    rightcode[length + 1] = '\0';
    print(temp->left, leftcode);
    print(temp->right, rightcode);
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
    char str[1000];
    while (!feof(fin))
    {
        fscanf(fin, "%s\n", str);
        // printf("%s\n", str);
        Node **Root = find_tree(str);
        char code[10] = "\0";
        print(Root[0],code);
        for (int i = 0; str[i]; i++)
            fprintf(fout,"%s ", Code[str[i] - 'a']);
        fprintf(fout,"\n");
    }
    return 0;
}