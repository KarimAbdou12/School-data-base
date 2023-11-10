#include <stdio.h>
#include <stdlib.h>
#include <windows.h>



#include "newtypes.h"
#include "prototypes.h"


struct data_of_school school;
FILE *file;


int main()
{

    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    const int red = FOREGROUND_RED | FOREGROUND_INTENSITY;
    const int green = FOREGROUND_GREEN | FOREGROUND_INTENSITY;
    const int yellow = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY;

    /* SetConsoleTextAttribute(hConsole, red);
     printf("This is red text.\n");
     SetConsoleTextAttribute(hConsole, green);
     printf("This is green text.\n");
     SetConsoleTextAttribute(hConsole, yellow);
     printf("This is yellow text.\n");
     SetConsoleTextAttribute(hConsole, FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
     SetConsoleTextAttribute(hConsole, yellow);*/

    read_from_txt();
    int choice;

    while(1)
    {
        system("cls");

        SetConsoleTextAttribute(hConsole, red);
        printf("\n\n\t\tWelcome To Our School\n\n");
        SetConsoleTextAttribute(hConsole, green);
        printf("choose :\n\n");
        SetConsoleTextAttribute(hConsole, yellow);;
        printf("1-Applying to school\n2-Modify student data\n3-Print Student data\n4-sorting students according to grades\n5-Call student\n6-Print all students\n7-Remove student data\n");
        printf("8-if you finished select 8\n\n");
        fflush(stdin);
        SetConsoleTextAttribute(hConsole, green);
        scanf("%d",&choice);

        if(1==choice)
        {
            add_student();
        }
        else if(2==choice)
        {
            edit_data(0);
        }
        else if(3==choice)
        {
            all_data_student_printbyref(0);
        }
        else if(4==choice)
        {
            sorting_studing_grade();
        }
        else if(5==choice)
        {
            call_student();
        }
        else if(6==choice)
        {
            print_all_students(0);
        }
        else if(7==choice)
        {
            remove_student();
        }
        else if(8==choice)
        {

            break;
        }

    }


    return 0;
}
