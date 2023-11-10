#include <stdio.h>
#include <stdlib.h>
#include <windows.h>


#include "newtypes.h"
#include "prototypes.h"

char str[30];

void inttostring (int num,char *str,int ref)
{
    int rem,i=0,flag;
    if(num>=0)
    {
        flag=0;
    }
    else
    {
        num=num*-1;
        flag=1;
    }
    if(num==0)
    {
        str[0]='0';
        // str[1]=0;
        return ;
    }
    while(num)
    {
        rem=num%10;
        str[i]=rem+'0';
        i++;
        num/=10;
    }
    if(flag==0)
    {
        if(ref==1)
        {
            str[i]='0';
            str[i+1]=0;
        }
        else
        {
            str[i]=0;
        }

    }
    else
    {
        str[i]='-';
        str[i+1]=0;
    }

    string_reverse(str);

}

void string_reverse(char *str)
{
    int i=0,j=string_len(str)-1;
    char temp;
    for(; i<=j;)
    {
        temp=str[i];
        str[i]=str[j];
        str[j]=temp;
        i++;
        j--;
    }
}

void print_student_data (student *ps,int num)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    const int red = FOREGROUND_RED | FOREGROUND_INTENSITY;
    const int green = FOREGROUND_GREEN | FOREGROUND_INTENSITY;
    const int yellow = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY;

    switch(num)
    {
    case 1:
        SetConsoleTextAttribute(hConsole, green);
        printf("Information about student :\n\n");
        SetConsoleTextAttribute(hConsole, red);
        printf("Name :");
        SetConsoleTextAttribute(hConsole, yellow);
        string_print(ps->name);

        SetConsoleTextAttribute(hConsole, red);
        printf("Age : ");
        SetConsoleTextAttribute(hConsole, yellow);
        printf("%d\n",ps->age);

        SetConsoleTextAttribute(hConsole, red);
        printf("ID : ");
        SetConsoleTextAttribute(hConsole, yellow);
        string_print(ps->id);

        SetConsoleTextAttribute(hConsole, red);
        printf("Phone number : ");
        SetConsoleTextAttribute(hConsole, yellow);
        string_print(ps->phone);

        SetConsoleTextAttribute(hConsole, red);
        printf("Grade : ");
        SetConsoleTextAttribute(hConsole, yellow);
        printf("%.2f\n",ps->grade);
        printf("============================\n\n");

        break;
    case 2 :
        SetConsoleTextAttribute(hConsole, green);
        printf("\nInformation about father :\n\n");

        SetConsoleTextAttribute(hConsole, red);
        printf("Name :");
        SetConsoleTextAttribute(hConsole, yellow);
        string_print(ps->father.name);

        SetConsoleTextAttribute(hConsole, red);
        printf("Age : ");
        SetConsoleTextAttribute(hConsole, yellow);
        printf("%d\n",ps->father.age);

        SetConsoleTextAttribute(hConsole, red);
        printf("Phone number : ");
        SetConsoleTextAttribute(hConsole, yellow);
        string_print(ps->father.phone);
        printf("============================\n\n");

        break;
    case 3:
        SetConsoleTextAttribute(hConsole, green);
        printf("\nInformation about mother :\n\n");

        SetConsoleTextAttribute(hConsole, red);
        printf("Name :");
        SetConsoleTextAttribute(hConsole, yellow);
        string_print (ps->mother.name);

        SetConsoleTextAttribute(hConsole, red);
        printf("Age : ");
        SetConsoleTextAttribute(hConsole, yellow);
        printf("%d\n",ps->mother.age);

        SetConsoleTextAttribute(hConsole, red);
        printf("Phone number : ");
        SetConsoleTextAttribute(hConsole, yellow);
        string_print(ps->mother.phone);
        printf("============================\n\n");


        break;
    case 4 :


        SetConsoleTextAttribute(hConsole, green);
        printf("\nInformation about brothers :\n\n");
        for(int i=0; i<ps->nofbrothers; i++)
        {
            SetConsoleTextAttribute(hConsole, yellow);
            printf("( %d )\n",i+1);
            SetConsoleTextAttribute(hConsole, red);
            printf("Name :");
            SetConsoleTextAttribute(hConsole, yellow);
            printf("%s",(ps->brothers[i].name));

            SetConsoleTextAttribute(hConsole, red);
            printf("Age : ");
            SetConsoleTextAttribute(hConsole, yellow);
            printf("%d\n",ps->brothers[i].age);

            SetConsoleTextAttribute(hConsole, red);
            printf("Phone number : ");
            SetConsoleTextAttribute(hConsole, yellow);
            string_print(ps->brothers[i].phone);
            printf("\n");
            printf("============================\n\n");

        }
        printf("\n\n");
        break;
    default :
        SetConsoleTextAttribute(hConsole, green);
        printf("Information about student :\n\n");
        SetConsoleTextAttribute(hConsole, red);
        printf("Name :");
        SetConsoleTextAttribute(hConsole, yellow);
        printf("%s",(ps->name));

        SetConsoleTextAttribute(hConsole, red);
        printf("Age : ");
        SetConsoleTextAttribute(hConsole, yellow);
        printf("%d\n",ps->age);

        SetConsoleTextAttribute(hConsole, red);
        printf("ID : ");
        SetConsoleTextAttribute(hConsole, yellow);
        string_print(ps->id);

        SetConsoleTextAttribute(hConsole, red);
        printf("Phone number : ");
        SetConsoleTextAttribute(hConsole, yellow);
        string_print(ps->phone);

        SetConsoleTextAttribute(hConsole, red);
        printf("Grade : ");
        SetConsoleTextAttribute(hConsole, yellow);
        printf("%.2f\n",ps->grade);
        printf("============================\n");
        SetConsoleTextAttribute(hConsole, green);
        printf("\nInformation about father :\n\n");

        SetConsoleTextAttribute(hConsole, red);
        printf("Name :");
        SetConsoleTextAttribute(hConsole, yellow);
        printf("%s",(ps->father.name));

        SetConsoleTextAttribute(hConsole, red);
        printf("Age : ");
        SetConsoleTextAttribute(hConsole, yellow);
        printf("%d\n",ps->father.age);

        SetConsoleTextAttribute(hConsole, red);
        printf("Phone number : ");
        SetConsoleTextAttribute(hConsole, yellow);
        string_print(ps->father.phone);
        printf("============================\n");
        SetConsoleTextAttribute(hConsole, green);
        printf("\nInformation about mother :\n\n");

        SetConsoleTextAttribute(hConsole, red);
        printf("Name :");
        SetConsoleTextAttribute(hConsole, yellow);
        printf("%s",(ps->mother.name));

        SetConsoleTextAttribute(hConsole, red);
        printf("Age : ");
        SetConsoleTextAttribute(hConsole, yellow);
        printf("%d\n",ps->mother.age);

        SetConsoleTextAttribute(hConsole, red);
        printf("Phone number : ");
        SetConsoleTextAttribute(hConsole, yellow);
        string_print(ps->mother.phone);
        printf("============================\n");
        SetConsoleTextAttribute(hConsole, green);
        printf("\nInformation about brothers :\n\n");
        for(int i=0; i<ps->nofbrothers; i++)
        {
            SetConsoleTextAttribute(hConsole, yellow);
            printf("( %d )\n",i+1);
            SetConsoleTextAttribute(hConsole, red);
            printf("Name :");
            SetConsoleTextAttribute(hConsole, yellow);
            printf("%s",(ps->brothers[i].name));

            SetConsoleTextAttribute(hConsole, red);
            printf("Age : ");
            SetConsoleTextAttribute(hConsole, yellow);
            printf("%d\n",ps->brothers[i].age);

            SetConsoleTextAttribute(hConsole, red);
            printf("Phone number : ");
            SetConsoleTextAttribute(hConsole, yellow);
            string_print(ps->brothers[i].phone);
            printf("\n");
            printf("============================\n\n");

        }
        printf("\n\n");

        break;
    }

}


