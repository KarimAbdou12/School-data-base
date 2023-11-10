#include <stdio.h>
#include <stdlib.h>
#include <windows.h>


#include "newtypes.h"
#include "prototypes.h"


int numofstudents=0;
student* student_referred;
int current;

void write_txt (void)
{
    if(0==numofstudents)
    {
        file = fopen("schooldata.txt", "w");
        fprintf(file,"%c",' ');
        fclose(file);
    }
    int i=0;
    for(i=0; i<numofstudents; i++)
    {
        if(i==0)
        {
            file = fopen("schooldata.txt", "w");
        }
        else
        {
            file = fopen("schooldata.txt", "a");
        }
        fprintf(file,"\n%d\n",i+1);
        fprintf(file,"%s\n",school.data[i]->name);
        fprintf(file,"%d\n",school.data[i]->age);
        fprintf(file,"%s\n",school.data[i]->id);
        fprintf(file,"%s\n",school.data[i]->phone);
        fprintf(file,"%f\n",school.data[i]->grade);
        fprintf(file,"%s\n",school.data[i]->father.name);
        fprintf(file,"%d\n",school.data[i]->father.age);
        fprintf(file,"%s\n",school.data[i]->father.phone);
        fprintf(file,"%s\n",school.data[i]->mother.name);
        fprintf(file,"%d\n",school.data[i]->mother.age);
        fprintf(file,"%s\n",school.data[i]->mother.phone);
        fprintf(file,"%d\n",school.data[i]->nofbrothers);
        fprintf(file,"%d\n",school.data[i]->nofboys);
        fprintf(file,"%d\n",school.data[i]->nofsisters);

        for(int k=0; k<school.data[i]->nofbrothers; k++)
        {
            fprintf(file,"%s\n",school.data[i]->brothers[k].name);
            fprintf(file,"%d\n",school.data[i]->brothers[k].age);
            fprintf(file,"%s\n",school.data[i]->brothers[k].phone);
        }
        if(school.data[i]->nofbrothers==0)
        {
            fprintf(file,"%d\n",school.data[i]->brothers);
        }
        fprintf(file,"%d",school.data[i]->flag);

        fclose(file);

    }



    return ;


}


void read_from_txt (void)//done
{

    if(numofstudents==0)
    {
        school.data=malloc(sizeof(student*));
    }

    school.data[numofstudents]=(student *)malloc(sizeof(student));
    school.data[numofstudents]->flag=0;

    file = fopen("schooldata.txt", "r");
    if (file == NULLPTR)
    {
        printf("Error opening file.\n");
        return 1;
    }
    fscanf(file,"%d\n",&numofstudents);
    school.nofstudent=numofstudents;

    while(!feof(file))
    {

        fgets(school.data[numofstudents-1]->name,30,file); //true
        fscanf(file,"%d",&(school.data[numofstudents-1]->age));//true
        int numread;
        fscanf(file,"%d",&(numread));
        inttostring(numread,school.data[numofstudents-1]->id,0);//true
        fscanf(file,"%d",&(numread));
        inttostring(numread,school.data[numofstudents-1]->phone,1);//true
        fscanf(file,"%f\n",&school.data[numofstudents-1]->grade);
        fgets(school.data[numofstudents-1]->father.name,30,file);
        fscanf(file,"%d",&school.data[numofstudents-1]->father.age);
        fscanf(file,"%d\n",&(numread));
        inttostring(numread,school.data[numofstudents-1]->father.phone,1);//true
        /*=========================================================================*/
        fgets(school.data[numofstudents-1]->mother.name,30,file);
        fscanf(file,"%d",&school.data[numofstudents-1]->mother.age);

        fscanf(file,"%d\n",&(numread));
        inttostring(numread,school.data[numofstudents-1]->mother.phone,1);//true
        /*===========================================================================*/

        fscanf(file,"%d\n",&school.data[numofstudents-1]->nofbrothers);


        if((school.data[numofstudents-1]->nofbrothers))//true
        {
            school.data[numofstudents-1]->brothers=(person *)malloc((school.data[numofstudents-1]->nofbrothers)*sizeof(person));

            fscanf(file,"%d\n",&(school.data[numofstudents-1]->nofboys));
            fscanf(file,"%d\n",&(school.data[numofstudents-1]->nofsisters));

            for(int k=0; k<(school.data[numofstudents-1]->nofbrothers); k++)

            {
                fgets(school.data[numofstudents-1]->brothers[k].name,30,file);
                fscanf(file,"%d",&school.data[numofstudents-1]->brothers[k].age);
                fscanf(file,"%d\n",&(numread));
                inttostring(numread,school.data[numofstudents-1]->brothers[k].phone,1);//true

            }
        }
        else//true
        {

            fscanf(file,"%d\n",&(school.data[numofstudents-1]->nofboys));
            fscanf(file,"%d\n",&(school.data[numofstudents-1]->nofsisters));
            fscanf(file,"%d\n",&(school.data[numofstudents-1]->brothers));
        }

        fscanf(file,"%d\n",&(school.data[numofstudents-1]->flag));
        fscanf(file,"%d\n",&(current));//read number of student from txt file

        if(!feof(file))
        {
            numofstudents++;
            school.data=realloc(&(school.data[0]),(numofstudents)*sizeof(student*));
            school.data[numofstudents-1]=malloc(sizeof(student));
            school.nofstudent=numofstudents;
        }
        else
        {
            return ;
        }

    }
    fclose(file);
    return ;

}


