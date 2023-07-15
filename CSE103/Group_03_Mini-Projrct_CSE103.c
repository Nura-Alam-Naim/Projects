#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<conio.h>

void head_Message();
void print_Message_in_Center(char *str);
void welcome_Message();
int log();
int menu();
int addVehicleInDataBase(int count);
int is_id_Valid(char *str,int count);
int is_name_valid(char *str);
int is_valid_Date(int d,int m, int y);
void searchVehicles(int count);
void display(int i);
void viewVehicles(int count);
int deleteVehicles(int count);
void updateCredential();

struct details{
        char id[80];
        char vehicle_name[80];
        char manu_name[30];
    }body[];

struct date{
        int dd;
        int mm;
        int yyyy;
    }day[];
    struct date *ptr;

struct credential{
        char user[16];
        char pass[26];
    }crede;

int main()
{
    system("COLOR 78");

    int f;
    int choice;
    int count=0;//to count how many vehicle have been registered
    head_Message();
    welcome_Message();
      tag:
    do{
        f=log();
        if(!f)
        {
            printf("\n\t\t\t\tLogin Failed! Press enter to Try again.");
            getche();
        }
        else f=1;
    }while(f!=1);

    do{
        choice=menu();

        switch(choice)
        {
        case 1:
           count=addVehicleInDataBase(count);
            break;
        case 2:
            searchVehicles(count);
            break;
        case 3:
            viewVehicles(count);
            break;
        case 4:
            count=deleteVehicles(count);
            break;
        case 5:
            updateCredential();
            system("cls");
            goto tag;//to initiate the program from the log in
            break;
        case 6:
            printf("\n\n");
            print_Message_in_Center("!!!Thank You!!!");
            return 0;
        default:
            printf("\n\t\t\t\t\t!!!Unrecognised number!!!");//if unrecognised number is pressed, this message will be shown
            printf("\n\t\t\t\t\t       Try again");
            getche();
            menu();
        }
    }while(choice!=6);
}
void head_Message()
{
    printf("\t\t\t\t"); printf("<~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~>");
    printf("\n");
    printf("\t\t\t\t");printf("<~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~>");
    printf("\n");
    printf("\t\t\t\t");printf("<~><~><~><~><~>                                                                                    <~><~><~><~><~>");
    printf("\n");
    printf("\t\t\t\t");printf("<~><~><~><~><~>                              Vehicle Management System                             <~><~><~><~><~>");
    printf("\n");
    printf("\t\t\t\t");printf("<~><~><~><~><~>                                                                                    <~><~><~><~><~>");
    printf("\n");
    printf("\t\t\t\t");printf("<~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~>");
    printf("\n");
    printf("\t\t\t\t");printf("<~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~>");
    printf("\n\n");
}
void print_Message_in_Center(char *str)
{
    int i,l,f=0;
    l=strlen(str);//to take string length in a variable
    int g=1+l/2;

    printf("\t\t\t\t");printf("<~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~>");//total 114
    printf("\n\n");
    printf("\t\t\t\t");
    for(i=0;i<114;i++)
    {
        if(i>=57-(l/2)&&i<57)//to initiate half string from the left
            {
                printf("%c",str[f]);
                f++;

            }
        else if(i>57&&i<=57+(l/2))//to initiate half string from the right
            {
                printf("%c",str[g]);
                g++;

            }
        else if(i==57)//to print the centre value of the string
            {
                printf("%c",str[l/2]);
            }
        else printf(" ");
    }
    printf("\n\n");
    printf("\t\t\t\t");printf("<~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~>");
    printf("\n\n\n\n");
}
void welcome_Message()
{
    print_Message_in_Center("CSE103");
    printf("\t\t\t");printf("\t\t\t<~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~>");
    printf("\n\n\n");
    printf("\t\t\t");printf("\t\t\t\t<~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~>");
    printf("\n\n");
    printf("\t\t\t");printf("\t\t\t\t<~>                           WELCOME                             <~>");
    printf("\n\n");
    printf("\t\t\t");printf("\t\t\t\t<~>                             TO                                <~>");
    printf("\n\n");
    printf("\t\t\t");printf("\t\t\t\t<~>                           VEHICLE                             <~>");
    printf("\n\n");
    printf("\t\t\t");printf("\t\t\t\t<~>                          MANAGEMENT                           <~>");
    printf("\n\n");
    printf("\t\t\t");printf("\t\t\t\t<~>                            SYSTEM                             <~>");
    printf("\n\n");
    printf("\t\t\t");printf("\t\t\t\t<~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~>");
    printf("\n\n\n");
    printf("\t\t\t");printf("\t\t\t<~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~>");
    printf("\n\n\n\n");
    printf("\t\t\t\t");printf("Enter any key to continue...");
    getche();
}

