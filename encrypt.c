#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
int main(){
char *a,n[15];
int i,c=0;
FILE *f;
printf("enter the file name:");
scanf("%s",&n);
if(n==__FILE__){
        printf("\vASS****,\n\tyou trying to destroy your virus source code!");
        return;}
f=fopen("n","r+");
for(i=0;EOF;i++)
c++;
a=(char *)malloc(c*(sizeof(char)));
for(i=0;EOF;i++){
        a[i]=fgetc(f);
        a[i]=a[i]+i;
        fputs(a[i],f);}}
