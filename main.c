#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#include <string.h>


int main()
{
    int command;
    while(1)
    {
        printf("\t \t   \t      * WELCOME *");
        printf("\n \t \t  \t     CHOOSE THE COMMAND");
        printf("\n \t \t \t \t 1-LOAD ");
        printf("\n \t \t \t \t 2-SEARCH ");
        printf("\n \t \t \t \t 3-ADD ");
        printf("\n \t \t \t \t 4-DELETE ");
        printf("\n \t \t \t \t 5-MODIFY ");
        printf("\n \t \t \t \t 6-PRINT ");
        printf("\n \t \t \t \t 7-SAVE ");
        printf("\n \t \t \t \t 8-QUIT \n \n");

        scanf("%d",&command);
        switch (command)
        {
        case 1 :
        {

            clrscr();
            LOAD();
            printf("\n");
            break;
        }
        case 2:
        {
            clrscr();
            Search(0);
            printf("\n");
            break;
        }

        case 3:
        {
            clrscr();
            ADD();
            printf("\n");
            break;
        }
        case 4:
        {
            clrscr();
            Delete();
            printf("\n");
            break;
        }
        case 5 :
        {
            clrscr();
            EDIT();
            printf("\n");
            break;
        }
        case 6:
        {
            clrscr();
            prnt();
            printf("\n");
            break;
        }

        case 7:
        {
            clrscr();
            Save();
            printf("\n");
            break;
        }
        case 8:
        {
            clrscr();
            EXIT();
        }
        default:
            printf("PLEAASE CHOOSE FROM THE FOLLOWING COMANDS \n");

        }


    }
    return 0;
}