int log()
{
    system("cls");
    head_Message();
    print_Message_in_Center("LOGIN");

    strcpy(crede.user,"admin");
    strcpy(crede.pass,"admin");

    char pass[26];
    char username[16];
    int f=0;

    printf("\n\t\t\t\tUSERNAME: ");
    gets(username);
    printf("\n\t\t\t\tPassword: ");
    gets(pass);
        if(strcmp(username,crede.user)==0 && strcmp(pass,crede.pass)==0) //comparing input string with username and password
            {
                f=1;
            }
        else
            {
                f=0;
            }
    return f;
}
int menu()
{
    system("cls");
    head_Message();
    print_Message_in_Center("MAIN MENU");

    int i;
    char temp[10];

    printf("\n\n");
    printf("\t\t\t\t");printf("1.Add vehicle\n");
    printf("\t\t\t\t");printf("2.Search vehicles\n");
    printf("\t\t\t\t");printf("3.View vehicles\n");
    printf("\t\t\t\t");printf("4.Delete vehicle\n");
    printf("\t\t\t\t");printf("5.Update password\n");
    printf("\t\t\t\t");printf("6.Exit\n");
    printf("\n\n");
    printf("\t\t\t\t");printf("Enter choice: ");
    gets(temp);
    i=atoi(temp);//converting string to integer value

    return i;

}

int addVehicleInDataBase(int count)
{
    system("cls");
    head_Message();
    print_Message_in_Center("ADD NEW VEHICLE");
    printf("\n");

    int i,f,g,h,d,m,y,a;
    int j,k;
    char temp[80];

    printf("\t\t\t\t");printf("ENTER VEHICLE DETAILS BELOW:");
    printf("\n\t\t\t\t");printf("--------------------------------------------------------------------------------") ;

    for(i=count; ; )
    {                                                                       // To add valid vehicle id
        do{
            printf("\n\t\t\t\t");printf("Vehicle ID NO : ");
                                gets(temp);

            h= is_id_Valid(temp,count);                                     /*Check for no input validation*/
            if(!h)
                {
                   printf("\n\t\t\t\t");printf("Invalid! Characters are used or same id is given. Try again\n");
                }
            else if(h=1)
                {
                    strcpy(body[i].id,temp);
                }
            }while(h!=1);

        do{                                                                     //To add valid vehicle name
            printf("\n\t\t\t\t");printf("Vehicle Name : ");
                                 gets(body[i].vehicle_name);
            strcpy(temp,body[i].vehicle_name);

            f = is_name_valid(temp);/*Check for name input validation*/
            if(!f)
                {
                    printf("\n\t\t\t\t");printf("Invalid Name. Please try again.\n");
                }
            else f=1;
            }while(f!=1);

        do{                                                                 //To add valid vehicle manufacturer name
            printf("\n\t\t\t\t");printf("Vehicle Manufacturer Name : ");
            gets(body[i].manu_name);
            strcpy(temp,body[i].manu_name);
            g = is_name_valid(temp);/*Check for name input validation*/
            if(!g)
                {
                    printf("\n\t\t\t\t");printf("Invalid Name. Please try again.\n");
                }
            else g=1;
            }while(g!=1);

        do{                                                                 //To add valid vehicle manufacture date
            printf("\n\t\t\t\t");printf("Vehicle Issued Date By Manufacturer (day/month/year): ");
                                scanf("%d/%d/%d",&d,&m,&y);
                                gets(temp);//to skip the input buffer.

                                a=is_valid_Date(d,m,y);//Check for the date validity
                                if(a==0)
                                    {
                                        printf("\n\t\t\t\t");printf("Date Invalid. Please enter properly\n");
                                    }
                                else if(a==1)
                                    {
                                        a=1;
                                        day[i].dd= d;
                                        day[i].mm= m;
                                        day[i].yyyy= y;
                                    }
            }while(a!=1);

        i++;
        printf("\n\t\t\t\t");printf("Press any key to go to main menu...");
        if(getche())
            {
                break;
            }
      }

      count=i;
      return count;
}

int is_id_Valid(char *str,int count)
{
    int i,f=1;

    for(i=0;i<strlen(str);i++)
    {
        if(!((str[i]>='0') && (str[i]<='9')))       /*check for characters*/
            {
                f=0;
            }
    }
    for(i=0;i<=count;i++)
    {
        if(!(strcmp(str,body[i].id)))           //Check for same id input
            {
                f=0;
            }
    }
    return f;
}