void add_student (void)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    const int red = FOREGROUND_RED | FOREGROUND_INTENSITY;
    const int green = FOREGROUND_GREEN | FOREGROUND_INTENSITY;
    const int yellow = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY;


    int cb=0,cs=0;
    if(numofstudents==0)
    {
        school.data=malloc(sizeof(student*));
    }
    else
    {
        school.data=realloc(school.data,(numofstudents+1)*sizeof(student*));
    }

    school.data[numofstudents]=malloc(sizeof(student));
    school.data[numofstudents]->flag=0;

    SetConsoleTextAttribute(hConsole, green);
    system("cls");
    printf("Information about the student :\n\n");

    SetConsoleTextAttribute(hConsole, red);
    printf("Name : ");
    SetConsoleTextAttribute(hConsole, yellow);
    string_scan(school.data[numofstudents]->name,30);

    SetConsoleTextAttribute(hConsole, red);
    printf("Age : ");
    SetConsoleTextAttribute(hConsole, yellow);
    scanf("%d",&(school.data[numofstudents]->age));

    SetConsoleTextAttribute(hConsole, red);
    printf("ID : ");
    SetConsoleTextAttribute(hConsole, yellow);
    string_scan((school.data[numofstudents]->id),14);

    SetConsoleTextAttribute(hConsole, red);
    printf("phone number : ");
    SetConsoleTextAttribute(hConsole, yellow);
    fflush(stdin);
    string_scan(school.data[numofstudents]->phone,11);

    SetConsoleTextAttribute(hConsole, red);
    fflush(stdin);
    printf("Grade : ");
    SetConsoleTextAttribute(hConsole, yellow);
    scanf("%f",&(school.data[numofstudents]->grade));
    printf("\n");

    SetConsoleTextAttribute(hConsole, green);
    printf("Information about Father :\n\n");

    SetConsoleTextAttribute(hConsole, red);
    printf("Name : ");
    SetConsoleTextAttribute(hConsole, yellow);
    string_scan(school.data[numofstudents]->father.name,30);

    SetConsoleTextAttribute(hConsole, red);
    printf("Age : ");
    SetConsoleTextAttribute(hConsole, yellow);
    scanf("%d",&(school.data[numofstudents]->father.age));

    SetConsoleTextAttribute(hConsole, red);
    fflush(stdin);
    printf("phone number : ");
    SetConsoleTextAttribute(hConsole, yellow);
    string_scan(school.data[numofstudents]->father.phone,11);
    printf("\n");

    SetConsoleTextAttribute(hConsole, green);
    printf("Information abour Mother :\n\n");

    SetConsoleTextAttribute(hConsole, red);
    printf("Name : ");
    SetConsoleTextAttribute(hConsole, yellow);
    string_scan(school.data[numofstudents]->mother.name,30);

    SetConsoleTextAttribute(hConsole, red);
    printf("Age : ");
    SetConsoleTextAttribute(hConsole, yellow);
    scanf("%d",&(school.data[numofstudents]->mother.age));

    SetConsoleTextAttribute(hConsole, red);
    printf("Phone number : ");
    SetConsoleTextAttribute(hConsole, yellow);
    string_scan(school.data[numofstudents]->mother.phone,11);
    printf("\n");


    SetConsoleTextAttribute(hConsole, green);
    printf("Enter the number of brothers : ");
    SetConsoleTextAttribute(hConsole, yellow);

    fflush(stdin);
    scanf("%d",&(school.data[numofstudents]->nofbrothers));

    if((school.data[numofstudents]->nofbrothers)!=0)
    {
        school.data[numofstudents]->brothers=malloc((school.data[numofstudents]->nofbrothers)*sizeof(person));

        SetConsoleTextAttribute(hConsole, red);
        printf("\nchoose :\n\n");
        for(int i=0; i<school.data[numofstudents]->nofbrothers; i++)
        {
            SetConsoleTextAttribute(hConsole, yellow);
            int flag;
            printf("1- Male\t\t2-Female\n");
            SetConsoleTextAttribute(hConsole, green);
            scanf("%d",&flag);
            if(1==flag)
            {
                cb++;
                SetConsoleTextAttribute(hConsole, green);
                printf("Information about brother : \n\n");
                SetConsoleTextAttribute(hConsole, red);
                printf("Name : ");
                SetConsoleTextAttribute(hConsole, yellow);
            }
            else if(2==flag)
            {
                cs++;
                SetConsoleTextAttribute(hConsole, green);
                printf("Information about sister : \n\n");
                SetConsoleTextAttribute(hConsole, red);
                printf("Name :");
                SetConsoleTextAttribute(hConsole, yellow);
            }

            string_scan(school.data[numofstudents]->brothers[i].name,30);

            SetConsoleTextAttribute(hConsole, red);
            printf("age : ");
            SetConsoleTextAttribute(hConsole, yellow);
            scanf("%d",&(school.data[numofstudents]->brothers[i].age));

            SetConsoleTextAttribute(hConsole, red);
            printf("phone number : ");
            SetConsoleTextAttribute(hConsole, yellow);
            string_scan(school.data[numofstudents]->brothers[i].phone,11);

        }
        school.data[numofstudents]->nofboys=cb;
        school.data[numofstudents]->nofsisters=cs;
    }
    else
    {
        school.data[numofstudents]->brothers=(void *)0;
        school.data[numofstudents]->nofboys=cb;
        school.data[numofstudents]->nofsisters=cs;
    }


    file = fopen("schooldata.txt", "a");
    fprintf(file,"\n%d\n",numofstudents+1);
    fprintf(file,"%s\n",school.data[numofstudents]->name);
    fprintf(file,"%d\n",school.data[numofstudents]->age);
    fprintf(file,"%s\n",school.data[numofstudents]->id);
    fprintf(file,"%s\n",school.data[numofstudents]->phone);
    fprintf(file,"%f\n",school.data[numofstudents]->grade);
    fprintf(file,"%s\n",school.data[numofstudents]->father.name);
    fprintf(file,"%d\n",school.data[numofstudents]->father.age);
    fprintf(file,"%s\n",school.data[numofstudents]->father.phone);
    fprintf(file,"%s\n",school.data[numofstudents]->mother.name);
    fprintf(file,"%d\n",school.data[numofstudents]->mother.age);
    fprintf(file,"%s\n",school.data[numofstudents]->mother.phone);
    fprintf(file,"%d\n",school.data[numofstudents]->nofbrothers);
    fprintf(file,"%d\n",school.data[numofstudents]->nofboys);
    fprintf(file,"%d\n",school.data[numofstudents]->nofsisters);

    for(int k=0; k<school.data[numofstudents]->nofbrothers; k++)
    {
        fprintf(file,"%s\n",school.data[numofstudents]->brothers[k].name);
        fprintf(file,"%d\n",school.data[numofstudents]->brothers[k].age);
        fprintf(file,"%s\n",school.data[numofstudents]->brothers[k].phone);
    }
    if(school.data[numofstudents]->nofbrothers==0)
    {
        fprintf(file,"%d\n",school.data[numofstudents]->brothers);
    }
    fprintf(file,"%d",school.data[numofstudents]->flag);

    fclose(file);

    /*==============================================================*/

    numofstudents++;
    school.nofstudent=numofstudents;

}


