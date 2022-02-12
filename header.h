typedef struct
{
    int day;
    int month;
    int year;
} birthday;
typedef struct
{
    char FirstName[20];
    char LastName[20];
    char email[20];
    birthday dof;
    char phone[20];
    char adrs[20];
} contact;
int count=0;
contact c[1000];
int loadflag=0;
int tag=1;
void clrscr();
void LOAD();
int check();
void Save();
int validate_string( const char *s );
int validate_number (char N[]);
void EXIT();
int Search ();
void ADD();
void Delete ();
int compareName(const void *a,const void *b);
int compareyear(const void *a,const void *b);
void sortbyLname( );
void sortbyDOF();
void PRINT();
void prnt();
void EDIT();