int is_name_valid(char *str)
{
    int i,f=1;

        if(strlen(str)>30)                       /*check for the string length*/
            {
                f=0;
            }
        for(i=0;i<strlen(str);i++)              /*check for alphabets and digits only*/
        {

            if(!(((str[i]>='a')&&(str[i]<='z')) || ((str[i]>='A')&&(str[i]<='Z'))||((str[i]>='0')&&(str[i]<='9'))  || str[i]==' '||str[i]=='_')||str[i]=='-')
                {
                    f=0;
                }
        }

    return f;
}
int is_valid_Date(int d, int m, int y)
{
    int got=1,f,g,h;

    //check year
    if(y>=1900 && y<=2022)
        {
            f=1;
        }
    else
        {
            f=0;
        }
    //check month
    if(m>=1 && m<=12)
        {
            g=1;
        }
    else
        {
            g=0;
        }
    //check days
    if((d>=1 && d<=31) && (m==1 || m==3 || m==5 || m==7 || m==8 || m==10 || m==12))
        {
            h=1;
        }
    else if((d>=1 && d<=30) && (m==4 || m==6 || m==9 || m==11))
        {
            h=1;
        }
    else if((d>=1 && d<=28) && (m==2))
        {
            h=1;
        }
    else if(d==29 && m==2 && ( y%400==0 ||(y%4==0 && y%100!=0))) //check for leap year months
        {
            h=1;
        }
    else
        {
            h=0;
        }

    if(h==0||g==0||f==0)//if any value is false, the result will be zero
        {
            got=0;
        }
        else
        {
            got=1;
        }
    return got;
}

