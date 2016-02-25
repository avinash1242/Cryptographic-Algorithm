#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

int main(void)
{
   char *a,av;
   int i,n=0;
   FILE *f;

   a = (char *)malloc(300*(sizeof(char)));
   f = fopen("test.txt","r");
   while(av != EOF)
   {
      av = fgetc(f);
      a[n] = av;
      n++;
   }

   fclose(f);

   for(i=0;i<n;i++)
   {
      a[i] = a[i] + 1;
   }

   f = fopen("test.txt","w");
   fputs(a,f);
   return 0;
}
