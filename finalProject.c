#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100
#define limitn 5

void signin();
void clrtemp();
void init(void);
void signup();
void scan();
void mhs_mainmenu();
void password();
void changepw();
void msg();
void course();
void ipk();
void sendmsg();
void sendmsg2();
int calc(int a, int b);
void calc2(int *x, int *y, int *z);

int i = 0,k = 0, limit = 0,chgpw = 0, j = 0;

struct usrinfo
{
    char usrname[50], password[50], name[50], inbox[50][300], id[10], course[10][3][50];
    int role; // admin/dosen == 1, mahasiswa == 0
    int inboxtotal, assigned;
}login[MAX];

struct tempinfo
{
    char 
    usrname[50], 
    password[50], 
    name[50], 
    password2[50], 
    password3[50], 
    sendmsg[300],
    id[10];
}temp;

int main(){
    printf("\n\n===============Academic Information System===============\n");
    printf("========Please enter your username and password.=========\n");
    init();
    signin();

    return 0;

}

void init(){
    for(int x = 0; x<MAX; x++){
        login[x].inboxtotal = 0;
        login[x].assigned = 0;
    }
    strcpy(login[0].usrname, "admin123");
    strcpy(login[0].password, "oqwieoi");
    strcpy(login[0].name, "Admin");
    strcpy(login[0].id, "1111111111");
    login[0].role = 1;
    strcpy(login[1].usrname, "muhamad.alif");
    strcpy(login[1].password, "ygjauwv");
    strcpy(login[1].name, "Muhamad Alif Daniswara");
    strcpy(login[1].id, "1906384176");
    strcpy(login[1].course[0][0], "Dasar Komputer\n");
    strcpy(login[1].course[0][1], "ENEE603014 - 648306\n");
    strcpy(login[1].course[0][2], "Nilai = A+\n");
    login[1].assigned = 1;
    login[1].role = 0;
    strcpy(login[2].usrname, "bilal.hazim");
    strcpy(login[2].password, "nqkqrvg");
    strcpy(login[2].name, "Bilal Hazim Karimdi");
    strcpy(login[2].id, "2222222222");
    strcpy(login[2].course[0][0], "Dasar Komputer\n");
    strcpy(login[2].course[0][1], "ENEE603014 - 648306\n");
    strcpy(login[2].course[0][2], "Nilai = A+\n");
    login[2].role = 0;
    strcpy(login[3].usrname, "fakhri.putra");
    strcpy(login[3].password, "testing");
    strcpy(login[3].name, "Fakhri Putra Laksono");
    strcpy(login[3].id, "3333333333");
    strcpy(login[3].course[0][0], "Dasar Komputer\n");
    strcpy(login[3].course[0][1], "ENEE603014 - 648306\n");
    strcpy(login[3].course[0][2], "Nilai = A+\n");
    login[2].role = 0;

}

void signin(){
    if(limit >= limitn)
    {
        printf("\n\n///////////////////////");
        printf("\nMaximum attempt reached");
        printf("\n///////////////////////");
        return;
    }
    printf("\n\nDoesn't have an account yet? \nenter \"1\" in the username field below.\n");
    printf("Username : ");
    scanf("%s", temp.usrname);
    if(temp.usrname[0] == '1')
    {
        signup();   
    }
    else if(strlen(temp.usrname) < 8)
    {
        printf("\n------------------------------------------------------");
        printf("\n(!)username must contain at least 8 characters or more");
        printf("\n------------------------------------------------------");
        getchar();
        signin();
    }
    else if (strlen(temp.usrname) > 50)
    {
        printf("\n--------------------------------------------");
        printf("\n(!)username can't be more than 50 characters");
        printf("\n--------------------------------------------");
        getchar();
        signin();
    }
    scan();
}

void signup(){

    printf("contact admin for registration");
    getch();
    mhs_mainmenu();
}
void scan(){

for(int j = 0; j<=MAX; j++){
    if(!strcmp(temp.usrname, login[j].usrname)){
        i = j;
        password();
        return;
    }
    else if(j == MAX){
        printf("\nusername doesn't match our database");
        printf("\n%d attempt(s) left", (limitn - limit - 1));
        limit++;
        signin();
    }
}

}

void password(){

    while(limit <= limitn)
    {       
        printf("Password : ");
        scanf("%s", temp.password);
        if(!strcmp(temp.password, login[i].password))
        {
            if(chgpw == 1)
            {
                changepw();
                return;
            }
            else
            mhs_mainmenu();
            return;
        }
        else
        {
        printf("\nWrong password");
        printf("\n%d attempt(s) left\n", (limitn - limit));
        limit++;
        password();
        }
    }
    printf("\n\n///////////////////////");
    printf("\nMaximum attempt reached");
    printf("\n///////////////////////");
    return;
}

