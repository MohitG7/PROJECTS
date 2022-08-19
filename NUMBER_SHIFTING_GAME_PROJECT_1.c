#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <time.h>

void printmtrx(int []);
void randam();
int chkResult(int);
void gameStart(char []);
void gameRules();
void wlcmScrn();
void gotoxy(int,int);
int a[16];

int main()
{
    wlcmScrn();
// Code to store player name.

    char name[30];
    HANDLE color=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(color,11);
    printf("Enter Player Name: ");
    fgets(name,30,stdin);
    name[strlen(name)-1]='\0';
    system("cls");

        gameRules();
        system("cls");
        gameStart(name);

    return 0;
}

//welcome screen code
void wlcmScrn()
{
    HANDLE color=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(color,14);
    printf("\n\t>>>>> WELCOME INTO THE GAME <<<<<\n\n\t    --Press Any Key To Play--  ");
    getch();
    system("cls");
}
//Code to control curser position in console screen.
void gotoxy(int x,int y)
{
    COORD c;
    c.X=x;
    c.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
}

//Code to start game.
void gameStart(char name[])
{
    HANDLE color=GetStdHandle(STD_OUTPUT_HANDLE);
    int i=15,temp,count=0,mvs=500;

    SetConsoleTextAttribute(color,FOREGROUND_RED|FOREGROUND_GREEN);
    printf("           \n\t\t\t\t\tHello, %s",name);
    SetConsoleTextAttribute(color,15);
    printf("           \n\t\t\t\t\tTotal Moves    : 500");
    SetConsoleTextAttribute(color,10);
    printf("           \n\t\t\t\t\tRemaining Moves: %3d",mvs);

    randam();
    printmtrx(a);
    printf("\n\tPress arrow keys..");

//Code for arrow key and swapping of values.
    while(1)
    {
        char ch=getch();
        switch(ch)
        {
        case 77://for right arrow
a:
            temp=a[i];
            a[i]=a[i-1];
            a[i-1]=temp;
            if(count==1)
            {
                count=0;
                break;
            }
            i=i-1;
            if(i==-1||i==3||i==7||i==11)
            {
                SetConsoleTextAttribute(color,12);
                printf("Press Another Key.\nThis Side No More Space To Shift Number.\n");
                i=i+1;
                system("pause");
                SetConsoleTextAttribute(color,10);
                printf("Game Resumed.");
                count++;
                goto a;
            }
            system("cls");
            mvs--;
            SetConsoleTextAttribute(color,FOREGROUND_RED|FOREGROUND_GREEN);
            printf("           \n\t\t\t\t\tHello, %s",name);
            SetConsoleTextAttribute(color,15);
            printf("           \n\t\t\t\t\tTotal Moves    : 500");
            SetConsoleTextAttribute(color,10);
            printf("           \n\t\t\t\t\tRemaining Moves: %3d",mvs);
            chkResult(mvs);
            printmtrx(a);
            break;
        case 75://for left arrow
d:
            temp=a[i];
            a[i]=a[i+1];
            a[i+1]=temp;
            if(count==1)
            {
                count=0;
                break;
            }
            i=i+1;
            if(i==4||i==8||i==12||i==16)
            {
                SetConsoleTextAttribute(color,12);
                printf("Press Another Key.\nThis Side No More Space To Shift Number.\n");
                i=i-1;
                system("pause");
                SetConsoleTextAttribute(color,10);
                printf("Game Resumed.");
                count++;
                goto d;
            }
            system("cls");
            mvs--;
            SetConsoleTextAttribute(color,FOREGROUND_RED|FOREGROUND_GREEN);
            printf("           \n\t\t\t\t\tHello, %s",name);
            SetConsoleTextAttribute(color,15);
            printf("           \n\t\t\t\t\tTotal Moves    : 500");
            SetConsoleTextAttribute(color,10);
            printf("           \n\t\t\t\t\tRemaining Moves: %3d",mvs);
            chkResult(mvs);
            printmtrx(a);
            break;

        case 80://for lower arrow
            temp=a[i];
            a[i]=a[i-4];
            a[i-4]=temp;
            i=i-4;
            if(i<0)
            {
                SetConsoleTextAttribute(color,12);
                printf("Press Another Key.\nThis Side No More Space To Shift Number.\n");
                i=i+4;
                system("pause");
                SetConsoleTextAttribute(color,10);
                printf("Game Resumed.");
            }
            system("cls");
            mvs--;
            SetConsoleTextAttribute(color,FOREGROUND_RED|FOREGROUND_GREEN);
            printf("           \n\t\t\t\t\tHello, %s",name);
            SetConsoleTextAttribute(color,15);
            printf("           \n\t\t\t\t\tTotal Moves    : 500");
            SetConsoleTextAttribute(color,10);
            printf("           \n\t\t\t\t\tRemaining Moves: %3d",mvs);
            chkResult(mvs);
            printmtrx(a);
            break;

        case 72://for upper arrow
            temp=a[i];
            a[i]=a[i+4];
            a[i+4]=temp;
            if(i<=15&&i>=0)
            {
                i=i+4;
                if(i>15)
                {
                    SetConsoleTextAttribute(color,12);
                    printf("Press Another Key.\nThis Side No More Space To Shift Number.\n");
                    i=i-4;
                    system("pause");
                    SetConsoleTextAttribute(color,10);
                    printf("Game Resumed.");
                }

            }
            system("cls");
            mvs--;
            SetConsoleTextAttribute(color,FOREGROUND_RED|FOREGROUND_GREEN);
            printf("           \n\t\t\t\t\tHello, %s",name);
            SetConsoleTextAttribute(color,15);
            printf("           \n\t\t\t\t\tTotal Moves    : 500");
            SetConsoleTextAttribute(color,10);
            printf("           \n\t\t\t\t\tRemaining Moves: %3d",mvs);
            chkResult(mvs);
            printmtrx(a);
            break;

            case 'e':
            exit(0);

            case 'E':
            exit(0);

        }
    }
}