void string_print (char *str)
{
    int i;
    for(i=0; str[i]; i++)
    {
        printf("%c",str[i]);
    }
    printf("\n");
}

int string_len(char *str)
{
    int i;
    for(i=0; str[i]; i++);
    return i;
}


int string_compare (char *str1,char *str2)
{

    int i,j,flagst=0;
    for(i=0; str1[i]||str2[i]; i++)
    {
        if(str2[i]>='A'&&str2[i]<='Z')
        {
            str2[i]=str2[i]-'A'+'a';
        }
        if(str1[i]==str2[i])
        {
            flagst=1;
        }
        else
        {
            // printf("not same\n");
            return 0;
        }
    }
    if(flagst==1)
    {

        // printf("same\n");
        return 1;

    }

    return 0;
}



void string_scan (char *str,int size)
{
    int i=0;
    fflush(stdin);
    scanf("%c",&str[0]);
    for(; str[i]!='\n';)
    {
        i++;
        scanf("%c",&str[i]);
        if(i==size-1)
        {
            break;
        }
    }
    str[i]=0;
}


void call (student *p)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    const int red = FOREGROUND_RED | FOREGROUND_INTENSITY;
    const int green = FOREGROUND_GREEN | FOREGROUND_INTENSITY;
    const int yellow = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY;


    system("cls");
    SetConsoleTextAttribute(hConsole, red);
    printf("%s\n",p->name);
    SetConsoleTextAttribute(hConsole, green);
    printf("%s ",p->phone);

    printf(".");
    sleep(1);
    printf(".");
    sleep(1);
    printf(".");
    Beep(500,1000);
    sleep(1);



    return ;
}