void edit_data (int where)
{

    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    const int red = FOREGROUND_RED | FOREGROUND_INTENSITY;
    const int green = FOREGROUND_GREEN | FOREGROUND_INTENSITY;
    const int yellow = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY;


    system("cls");
    if(1==where)
    {
        goto end;
    }
    char ch=0,flag,r=0,editch;

    SetConsoleTextAttribute(hConsole, red);
    printf("Enter ID or name\n\n");
    SetConsoleTextAttribute(hConsole, green);
    printf("what will you enter ?\n");
    SetConsoleTextAttribute(hConsole, yellow);
    printf("1- ID \t\t 2- Name\n");
    SetConsoleTextAttribute(hConsole, green);
    scanf("%d",&ch);

    if(1==ch)
    {
        printf("ID : ");
        fflush(stdin);
        scanf("%s",str);
        flag=1;
    }
    else if(2==ch)
    {
        printf("Name : ");
        fflush(stdin);
        scanf("%s",str);
        flag=2;
    }

    int i;  // index of students number in school
    for( i=0; i<numofstudents; i++)
    {

        if(1==flag)
        {
            student_referred=school.data[i];
            r=string_compare(str,student_referred->id);
        }
        else if(2==flag)
        {
            student_referred=school.data[i];
            r=string_compare(str,student_referred->name);
        }
        if(1==r)
        {
            break;
        }
    }

    if(r!=0)
    {
        system("cls");
        print_student_data(school.data[i],5);

end :

        SetConsoleTextAttribute(hConsole, green);
        printf("What do you want edit ?\n");

        printf("Choose :\n");

        SetConsoleTextAttribute(hConsole, green);
        printf("1- ");
        SetConsoleTextAttribute(hConsole, red);
        printf("Information about student \n");

        SetConsoleTextAttribute(hConsole, green);
        printf("2- ");
        SetConsoleTextAttribute(hConsole, red);
        printf("Information about the father \n");

        SetConsoleTextAttribute(hConsole, green);
        printf("3- ");
        SetConsoleTextAttribute(hConsole, red);
        printf("Information about mother \n");

        SetConsoleTextAttribute(hConsole, green);
        printf("4- ");
        SetConsoleTextAttribute(hConsole, red);
        printf("Information about brothers\n ");
        SetConsoleTextAttribute(hConsole, green);
        scanf("%d",&ch);
        switch(ch)
        {
        case 1:
            system("cls");

            print_student_data(student_referred,ch);
            SetConsoleTextAttribute(hConsole, green);
            printf("What do you want edit ?\n\n");
            SetConsoleTextAttribute(hConsole, green);
            printf("Choose :\n");
            SetConsoleTextAttribute(hConsole, red);
            printf("1- ID \t\t\t 2- Age\n3- Phone number \t 4-Grade\n");
            SetConsoleTextAttribute(hConsole, green);
            scanf("%d",&editch);
            if(1==editch)
            {
                printf("Enter new ID : ");
                string_scan(student_referred->id,14);
                SetConsoleTextAttribute(hConsole, red);
                printf("\nDONE\n ");
                sleep(3);
            }
            else if(2==editch)
            {
                printf("Enter new age : ");
                scanf("%d",&(student_referred->age));
                SetConsoleTextAttribute(hConsole, red);
                printf("\nDONE\n ");
                sleep(3);
            }
            else if(3==editch)
            {
                printf("Enter new phone number : ");
                string_scan(student_referred->phone,11);
                SetConsoleTextAttribute(hConsole, red);
                printf("\nDONE\n ");
                sleep(3);
            }
            else if(4==editch)
            {
                printf("Enter new Grade : ");
                scanf("%f",&(student_referred->grade));
                SetConsoleTextAttribute(hConsole, red);
                printf("\nDONE\n ");
                sleep(3);
            }
            break;

        case 2:

            system("cls");
            print_student_data(student_referred,ch);
            SetConsoleTextAttribute(hConsole, green);
            printf("What do you want edit ?\n\n");
            SetConsoleTextAttribute(hConsole, green);
            printf("Choose :\n");
            SetConsoleTextAttribute(hConsole, red);
            printf("1- Age \t\t 2- Phone number \n");
            SetConsoleTextAttribute(hConsole, green);
            scanf("%d",&editch);
            if(1==editch)
            {
                printf("Enter new age : ");
                scanf("%d",&(student_referred->father.age));
                SetConsoleTextAttribute(hConsole, green);
                printf("\nDONE\n ");
                sleep(3);
            }
            else if(2==editch)
            {
                printf("Enter new phone number : ");
                string_scan(student_referred->father.phone,11);
                SetConsoleTextAttribute(hConsole, green);
                printf("\nDONE\n ");
                sleep(3);
            }
            break;

        case 3:

            system("cls");
            print_student_data(student_referred,ch);
            SetConsoleTextAttribute(hConsole, green);
            printf("What do you want edit ?\n\n");
            SetConsoleTextAttribute(hConsole, green);
            printf("Choose :\n");
            SetConsoleTextAttribute(hConsole, red);
            printf("1- Age \t\t 2- Phone number \n");
            SetConsoleTextAttribute(hConsole, green);
            scanf("%d",&editch);
            if(1==editch)
            {
                printf("Enter new age : ");
                scanf("%d",&(student_referred->mother.age));
                SetConsoleTextAttribute(hConsole, green);
                printf("\nDONE\n ");
                sleep(3);
            }
            else if(2==editch)
            {
                printf("Enter new phone number : ");
                string_scan(student_referred->mother.phone,11);
                SetConsoleTextAttribute(hConsole, green);
                printf("\nDONE\n ");
                sleep(3);
            }
            break;

        case 4:



            system("cls");
            print_student_data(student_referred,ch);
            char bch=0;
            if((student_referred->nofbrothers)>1)
            {
                SetConsoleTextAttribute(hConsole, green);
                printf("Enter the number of the brother whose data you want to modify \n");
                SetConsoleTextAttribute(hConsole, red);
                printf("number : ");
                SetConsoleTextAttribute(hConsole, green);
                scanf("%d",&bch);
                bch--;
            }

            SetConsoleTextAttribute(hConsole, green);
            printf("What do you want edit ?\n\n");
            SetConsoleTextAttribute(hConsole, green);
            printf("Choose :\n");
            SetConsoleTextAttribute(hConsole, red);
            printf("1- Age \t\t 2- Phone number \n");
            SetConsoleTextAttribute(hConsole, green);
            scanf("%d",&editch);
            if(1==editch)
            {
                printf("Enter new age : ");
                scanf("%d",&(student_referred->brothers[bch].age));
                SetConsoleTextAttribute(hConsole, red);
                printf("\nDONE\n ");
                sleep(3);
            }
            else if(2==editch)
            {
                printf("Enter new phone number : ");
                string_scan(student_referred->brothers[bch].phone,11);
                SetConsoleTextAttribute(hConsole, green);
                printf("\nDONE\n ");
                sleep(3);
            }
            break;

        }

    }
    write_txt();
    return ;

}



