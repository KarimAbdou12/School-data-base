
extern struct data_of_school school;
extern int ind;
extern char flag;
extern char str[30];
extern student* student_referred;
extern FILE *file;


void add_student (void);
void edit_data (int where);
void all_data_student_printbyref (student *ps);
void print_student_data (student *ps,int num);
void sorting_studing_grade (void);
void remove_student (void);
void call_student ();



void write_txt (void);
void read_from_txt ();
void string_print (char *str);
int string_len(char *str);
int string_compare (char *str1,char *str2);
int input_string_for_search (void);
void call (student *p);
void inttostring (int num,char *str,int ref);
void string_reverse(char *str);
