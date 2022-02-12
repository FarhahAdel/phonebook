#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#include <string.h>
#include "header.h"
void clrscr()
{
    system("@cls||clear");
}
void LOAD()
{
    FILE *f1;
    if(!loadflag)
    {

        f1=fopen("phonebook.txt","r");
        if (f1!=NULL)
        {

            while (!feof(f1))
            {
                fscanf(f1,"%[^,],",c[count].FirstName);
                fscanf(f1,"%[^,],",c[count].LastName);
                fscanf(f1,"%d-",&c[count].dof.day);
                fscanf(f1,"%d-",&c[count].dof.month);
                fscanf(f1,"%d,",&c[count].dof.year);
                fscanf(f1,"%[^,],",c[count].adrs);
                fscanf(f1,"%[^,],",c[count].email);
                fscanf(f1,"%[^\n]\n",c[count].phone);

                count++;
            }
            printf("\t \t \t * SUCCESSFULLY LOADED * \n");
            fclose(f1);

        }
        else
            printf("\n Error loading file");
        loadflag=1;
        tag=0;
    }

}

void Save()
{
    FILE *f1;
    f1=fopen("phonebook.txt","w");
    int i;

    if (f1!=NULL)
    {

        for(i=0; i<count; i++)
        {
            fprintf(f1,"%s,",c[i].FirstName);
            fprintf(f1,"%s,",c[i].LastName);
            fprintf(f1,"%d-%d-%d,",c[i].dof.day,c[i].dof.month,c[i].dof.year);
            fprintf(f1,"%s,",c[i].adrs);
            fprintf(f1,"%s,",c[i].email);
            fprintf(f1,"%s\n",c[i].phone);
        }




        printf("\t \t \t * SUCCESSFULLY SAVED * \n");
        tag=1;
        fclose(f1);
    }
    else
        printf("\n Error loading file");
}
int validate_string ( const char *s )
{
    if ( !*s )
    {
        return 0;
    }
    for ( ; *s; ++s )
    {
        if ( !isalpha ( *s ) )
        {
            return 0;
        }
    }
    return 1;
}
int validate_number (char N[])
{
    int count=0;
    int i;
    for(i=0; i<strlen(N); i++)
    {
        if(isalpha(N[i]))
            count++;
    }
    if(count)
        return 0;
    else
        return 1;
}