void all_data_student_printbyref (student *ps)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    const int red = FOREGROUND_RED | FOREGROUND_INTENSITY;
    const int green = FOREGROUND_GREEN | FOREGROUND_INTENSITY;
    const int yellow = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY;


    system("cls");
    char flag,r;
    int i=0;// index of students number in school
    if(ps==((void*)0))
    {
        char ch=0,flag,r=0,editch;

        SetConsoleTextAttribute(hConsole, red);
        printf("Enter ID or name\n\n");
        SetConsoleTextAttribute(hConsole, green);
        printf("what will you enter ?\n");
        SetConsoleTextAttribute(hConsole, yellow);
        printf("1- ID \t\t 2- Name\n");
        SetConsoleTextAttribute(hConsole, green);
        scanf("%d",&ch);

        if(1==ch)
        {
            SetConsoleTextAttribute(hConsole, green);
            printf("ID : ");

            fflush(stdin);
            scanf("%s",str);
            flag=1;
        }
        else if(2==ch)
        {
            SetConsoleTextAttribute(hConsole, green);
            printf("Name : ");

            fflush(stdin);
            scanf("%s",str);
            flag=2;
        }

        for( i=0; i<numofstudents; i++)
        {

            if(1==flag)
            {
                student_referred=school.data[i];
                r=string_compare(str,student_referred->id);
            }
            else if(2==flag)
            {
                student_referred=school.data[i];
                r=string_compare(str,student_referred->name);
            }
            if(1==r)
            {
                break;
            }
        }
        if(r==0)
        {
            SetConsoleTextAttribute(hConsole, red);
            printf("\nNOT FOUND\n");
            sleep(3);
            return;
        }
    }
    system("cls");
    print_student_data(student_referred,5);

    SetConsoleTextAttribute(hConsole, green);
    printf("when you finished press ");
    SetConsoleTextAttribute(hConsole, red);
    printf("ENTER \n");
    char ch;
    fflush(stdin);
    scanf("%c",&ch);
    if(ch)
        return ;
    return;
}