void mhs_mainmenu(){

    int menu, x, y, z;
    printf("\n\n===============================");
    printf("\nWelcome, %s", login[i].name);
    printf("\n===============================\n\n");
    printf("1. Change Password");
    printf("\n2. See/Send message");
    printf("\n3. Course(s) details");
    printf("\n4. Addition calculator");
    printf("\n5. Subtraction calculator");
    printf("\n6. Logout");
    printf("\n===============================");
    printf("\nEnter your option\n");
    scanf("%d", &menu);

    switch (menu)
    {
    case 1:
        printf("\nEnter your old ");
        chgpw = 1;
        password();
        break;
    case 2:
        printf("\n(!)  WARNING  (!)");
        printf("\nMessage you send or recieve will be gone at 11:59 PM");
        printf("\ndue to how the system works.");
        printf("\nMake sure to save important message.");
        printf("\nSorry for the inconvenience.");
        printf("\n=========================================================\n");
        msg();
        break;
    case 3:
        course();
    case 4:
        printf("Enter first number : ");
        scanf("%d", &x);
        printf("Enter second number : ");
        scanf("%d", &y);
        printf("%d + %d = %d", x, y, calc(x,y));
        getch();
        mhs_mainmenu();
    case 5:
        printf("Enter first number : ");
        scanf("%d", &x);
        printf("Enter second number : ");
        scanf("%d", &y);
        calc2(&x, &y, &z);
        printf("%d - %d = %d", x, y, z);
        getch();
        mhs_mainmenu();
    case 6:
        limit = 0;
        signin();
    default:
        printf("Invalid input!");
        mhs_mainmenu();
        break;
    }
}

void changepw(){
    
    printf("\n\nEnter your new password : ");
    scanf("%s", temp.password);
    strcpy(login[i].password, temp.password);
    printf("Your new password is now %s", login[i].password);
    chgpw = 0;
    getch();
    mhs_mainmenu();
    return;
}

void msg(){
    int option;
    printf("\n1. Inbox");
    printf("\n2. Send a message");
    printf("\n3. Empty my inbox");
    printf("\n4. Back\n");
    printf("\nEnter your option\n");
    scanf("%d", &option);

    switch (option)
    {
    case 1:
        printf("You have %d message(s)", login[i].inboxtotal);
        for(int x = 0; x<login[i].inboxtotal; x++)
        {
            printf("\n\n==============================");
            printf("\n%s", login[i].inbox[x]);
            printf("\n==============================\n");
        }
            getch();
            msg();
        break;
    case 2:
        sendmsg();
        break;
    case 3:
        memset(login[i].inbox, 0, sizeof login[i].inbox);
        login[i].inboxtotal = 0;
        printf("Emptied!\n");
        printf("you now have %d message\n", login[i].inboxtotal);
        msg();
    case 4:
        mhs_mainmenu();
    default:
        printf("Invalid input!");
        msg();
        break;
    }
}

void sendmsg(){
    
    int target, l = 0;
    char header[20] = "From : ";
    printf("Recipient(use ID) : ");
    scanf("%s", temp.id);
    for(j = 0; j<=MAX; j++){
    if(!strcmp(temp.id, login[j].id)){
        printf("message will be sent to : %s", login[j].name);
        printf("\nEnter the message you'd like to send : \n");
        scanf(" %[^\n]%*c", temp.sendmsg);
        strcat(header, login[i].name);
        strcat(header, "\n\n");
        strcat(header, temp.sendmsg);
        strcpy(login[j].inbox[login[j].inboxtotal], header);
        login[j].inboxtotal += 1;
        printf("==========================================\n");
        printf("Message sent!");
        getch();
        msg();
        return;
    }
    else if(j == MAX){
    printf("\nID doesn't match our database");
    sendmsg();
    }
    }
    
}

void course(){

for(int x = 0; x<login[i].assigned; x++)
{   
    printf("%d. ", (x+1));
    for(int y = 0; y<3; y++)
    {
        printf("%s",login[i].course[x][y]);
        if(y == 3)
				{
					printf("\n");
				}
    }
}
getch();
mhs_mainmenu();
return;
}

int calc(int a, int b)
{
    return a+b;
}

void calc2(int *x, int *y, int *z)
{
    *z = *x - *y;
}