void searchVehicles(int count)
{
    system("cls");
    head_Message();
    print_Message_in_Center("SEARCH VEHICLE");

    char temp[80];
    int i,found;

    printf("\n");
    printf("\n\t\t\t\t");printf("Enter Vehicle Name to search:");
                         gets(temp);

    found=0;
    for(i=0;i<count;i++)
    {
        if(!(strcmp(temp, body[i].vehicle_name)))
            {
                display(i);//to print the details
                found=1;
                printf("\n");
                break;
            }
    }
    if(!found)
            {
                printf("\n\t\t\t\t");printf("Not Found");
            }
    printf("\n\n\t\t\t\t");printf("Press any key to go to main menu...");
    getche();

}
void display(int i)
{
    printf("\n\t\t\t\t");printf("Vehicle ID NO : %s",body[i].id);
    printf("\n\t\t\t\t");printf("Vehicle Name : %s",body[i].vehicle_name);
    printf("\n\t\t\t\t");printf("Vehicle Manufacturer Name : %s",body[i].manu_name);
    printf("\n\t\t\t\t");printf("Vehicle Issued Date By Manufacturer (day/month/year): %d/%d/%d",day[i].dd,day[i].mm,day[i].yyyy);
}
void viewVehicles(int count)
{
    system("cls");
    head_Message();
    print_Message_in_Center("VIEW VEHICLE DETAILES");

    int i,c=1;

    if(!count)
        {
           printf("\n\t\t\t\t");printf("No Records."); //initially there will be no records to view
        }
    else
    {
        for(i=0;i<count;i++)//to access every structure value
        {
            printf("\n\t\t\t\t");printf("Vehicle Count:%d",c);
            printf("\n\n\t\t\t\t");printf("Vehicle ID NO : %s",body[i].id);
            printf("\n\t\t\t\t");printf("Vehicle Name : %s",body[i].vehicle_name);
            printf("\n\t\t\t\t");printf("Vehicle Manufacturer Name : %s",body[i].manu_name);
            printf("\n\t\t\t\t");printf("Vehicle Issued Date By Manufacturer (day/month/year): %d/%d/%d",day[i].dd,day[i].mm,day[i].yyyy);
            printf("\n\n\n");
            c++;
        }
    }
    printf("\n\n\t\t\t\t");printf("Press any key to go to main menu...");
    getche();
}
int deleteVehicles(int count)
{
    system("cls");
    head_Message();
    print_Message_in_Center("DELETE VEHICLE DETAILES");
    printf("\n");

    char temp[25];
    int i,found=0,del;

    printf("\n\t\t\t\t");printf("Enter vehicle ID NO. for delete: ");
                         gets(temp);

    for(i=0;i<count;i++)// to search in every structure for the id
    {
        if(!(strcmp(temp,body[i].id)))
            {
                found=1;
                del=i;
                break;
            }
    }
    if(found==1)
        {
           for(i=del;i<count;i++) // to place the value to targeted location from the forwarded locations
            {
                strcpy(body[i].id,body[i+1].id);
                strcpy(body[i].vehicle_name,body[i+1].vehicle_name);
                strcpy(body[i].manu_name,body[i+1].manu_name);
                day[i].dd=day[i+1].dd;
                day[i].mm=day[i+1].mm;
                day[i].mm=day[i+1].mm;

            }
            printf("\n\n\n\t\t\t\t");printf("Record deleted successfully.....");

            count--;    // deleting one index from the register counter
        }
    if(!found)
        {
             printf("\n\t\t\t\t");printf("Not found");
        }
    printf("\n\n\n\t\t\t\t");printf("Press any key to go to main menu.");
    getche();
    return count;
}
void updateCredential()
{
    system("cls");
    head_Message();
    print_Message_in_Center("UPDATE CREDENTIAL");
    printf("\n");

    int flag=1,i,f=1;

    printf("\n\t\t\t\t");printf("Rules for USERNAME: ");
    printf("\n\n\t\t\t\t");printf("1. USERNAME only contains characters and numbers.");
    printf("\n\t\t\t\t");printf("2. First character of the USERNAME must be an alphabet.");
    printf("\n\t\t\t\t");printf("3. USERNAME must have least 4 characters and maximum 16 characters\n");

        //For Update USERNAME
    do{
        printf("\n\t\t\t\t");printf("New USERNAME: ");
        gets(crede.user);

        if((strlen(crede.user)<4) || (strlen(crede.user)>16))//check for conditioned length
            {
                f=0;
            }
        if(!(((crede.user[0]>='a')&&(crede.user[0]<='z')) || ((crede.user[0]>='A')&&(crede.user[0]<='Z')) ))// check for first character
            {
                f=0;
            }
        for(i=0;i<strlen(crede.user)-1;i++)
        {
            if(!( ((crede.user[i]>='a')&&(crede.user[i]<='z')) || ((crede.user[i]>='A')&&(crede.user[i]<='Z')) ||
                  ((crede.user[i]>='0')&&(crede.user[i]<='9'))))// check for characters and digits only
                {
                    f=0;
                }
        }

        if(f==0)
            {
                printf("\n\t\t\t\t");printf("Wrong Keyword Have Entered! Try again\n");
            }
        else
            {
               f=1;
            }
    }while(f!=1);
    printf("\n\t\t\t\t");printf("Your USERNAME has been changed successfully.....");
    printf("\n\n\n");

            // To update Password
    printf("\n\t\t\t\t");printf("Rules for password: \n");
    printf("\n\t\t\t\t");printf("1. Password only contains characters and numbers.");
    printf("\n\t\t\t\t");printf("2. First character of the password must be an alphabet.");
    printf("\n\t\t\t\t");printf("3. Only \"!,@,#,$,%,^,&,*,_\" special characters can be used.");
    printf("\n\t\t\t\t");printf("4. \"_\" can not be used as a last character.");
    printf("\n\t\t\t\t");printf("5. Password must have least 4 characters and maximum 16 characters \n");

    do{
        printf("\n\t\t\t\t");printf("New password: ");
        gets(crede.pass);
        if((strlen(crede.pass)<4) || (strlen(crede.pass)>25))//check for conditioned lenght
            {
                flag=0;
            }
        if(!( ((crede.pass[0]>='a')&&(crede.pass[0]<='z')) || ((crede.pass[0]>='A')&&(crede.pass[0]<='Z'))))//check for first character
            {
                flag=0;
            }
        for(i=0;i<strlen(crede.pass);i++)
            {
                if(!( ((crede.pass[i]>='a')&&(crede.pass[i]<='z')) || ((crede.pass[i]>='A')&&(crede.pass[i]<='Z')) || ((crede.pass[i]>='0')&&(crede.pass[i]<='9'))||
                    (crede.pass[i]=='!'||crede.pass[i]=='@'||crede.pass[i]=='#'||crede.pass[i]=='$'||crede.pass[i]=='%'||crede.pass[i]=='^'||crede.pass[i]=='&'||
                     crede.pass[i]=='*'|| crede.pass[i]=='_') ))//check for conditioned characters and digits
                    {
                        flag=0;
                    }
            }

        if(crede.pass[strlen(crede.pass)-1]=='_')//check for last character
            {
                flag=0;
            }

        if(!flag)
            {
                printf("\n\t\t\t\t");printf("Wrong Keyword Have Entered! Try again");
            }
        else
            {
                flag=1;
            }
    }while(flag!=1);

    printf("\n\t\t\t\t");printf("Your password has been changed successfully.....");
    printf("\n\n\n\t\t\t\t");printf("Login Again -->");
    getche();
}




