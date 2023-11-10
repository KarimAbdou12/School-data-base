
#define NULLPTR ((void*)0)

typedef struct{
char name [30];
int age;
int phone[11];
}person;


typedef struct {
char name[30];
int age;
char id[14];
char phone[11];
float grade;
person father;
person mother;
int nofbrothers;
int nofboys;
int nofsisters;
person *brothers;
char flag;//for print all atudent (sorting )
}student;


struct data_of_school
{
   student **data;
   int nofstudent;
};