void print_all_students (student *ps)//ps : pointer to struct
{

    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    const int red = FOREGROUND_RED | FOREGROUND_INTENSITY;
    const int green = FOREGROUND_GREEN | FOREGROUND_INTENSITY;
    const int yellow = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY;

    system("cls");

    int i;
    SetConsoleTextAttribute(hConsole, green);
    printf("Names :\n\n");
    for( i=0; i<numofstudents; i++)
    {
        SetConsoleTextAttribute(hConsole, yellow);
        student_referred=school.data[i];
        printf("%s- %s\n",student_referred->id,student_referred->name);
    }

    SetConsoleTextAttribute(hConsole, red);
    printf("\n\nDO you want to see all data for a specific student \n");
    SetConsoleTextAttribute(hConsole, yellow);
    printf("1- Yes  \t2-NO\n");

    char r,ch;
    scanf("%d",&ch);
    if(1==ch)
    {
        SetConsoleTextAttribute(hConsole, red);
        printf("Enter his number : ");
        SetConsoleTextAttribute(hConsole, green);
        string_scan(str,14);
        for( i=0; i<numofstudents; i++)
        {
            student_referred=school.data[i];
            r=string_compare(student_referred->id,str);
            if(1==r)
            {
                break;
            }
        }

        system("cls");

        if(r!=0)
        {
            all_data_student_printbyref(student_referred);

        }
        else if(0==r)
        {
            SetConsoleTextAttribute(hConsole, red);
            printf("\nNOT FOUND !!\n");
            sleep(3);
            return ;
        }

    }
    else
    {
        SetConsoleTextAttribute(hConsole, green);
        printf("when you finished press ");
        SetConsoleTextAttribute(hConsole, red);
        printf("ENTER \n");
        char ch;
        fflush(stdin);
        scanf("%c",&ch);
        if(ch)
            return ;


    }
    return ;
}

