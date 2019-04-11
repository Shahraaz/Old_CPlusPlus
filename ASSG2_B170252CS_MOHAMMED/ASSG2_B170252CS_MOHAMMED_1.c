#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int hash_table[100000], occupied[100000], Deleted[100000];
int hash_size, c1, c2, r;

int find_Prime(int m)
{
    int i, j, flag = 0;
    for (i = m - 1; i >= 2; i--)
    {
        flag = 0;
        for (j = 2; j * j <= (m); j++)
        {
            if (i % j == 0)
            {
                flag = 1;
                break;
            }
        }
        if (!flag)
            return i;
    }
    return 2;
}

typedef struct node
{
    struct node *next;
    int real;
} node;
node *Hash_Chain[100000];

void insert_chain(int index)
{
    int k = index % hash_size;
    node *temp = malloc(sizeof(node));
    temp->next = NULL;
    temp->real = index;
    node *it = Hash_Chain[k];
    if (it == NULL)
        Hash_Chain[k] = temp;
    else
    {
        while (it->next != NULL)
        {
            if (it->real == index)
                return;
            it = it->next;
        }
        it->next = temp;
    }
}

int search_chain(int index)
{
    int k = index % hash_size;
    node *temp = Hash_Chain[k];
    while (temp != NULL)
    {
        if (temp->real == index)
            return 1;
        temp = temp->next;
    }
    return -1;
}

void delete_chain(int index)
{
    int k = index % hash_size;
    node *temp = Hash_Chain[k], *prev = NULL;
    while (temp != NULL)
    {
        if (temp->real == index)
            if (!prev){
                prev->next = temp->next;
                Hash_Chain[k] = temp->next;
            }
        prev = temp->next;
        temp = temp->next;
    }
    Hash_Chain[k] = temp;
}

void print_chained()
{
    for (int i = 0; i < hash_size; i++)
    {
        printf("%d (", i + 1);
        node *temp = Hash_Chain[i];
        while (temp != NULL)
        {
            printf("%d ", temp->real);
            temp = temp->next;
        }
        printf(")\n");
    }
}

int find_empty(int key, int s, int i)
{
    int index = 0;
    switch (s)
    {
    case 0:
        index = (key + i) % hash_size;
        break;
    case 1:
        index = (key + c1 * i + c2 * i * i) % hash_size;
        break;
    case 2:
        index = (key % hash_size + i * (r - key % r) + hash_size) % hash_size;
        break;
    }
    if (!occupied[index] || hash_table[index] == key)
        return index;
    return find_empty(key, s, i + 1);
}

void insert(int key, int s)
{
    int index;
    if (s == 3)
        insert_chain(key);
    else
    {
        index = find_empty(key, s, 0);
        occupied[index] = 1;
        Deleted[index] = 0;
        hash_table[index] = key;
    }
}

int search(int key, int s, int i)
{
    int index;
    if (s == 3)
        return search_chain(key);
    else
    {
        switch (s)
        {
        case 0:
            index = (key + i) % hash_size;
            break;
        case 1:
            index = (key + c1 * i + c2 * i * i) % hash_size;
            break;
        case 2:
            index = (key % hash_size + i * (r - key % r) + hash_size) % hash_size;
            break;
        }
        // printf("hash_size %d index %d s %d key %d\n", hash_size, index, s, key);
        if (occupied[index] && hash_table[index] == key)
            return 1;
        if (!occupied[index] && !Deleted[index])
            return -1;
        return search(key, s, i + 1);
    }
    return -1;
}

void delete (int key, int s, int i)
{
    int index;
    if (s == 3)
        delete_chain(key);
    else
    {
        switch (s)
        {
        case 0:
            index = (key + i) % hash_size;
            break;
        case 1:
            index = (key + c1 * i + c2 * i * i) % hash_size;
            break;
        case 2:
            index = (key % hash_size + i * (r - key % r) + hash_size) % hash_size;
            break;
        }
        if (occupied[index] && hash_table[index] == key)
        {
            occupied[index] = 0;
            Deleted[index] = 1;
            return;
        }
        if (!occupied[index] && !Deleted[index])
            return;
        return delete (key, s, i + 1);
    }
    return;
}

void print(int s)
{
    if (s == 3)
        print_chained();
    else
    {
        for (int i = 0; i < hash_size; i++)
        {
            printf("%d (", i);
            if (occupied[i])
                printf("%d", hash_table[i]);
            printf(")\n");
        }
    }
}

int main()
{
    char ch;
    int key;
    FILE *fin, *fout;
    fin = fopen("input.txt", "r");
    fout = fopen("output.txt", "w");
    if (fin == NULL || fout == NULL)
        exit(0);
    fscanf(fin, "%c ", &ch);
    fscanf(fin, "%d\n", &hash_size);
    r = find_Prime(hash_size);
    int s = ch - 'a';
    if (s == 1)
    {
        fscanf(fin, "%d %d\n", &c1, &c2);
    }
    printf("%d %d\n", hash_size, s);
    while (!feof(fin))
    {
        ch = getc(fin);
        switch (ch)
        {
        case 'i':
            fscanf(fin, "%d\n", &key);
            // printf("i %d\n", key);
            insert(key, s);
            break;
        case 's':
            fscanf(fin, "%d\n", &key);
            // printf("s %d\n", key);
            printf("%d\n", search(key, s, 0));
            break;
        case 'd':
            fscanf(fin, "%d\n", &key);
            // printf("d %d\n", key);
            delete (key, s, 0);
            break;
        case 'p':
            // printf("p\n");
            print(s);
            break;
        case 't':
            return 0;
            break;
        }
    }
    return 0;
}
