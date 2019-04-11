#include<stdio.h>
#include<stdlib.h>
#include<string.h>
FILE *fin,*fout;
char* remover(char* text)
{
	int i,length = strlen(text),j;
	i = j = 0;
//	printf("%d\n",length);
	for(i=0;i<length;i++)
		if((text[i]<='Z' && text[i]>='A' )|| (text[i]==' '))
			text[j++] = text[i];
	text[j] = '\0';
	return text;
}
const int d = 256;
void search(char *pat, char *txt, int q) 
{ 
//	fprintf(fout,"search\n%s\n",pat);
//	fprintf(fout,"%s\n",txt);
    int M = strlen(pat); 
    int N = strlen(txt); 
    int i, j; 
    int p = 0;
    int t = 0; 
    int h = 1,flag = 0; 
    for (i = 0; i < M-1; i++) 
        h = (h*d)%q; 
    for (i = 0; i < M; i++) 
    { 
        p = (d*p + pat[i])%q; 
        t = (d*t + txt[i])%q; 
    }   
    for (i = 0; i <= N - M; i++) 
    { 
        if ( p == t ) 
        { 
            for (j = 0; j < M; j++) 
            { 
                if (txt[i+j] != pat[j]) 
                    break; 
            } 
            if (j == M) {
                fprintf(fout,"%d ", i);
			flag = 1;
		} 
        } 
        if ( i < N-M ) 
        { 
            t = (d*(t - txt[i]*h) + txt[i+M])%q; 
            if (t < 0) 
            t = (t + q); 
        } 
    }
	if(!flag)
	        fprintf(fout,"-1"); 
	fprintf(fout,"\n");
} 
int main()
{
	fin = fopen("input.txt","r");	
	fout = fopen("output.txt","w");	
	if(fin==NULL || fout== NULL)
		return 0;
	int q = 101;
	char *text,*Pat,Choice[5];
	text = (char*)malloc(1000);
	Pat = (char*)malloc(1000);
	while(!feof(fin))
	{
		fscanf(fin,"%s ",Choice);
		if(strlen(Choice)==2)
			Choice[0] = 'r';
		switch(Choice[0])
		{
			case 't' : 
				fscanf(fin,"%[^\n]s",text);
				//fprintf(fout,"TEXT %s\n",text);
				text = remover(text);
				//fprintf(fout,"TEXT %s\n",text);
				break;
			case 'p' : 
				fscanf(fin,"%[^\n]s",Pat);
				//fprintf(fout,"Pat %s\n",Pat);
				Pat = remover(Pat);
				//fprintf(fout,"Pat %s\n",Pat);
				break;
			case 'r' : 
				search(Pat,text,101);
				break;
			case 'e' :
				return 0;
		}	
	}
	return 0;
}