void sorting_studing_grade (void)
{

    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    const int red = FOREGROUND_RED | FOREGROUND_INTENSITY;
    const int green = FOREGROUND_GREEN | FOREGROUND_INTENSITY;
    const int yellow = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY;

    system("cls");
    int i,j,max;
    SetConsoleTextAttribute(hConsole, green);
    printf("Sorting :\n\n");

    for(j=0; j<numofstudents; j++)
    {
        for(int k=0; k<numofstudents; k++)
        {
            if(school.data[k]->flag==0)
            {
                max=k;
                break;
            }

        }

        for(i=0; i<numofstudents; i++)
        {
            if((school.data[i]->grade)>(school.data[max]->grade)&&(school.data[i]->flag)==0)
            {
                max=i;
            }
        }

        school.data[max]->flag=1;

        SetConsoleTextAttribute(hConsole, red);
        printf("Grade : ");
        SetConsoleTextAttribute(hConsole, yellow);
        printf("%.2f\t\t",school.data[max]->grade);
        SetConsoleTextAttribute(hConsole, red);
        printf("Name : ");
        SetConsoleTextAttribute(hConsole, yellow);
        printf("%s\n",school.data[max]->name);

    }

    for(int j=0;j<numofstudents;j++)
    {
         school.data[j]->flag=0;
    }

    SetConsoleTextAttribute(hConsole, yellow);
    printf("========================================\n\n");

    SetConsoleTextAttribute(hConsole, green);
    printf("when you finished press ");
    SetConsoleTextAttribute(hConsole, red);
    printf("ENTER \n");
    char ch;
    fflush(stdin);
    scanf("%c",&ch);
    if(ch)
        return ;
    return;
}