//Code to check winning or losing result.
int chkResult(int mvs)
{
    HANDLE color=GetStdHandle(STD_OUTPUT_HANDLE);

        if(a[0]==1 &&a[1]==2 &&a[2]==3 &&a[3]==4 &&a[4]==5 &&a[5]==6 &&a[6]==7 &&a[7]==8 &&a[8]==9 &&a[9]==10 &&a[10]==11 &&a[11]==12 &&a[12]==13 &&a[13]==14&&a[14]==15&& mvs>0)
        {
            SetConsoleTextAttribute(color,14);
            system("cls");
            printf("\n\n\n\tCONGTRATS You Win The Game!!!!!!!");
            getch();
            system("cls");
            goto restart;
        }
        else if(mvs==0)
            {
            char y;
            system("cls");
            SetConsoleTextAttribute(color,12);
            printf("\n\n\n\tYou LOSE !!!!.\n\tNo moves are remaining to play.");
 restart:   printf("\n\n\n\tDo you want to restart the game...\n\tIf yes Press Y otherwise N  ");
            y=getch();
            if(y=='y'||y=='Y')
            {
                system("cls");
                main();
            }
            else
                exit(0);
            }
            else return 1;
}

//Code to Update random values of game.
void randam()
{
    int min=1,max=min+14,i,j,temp;
    a[15]=0;

    srand(time(0));
    for(i=0; i<15; i++)
    {
        temp = rand()%15 + min;
        for(j=0; j<i; j++)
        {
            if(temp==a[j])
                break;
        }
        if(i==j)
        {
            a[i]=temp;
        }

        else i--;
    }
}