int validate_email(char test[])
{
    int     i;
    char    *pos1, *pos2;
    char    *ch;


    while (1)
    {
        for (i = 0, ch = test; *ch; *ch++)
        {
            if (*ch == '@')
            {
                pos1 = ch;  // <-stores last @ address
                i++;
            }
        }
        pos2 = ch;          // <-stores end address ("\0") of test

        /* If there is only one "@" */
        if (i == 1)
        {

            /* Pos1 - test <-a character must be before "@". Ch - pos1 <-Counts
             * backwards from the end of the string towards "@". A character
             * must be between "@" and "." */
            while (pos1 - test && ch - pos1 > 1)
            {

                /* From the end of string to "." has to be atleast 2 chars */
                if ((pos2 - ch) > 2 && *ch == '.')
                {
                   // printf("pos2 - ch is %d and *ch is %c",pos2 - ch, *ch);
                    return 1;
                }
                ch--;
            }
        }
        puts("error in data entered\n \tINVAILED!!\n Enter email");
        scanf("%39s", test);
    } /* End while */

    return 1;
}
void EXIT()
{
    int choice,choice2;
    printf("Do you want to exit?\n1-Yes\n2-No\n");
    scanf("%d",&choice);
    switch(choice)
    {
    case 1:
    {
        if(tag==1)
            exit(0);
        else
        {
            printf("You didn't save.\n1-Exit and save.\n2-Exit anyway\n");
            scanf("%d",&choice2);
            if (choice2==1)
            {
                Save();
                exit(0);
            }
            else if(choice2==2)
                exit(0);
        }
        break;
    }
    case 2:
        break;
    default:
        printf("Choice doesn't exist.\n");
    }
}
int Search ( int start)
{
    int i;
    char s[20];
    char key[20];
    int n=0;
    if (!loadflag)
        LOAD();
    int choice;
    printf("Choose type of search \n \t 1)First Name \n \t 2)Last Name \n \t 3)Email \n \t 4)Adress \n \t 5)Phone Number \n");
    scanf("%d",&choice);
    switch (choice)
    {

    case 1:
    {
        printf("enter the name \n");
        scanf("%s",s);
        while(!validate_string(s))
        {
            printf("error in data entered\n \tINVAILED!!");
            printf("\nEnter the name again: : ");
            scanf("%s",s);
        }

        for(i=start; i<count; i++ )
        {
            strcpy(key,c[i].FirstName);
            if(stricmp(key,s)==0)
            {
                n=1;
                break;

            }
        }
        break;
    }
    case 2:
    {
        printf("enter the name \n");
        scanf("%s",s);
        while(!validate_string(s))
        {
            printf("error in data entered\n \tINVAILED!!");
            printf("\nEnter the name again: ");
            scanf("%s",s);
        }
        for(i=start; i<count; i++ )
        {
            strcpy(key,c[i].LastName);
            if(stricmp(key,s)==0)
            {
                n=1;
                break;

            }
        }
        break;
    }
    case 3 :
    {

        printf("enter the Email \n");
        scanf("%s",s);
        for(i=start; i<count; i++ )
        {
            strcpy(key,c[i].email);
            if(stricmp(key,s)==0)
            {
                n=1;
                break;

            }
        }
        break;
    }
    case 4:
    {

        printf("enter the Adress \n");
        fflush(stdin);
        gets(s);
        for(i=start; i<count; i++ )
        {
            strcpy(key,c[i].adrs);
            if(stricmp(key,s)==0)
            {
                n=1;
                break;

            }
        }
        break;
    }
    case 5:
    {

        printf("enter the phone number \n");
        scanf("%s",s);
        puts(s);
        while(!validate_number(s))
        {
            printf("error in data entered\n \tINVAILED!!");
            printf("\nEnter phone number again : ");
            gets(s);

        }
        for(i=start; i<count; i++ )
        {
            strcpy(key,c[i].phone);
            if(stricmp(key,s)==0)
            {
                n=1;
                break;

            }
        }
        break;
    }
    }

    if (n==1)
        printf("found \n");
    else
    {
        printf("not found \n");
        i++;
    }
    return i;
}
void ADD()
{
    int i=count;

    printf("\nEnter First Name : ");
    scanf("%s",c[i].FirstName);
    while(!validate_string(c[i].FirstName))
    {
        printf("error in data entered\n \tINVAILED!!");
        printf("\nEnter First Name : ");
        scanf("%s",c[i].FirstName);
    }
    printf("\nEnter Last Name : ");
    scanf("%s",c[i].LastName);
    while(!validate_string(c[i].LastName))
    {
        printf("error in data entered\n \tINVAILED!!");
        printf("\nEnter Last Name : ");
        scanf("%s",c[i].LastName);
    }

    printf("\nEnter date of birth : ");
    scanf("%d",&c[i].dof.day);
    while(c[i].dof.day<1 ||  c[i].dof.day>31)
    {
        printf("error in data entered\n \tINVAILED!!");
        printf("\nEnter day : ");
        scanf("%d",&c[i].dof.day);

    }

    printf("\nEnter month : ");

    scanf("%d",&c[i].dof.month);


    while(c[i].dof.month>12 || c[i].dof.month<1)
    {
        printf("error in data entered\n \tINVAILED!!");
        printf("\nEnter month : ");
        scanf("%d",&c[i].dof.month);
    }

    printf("\nEnter year : ");
    scanf("%d",&c[i].dof.year);
    fflush(stdin);
    while(c[i].dof.year>2018 || c[i].dof.year<1800)
    {
        printf("error in data entered\n \tINVAILED!!");
        printf("\nEnter year : ");
        scanf("%d",&c[i].dof.year);
    }


    printf("\nEnter Address : ");
    fflush(stdin);
    gets(c[i].adrs);

    printf("\nEnter Email : ");
    scanf("%s",c[i].email);
    validate_email(c[i].email);


    printf("\nEnter Phone Number : ");
    scanf("%s",c[i].phone);
    while(!validate_number(c[i].phone))
    {
        printf("error in data entered\n \tINVAILED!!");
        printf("\nEnter phone number : ");
        scanf("%s",c[i].phone);
    }

    count++;
    i++;
    tag=0;

}
int check()
{
    int ans;
    int z=Search(0);
    if(!(z>count))
    {
        printf("Is this the contact you want? \n1)Yes 2)No");
        printf("\nFirst Name : %s",c[z].FirstName);
        printf("\nLast Name : %s",c[z].LastName);
        printf("\nBirthday : %d-%d-%d,",c[z].dof.day,c[z].dof.month,c[z].dof.year);
        printf("\nAdress : %s,",c[z].adrs);
        printf("\nEmail : %s,",c[z].email);
        printf("\nPhone Number : %s.\n",c[z].phone);
        scanf("%d",&ans);
        if(ans==1)
            return z;
        else
            z=Search(z+1);
        return z;
    }
    return z;
}
void Delete ()
{
    int choice;
    int z=check();


if(z<=count){
    int i=z+1;
    int k=count-1;

    printf("are you sure you want to delete %s \n1)yes,delete.\n2)no\n",c[z].FirstName);
    scanf("%d",&choice);

    if(choice == 1)
    {
        while(i!=k)
        {
            c[z]=c[i];
            z++;
            i++;
        }

    }
    tag=0;
}
else printf("NOT AVAILABLE COMMAND");
}
int compareName(const void *a,const void *b)
{
    const contact *p1 = a;
    const contact *p2=b;
    return strcmp(p1->LastName, p2->LastName);
}
int compareyear(const void *a,const void *b)
{
    const contact *p1 = a;
    const contact *p2=b;
    return (p1->dof.year - p2->dof.year);
}
void sortbyLname( )
{int i,j;
contact swap;
    qsort(c,count,sizeof(contact),compareName);
    for(j=0;j<count;j++)
        for(i=0;i<count-j-1;i++)
    {
        if(!strcmp(c[i].LastName,c[i+1].LastName))
            if(strcmp(c[i].FirstName,c[i+1].FirstName)==1)
        {
            swap=c[i];
            c[i]=c[i+1];
            c[i+1]=swap;
        }
    }
}
void sortbyDOF()
{
    int i,j;
    contact swap;
    qsort(c,count,sizeof(contact),compareyear);
    for (j=0; j<count; j++)
        for (i=0; i<count-j-1; i++)
        {
            if(c[i].dof.year==c[i+1].dof.year)
            {
                if(c[i].dof.month>c[i+1].dof.month)
                {
                    swap=c[i];
                    c[i]=c[i+1];
                    c[i+1]=swap;
                }
                if(c[i].dof.month==c[i+1].dof.month)
                    if(c[i].dof.day>c[i+1].dof.day)
                    {
                        swap=c[i];
                        c[i]=c[i+1];
                        c[i+1]=swap;

                    }
            }
        }

}
void PRINT()
{

    int i;
    for(i=0; i<count; i++)
    {
        printf("\nFirst Name : %s",c[i].FirstName);
        printf("\nLast Name : %s",c[i].LastName);
        printf("\nBirthday : %d-%d-%d,",c[i].dof.day,c[i].dof.month,c[i].dof.year);
        printf("\nAdress : %s,",c[i].adrs);
        printf("\nEmail : %s,",c[i].email);
        printf("\nPhone Number : %s.",c[i].phone);

        printf("\n");
    }

}
void prnt()
{
    int choice,choic1;
    if(!loadflag)
        LOAD();
label1:
    printf("Do you want to print it sorted? \n1)YES \n2)NO \n");
    scanf("%d",&choice);
    if(choice==2)
        PRINT();
    else if (choice==1)
    {
label2:
        printf("CHOOSE TYPE OF SORTING \n1)Last Name\n2)Birthday \n");
        scanf("%d",&choic1);
        switch (choic1)
        {
        case 1:
        {
            sortbyLname();
            PRINT();
            break;
        }
        case 2:
        {
            sortbyDOF();
            PRINT();
            break;
        }
        default :
        {
            printf("PLEAASE CHOOSE FROM THE FOLLOWING COMANDS \n");
            goto label2;
        }

        }
    }
    else
    {
        printf("PLEAASE CHOOSE FROM THE FOLLOWING COMANDS \n");
        goto label1;
    }

}
void EDIT()
{
    int z=check();
    if (!(z>count))
    {
        char s[50];
        fflush(stdin);

        printf("\nEnter First Name : ");

        gets(s);

        if(strcasecmp(s,"\0"))
        {
            strcpy(c[z].FirstName,s);
        }

        s[0] = 0;
        getchar();
        printf("\nEnter Last Name : ");

        gets(s);

        if(strcasecmp(s,"\0"))
        {
            strcpy(c[z].LastName,s);
        }
        s[0] = 0;
        getchar();
        printf("\nEnter Address : ");

        gets(s);

        if(strcasecmp(s,"\0"))
        {
            strcpy(c[z].adrs,s);
        }
        s[0] = 0;
        getchar();
        printf("\nEnter Email : ");

        gets(s);

        if(strcasecmp(s,"\0"))
        {
            strcpy(c[z].email,s);
        }

    }
    else
    {
        int d;
        printf("do you want to add this contact 1)yes 2)no\n");
        scanf("%d",&d);
        if(d==1)
        {
            ADD();
        }
    }
    tag=0;
}