void remove_student (void)
{

    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    const int red = FOREGROUND_RED | FOREGROUND_INTENSITY;
    const int green = FOREGROUND_GREEN | FOREGROUND_INTENSITY;
    const int yellow = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY;


    system("cls");
    student *temp;
    char ch=0,flag,r=0,editch;

    SetConsoleTextAttribute(hConsole, red);
    printf("Enter ID or name\n\n");
    SetConsoleTextAttribute(hConsole, green);
    printf("what will you enter ?\n");
    SetConsoleTextAttribute(hConsole, yellow);
    printf("1- ID \t\t 2- Name\n");
    SetConsoleTextAttribute(hConsole, green);
    scanf("%d",&ch);

    if(1==ch)
    {
        printf("ID : ");
        scanf("%s",str);
        flag=1;
    }
    else if(2==ch)
    {
        printf("Name : ");
        scanf("%s",str);
        flag=2;
    }
    int i;  // index of students number in school
    for( i=0; i<numofstudents; i++)
    {
        if(1==flag)
        {

            r=string_compare(str,school.data[i]->id);
        }
        else if(2==flag)
        {

            r=string_compare(str,school.data[i]->name);
        }
        if(1==r)
        {
            break;
        }
    }
    if(0!=r)
    {
        for(; i<numofstudents-1; i++)
        {
            temp=school.data[i];
            school.data[i]=school.data[i+1];
            school.data[i+1]=temp;
        }
        free(school.data[i]);
        //free(school.data+(i-1));<<<<<<<<<<<<<<<<<<<<<<<<<  (remove)*/

        school.nofstudent--;
        numofstudents--;
        SetConsoleTextAttribute(hConsole, red);
        printf("\n DONE \n");
        sleep(3);
    }
    else
    {
        printf("NOT FOUND !!\n");
        sleep(3);
    }

    write_txt();
    return ;
}


void call_student ()
{
    system("cls");
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    const int red = FOREGROUND_RED | FOREGROUND_INTENSITY;
    const int green = FOREGROUND_GREEN | FOREGROUND_INTENSITY;
    const int yellow = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY;

    int i;
    char flag,r=0,ch;

    SetConsoleTextAttribute(hConsole, red);
    printf("Enter ID or name\n\n");
    SetConsoleTextAttribute(hConsole, green);
    printf("what will you enter ?\n");
    SetConsoleTextAttribute(hConsole, yellow);
    printf("1- ID \t\t 2- Name\n");
    SetConsoleTextAttribute(hConsole, green);
    scanf("%d",&ch);

    if(1==ch)
    {
        printf("ID : ");
        scanf("%s",str);
        flag=1;
    }
    else if(2==ch)
    {
        printf("Name : ");
        scanf("%s",str);
        flag=2;
    }
    for( i=0; i<numofstudents; i++)
    {
        if(1==flag)
        {
            r=string_compare(str,school.data[i]->id);
        }
        else if(2==flag)
        {
            r=string_compare(str,school.data[i]->name);
        }
        if(1==r)
        {
            break;
        }
    }
    if(0!=r)
    {
        call(school.data[i]);
        call(school.data[i]);
        call(school.data[i]);

        SetConsoleTextAttribute(hConsole, red);

        printf("\n\nNO ANSWER !!\n");
        Beep(1000,900);
        sleep(3);

    }
    else
    {

        printf("NOt FOUND !!");
        sleep(3);
    }



    return ;
}