//Code for print values in 4*4 square matrix with structure.
void printmtrx(int a[])
{
    int j=0;
    HANDLE color=GetStdHandle(STD_OUTPUT_HANDLE);
    printf("\n\n\t-----------------------------\n");

    for(int i=0; i<=12; i+=4)
    {
        if(i<=8)
        {
            SetConsoleTextAttribute(color,j+10);
            if(a[i]==0)
                printf("\t|  %2c  |  %2d  |  %2d  |  %2d  |\n",a[i],a[i+1],a[i+2],a[i+3]);
            else if(a[i+1]==0)
                    printf("\t|  %2d  |  %2c  |  %2d  |  %2d  |\n",a[i],a[i+1],a[i+2],a[i+3]);
                else if(a[i+2]==0)
                        printf("\t|  %2d  |  %2d  |  %2c  |  %2d  |\n",a[i],a[i+1],a[i+2],a[i+3]);
                else if(a[i+3]==0)
                            printf("\t|  %2d  |  %2d  |  %2d  |  %2c  |\n",a[i],a[i+1],a[i+2],a[i+3]);
                            else
                                printf("\t|  %2d  |  %2d  |  %2d  |  %2d  |\n",a[i],a[i+1],a[i+2],a[i+3]);
            j+=4;
            if(j==8)
                j=5;
        }

        else
        {
            i=12;
            SetConsoleTextAttribute(color,11);
            if(a[i]==0)
                printf("\t|  %2c  |  %2d  |  %2d  |  %2d  |\n",a[i],a[i+1],a[i+2],a[i+3]);
            else if(a[i+1]==0)
                    printf("\t|  %2d  |  %2c  |  %2d  |  %2d  |\n",a[i],a[i+1],a[i+2],a[i+3]);
                else if(a[i+2]==0)
                        printf("\t|  %2d  |  %2d  |  %2c  |  %2d  |\n",a[i],a[i+1],a[i+2],a[i+3]);
                else if(a[i+3]==0)
                            printf("\t|  %2d  |  %2d  |  %2d  |  %2c  |\n",a[i],a[i+1],a[i+2],a[i+3]);
                            else
                                printf("\t|  %2d  |  %2d  |  %2d  |  %2d  |\n",a[i],a[i+1],a[i+2],a[i+3]);
        }
        if(i==12)
            break;

    }
    printf("\t-----------------------------\n");

}

//Code to display Rules of the game.
void gameRules()
{

        HANDLE color=GetStdHandle(STD_OUTPUT_HANDLE);
        gotoxy(20,1);
        SetConsoleTextAttribute(color,15);
        printf(">>> RULS OF THIS GAME <<<\n\n");
        SetConsoleTextAttribute(color,6);
        printf(">>\t1. You can move only 1 step at a time by arrow key.\n");
        SetConsoleTextAttribute(color,2);
        printf("\n>>\t\t Move Up   : by Up arrow key.");
        printf("\n>>\t\t Move Down : by Down arrow key.");
        printf("\n>>\t\t Move Left : by Left arrow key.");
        printf("\n>>\t\t Move Right: by Right arrow key.\n");
        SetConsoleTextAttribute(color,3);
        printf("\n>>\t2. You can move number at empty position only");
        printf("\n>>\t3. For each valid move : your total number of move will decreased by 1.\n");
        printf(">>\t4. Winning situation   : number in a 4*4 matrix should be in order from 1 to 15.\n\n");
        SetConsoleTextAttribute(color,4);
        printf("                            winning situation:\n\n");
        SetConsoleTextAttribute(color,5);
        printf("\t\t\t-------------------------\n");
        printf("\t\t\t|  1  |  2  |  3  |  4  |\n");
        printf("\t\t\t|  5  |  6  |  7  |  8  |\n");
        printf("\t\t\t|  9  |  10 |  11 |  12 |\n");
        printf("\t\t\t|  13 |  14 |  15 |     |\n");
        printf("\t\t\t-------------------------\n\n");

        SetConsoleTextAttribute(color,6);
        printf(">>\t5.You can exit the game at any time by pressing 'E' or 'e'.\n\tso try to win in minimum number of moves.\n");
        printf("                            \n\n\t\t>>>  Enjoy The Game!!! , Good Luck  <<<\n");
        SetConsoleTextAttribute(color,15);
        printf("\n\n\t\t     Enter Any Key To Start Game....");
        getch();

}

