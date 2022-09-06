#include<stdio.h>
#include<conio.h>
#include<windows.h>


struct evil{
        int row;
        int col;
}mx[10];
int flag=0;

void GameDisplay(int a[3][3],char p1[20],char p2[20]);
void gamePlay(int a[3][3],int player,char p1[20],char p2[20]);
void checkResult(int a[3][3],char p1[20],char p2[20]);
int minMax(int [3][3] , int);
int smartMove(int a[3][3],int isEvil);
int MM_winCheck(int b[3][3]);
void smartComputer(int a[3][3]);
void evilComputer(int a[3][3]);
int remainMvs(int b[3][3]);
int main()
{
	int a[3][3]={1,2,3,4,5,6,7,8,9};

start:system("cls");
    int choice;
    HANDLE color=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(color,10);
    printf("\nEnter Your Choice:\n");
    SetConsoleTextAttribute(color,14);
    printf("1. Want to Play With Smart Computer\n");
    SetConsoleTextAttribute(color,15);
    printf("2. Want to Play With Evil Computer\n");
    SetConsoleTextAttribute(color,14);
    printf("3. Want to Play With Your Friend\n");
    SetConsoleTextAttribute(color,10);
    printf("4. Exit.\n");

    char p1[20],p2[20],ch;
    ch=getch();

  switch(ch)
    {
        case '1':
                system("cls");
                smartComputer(a);
                break;
        case '2':
                system("cls");
                evilComputer(a);
                break;
        case '3':
                system("cls");
                SetConsoleTextAttribute(color,10);
                printf("\nEnter Player_1 Name: \n");
                SetConsoleTextAttribute(color,14);
                fgets(p1,20,stdin);
                p1[strlen(p1)-1]='\0';
                SetConsoleTextAttribute(color,10);
                printf("\nEnter Player_2 Name: \n");
                SetConsoleTextAttribute(color,14);
                fgets(p2,20,stdin);
                p2[strlen(p2)-1]='\0';
                gamePlay(a,0,p1,p2);
                break;
        case '4':
                exit(0);
        default:
            SetConsoleTextAttribute(color,12);
            printf("\nSorry!!!!!! Invalid Choise.\nPlease select valid choise.");
            getch();
            goto start;
    }
     return 0;
}
//Code For Game Play.
void gamePlay(int a[3][3],int player,char p1[20],char p2[20])
{
    int plr=0;
    system("cls");
    GameDisplay(a,p1,p2);
loop:while(1)
    {
        HANDLE color=GetStdHandle(STD_OUTPUT_HANDLE);
        char ch=getch();
        switch(ch)
        {
            case '1':
                if(a[0][0]!='X'&&a[0][0]!='O')
                    {
                        if(plr==0&&player!=1)
                        {
                            plr = 1;
                            a[0][0]='X';
                            system("cls");
                            GameDisplay(a,p1,p2);
                            checkResult(a,p1,p2);
                        break;
                        }else
                            {
                                plr = 0;
                                a[0][0]='O';
                                system("cls");
                                GameDisplay(a,p1,p2);
                                checkResult(a,p1,p2);
                                break;
                            }
                    }
                else
                {
                        SetConsoleTextAttribute(color,4);
                        printf("\nError!!!!\nThis Place Already Filled.\nPlease Choose Another Place.\n\nPress Any Key To Continue Game.");
                        getch();
                        SetConsoleTextAttribute(color,10);
                        printf("\nGame Resumed..");
                        goto loop;
                }

                case '2':
                if(a[0][1]!='X'&&a[0][1]!='O')
                    {
                        if(plr==0&&player!=1)
                        {
                            plr = 1;
                            a[0][1]='X';
                            system("cls");
                            GameDisplay(a,p1,p2);
                            checkResult(a,p1,p2);
                        break;
                        }else
                            {
                                plr = 0;
                                a[0][1]='O';
                                system("cls");
                                GameDisplay(a,p1,p2);
                                checkResult(a,p1,p2);
                                break;
                            }
                    }
                else
                {
                        SetConsoleTextAttribute(color,4);
                        printf("\nError!!!!\nThis Place Already Filled.\nPlease Choose Another Place.\n\nPress Any Key To Continue Game.");
                        getch();
                        SetConsoleTextAttribute(color,10);
                        printf("\nGame Resumed..");
                        goto loop;
                }

                case '3':
                if(a[0][2]!='X'&&a[0][2]!='O')
                    {
                        if(plr==0&&player!=1)
                        {
                            plr = 1;
                            a[0][2]='X';
                            system("cls");
                            GameDisplay(a,p1,p2);
                            checkResult(a,p1,p2);
                        break;
                        }else
                            {
                                plr = 0;
                                a[0][2]='O';
                                system("cls");
                                GameDisplay(a,p1,p2);
                                checkResult(a,p1,p2);
                                break;
                            }
                    }
                else
                {
                        SetConsoleTextAttribute(color,4);
                        printf("\nError!!!!\nThis Place Already Filled.\nPlease Choose Another Place.\n\nPress Any Key To Continue Game.");
                        getch();
                        SetConsoleTextAttribute(color,10);
                        printf("\nGame Resumed..");
                        goto loop;
                }

                case '4':
                if(a[1][0]!='X'&&a[1][0]!='O')
                    {
                        if(plr==0&&player!=1)
                        {
                            plr = 1;
                            a[1][0]='X';
                            system("cls");
                            GameDisplay(a,p1,p2);
                            checkResult(a,p1,p2);
                        break;
                        }else
                            {
                                plr = 0;
                                a[1][0]='O';
                                system("cls");
                                GameDisplay(a,p1,p2);
                                checkResult(a,p1,p2);
                                break;
                            }
                    }
                else
                {
                        SetConsoleTextAttribute(color,4);
                        printf("\nError!!!!\nThis Place Already Filled.\nPlease Choose Another Place.\n\nPress Any Key To Continue Game.");
                        getch();
                        SetConsoleTextAttribute(color,10);
                        printf("\nGame Resumed..");
                        goto loop;
                }

                case '5':
                if(a[1][1]!='X'&&a[1][1]!='O')
                    {
                        if(plr==0&&player!=1)
                        {
                            plr = 1;
                            a[1][1]='X';
                            system("cls");
                            GameDisplay(a,p1,p2);
                            checkResult(a,p1,p2);
                        break;
                        }else
                            {
                                plr = 0;
                                a[1][1]='O';
                                system("cls");
                                GameDisplay(a,p1,p2);
                                checkResult(a,p1,p2);
                                break;
                            }
                    }
                else
                {
                        SetConsoleTextAttribute(color,4);
                        printf("\nError!!!!\nThis Place Already Filled.\nPlease Choose Another Place.\n\nPress Any Key To Continue Game.");
                        getch();
                        SetConsoleTextAttribute(color,10);
                        printf("\nGame Resumed..");
                        goto loop;
                }

                case '6':
                if(a[1][2]!='X'&&a[1][2]!='O')
                    {
                        if(plr==0&&player!=1)
                        {
                            plr = 1;
                            a[1][2]='X';
                            system("cls");
                            GameDisplay(a,p1,p2);
                            checkResult(a,p1,p2);
                        break;
                        }else
                            {
                                plr = 0;
                                a[1][2]='O';
                                system("cls");
                                GameDisplay(a,p1,p2);
                                checkResult(a,p1,p2);
                                break;
                            }
                    }
                else
                {
                        SetConsoleTextAttribute(color,4);
                        printf("\nError!!!!\nThis Place Already Filled.\nPlease Choose Another Place.\n\nPress Any Key To Continue Game.");
                        getch();
                        SetConsoleTextAttribute(color,10);
                        printf("\nGame Resumed..");
                        goto loop;
                }

                case '7':
                if(a[2][0]!='X'&&a[2][0]!='O')
                    {
                        if(plr==0&&player!=1)
                        {
                            plr = 1;
                            a[2][0]='X';
                            system("cls");
                            GameDisplay(a,p1,p2);
                            checkResult(a,p1,p2);
                        break;
                        }else
                            {
                                plr = 0;
                                a[2][0]='O';
                                system("cls");
                                GameDisplay(a,p1,p2);
                                checkResult(a,p1,p2);
                                break;
                            }
                    }
                else
                {
                        SetConsoleTextAttribute(color,4);
                        printf("\nError!!!!\nThis Place Already Filled.\nPlease Choose Another Place.\n\nPress Any Key To Continue Game.");
                        getch();
                        SetConsoleTextAttribute(color,10);
                        printf("\nGame Resumed..");
                        goto loop;
                }

                case '8':
                if(a[2][1]!='X'&&a[2][1]!='O')
                    {
                        if(plr==0&&player!=1)
                        {
                            plr = 1;
                            a[2][1]='X';
                            system("cls");
                            GameDisplay(a,p1,p2);
                            checkResult(a,p1,p2);
                        break;
                        }else
                            {
                                plr = 0;
                                a[2][1]='O';
                                system("cls");
                                GameDisplay(a,p1,p2);
                                checkResult(a,p1,p2);
                                break;
                            }
                    }
                else
                {
                        SetConsoleTextAttribute(color,4);
                        printf("\nError!!!!\nThis Place Already Filled.\nPlease Choose Another Place.\n\nPress Any Key To Continue Game.");
                        getch();
                        SetConsoleTextAttribute(color,10);
                        printf("\nGame Resumed..");
                        goto loop;
                }

                case '9':
                if(a[2][2]!='X'&&a[2][2]!='O')
                    {
                        if(plr==0&&player!=1)
                        {
                            plr = 1;
                            a[2][2]='X';
                            system("cls");
                            GameDisplay(a,p1,p2);
                            checkResult(a,p1,p2);
                        break;
                        }else
                            {
                                plr = 0;
                                a[2][2]='O';
                                system("cls");
                                GameDisplay(a,p1,p2);
                                checkResult(a,p1,p2);
                                break;
                            }
                    }
                else
                {
                        SetConsoleTextAttribute(color,4);
                        printf("\nError!!!!\nThis Place Already Filled.\nPlease Choose Another Place.\n\nPress Any Key To Continue Game.");
                        getch();
                        SetConsoleTextAttribute(color,10);
                        printf("\nGame Resumed..");
                        goto loop;
                }
            }
            if(player==1)
                break;
    }
}
//Code For Smart Computer.
void smartComputer(int a[3][3])
{
    HANDLE color=GetStdHandle(STD_OUTPUT_HANDLE);
    char p2[20]="Computer",p1[20];
     SetConsoleTextAttribute(color,13);
    printf("\nEnter Player_ Name: \n");
     SetConsoleTextAttribute(color,9);
    fgets(p1,20,stdin);
    p1[strlen(p1)-1]='\0';
   while(1)
    {
        gamePlay(a,1,p1,p2);
        smartMove(a,0);
        system("cls");
        checkResult(a,p1,p2);
    }
}
//Code For Cheater Computer.
void evilComputer(int a[3][3])
{
    HANDLE color=GetStdHandle(STD_OUTPUT_HANDLE);
    char p2[20]="Computer",p1[20];
    SetConsoleTextAttribute(color,9);
    printf("\nEnter Player_ Name: \n");
    SetConsoleTextAttribute(color,10);
    fgets(p1,20,stdin);
    p1[strlen(p1)-1]='\0';

  while(1)
    {
        gamePlay(a,1,p1,p2);
        int isWin = smartMove(a,1);
        if(isWin==1)
            smartMove(a,0);
        else smartMove(a,2);
        system("cls");
        checkResult(a,p1,p2);
    }
}
//Code For Game Results.
void checkResult(int a[3][3],char p1[20],char p2[20])
{
    char y;

    int str=strcmp("Computer",p2);

    HANDLE color=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(color,14);
    if(a[0][0]=='X'&&a[0][1]=='X'&&a[0][2]=='X'||a[1][0]=='X'&&a[1][1]=='X'&&a[1][2]=='X'||a[2][0]=='X'&&a[2][1]=='X'&&a[2][2]=='X'||a[0][0]=='X'&&a[1][0]=='X'&&a[2][0]=='X'||a[1][1]=='X'&&a[0][1]=='X'&&a[2][1]=='X'||a[2][2]=='X'&&a[1][2]=='X'&&a[0][2]=='X'||a[0][0]=='X'&&a[1][1]=='X'&&a[2][2]=='X'||a[2][0]=='X'&&a[1][1]=='X'&&a[0][2]=='X')
        {
            printf("\n\t-----GAME OVER-----\n\tPress any key to see results.");
            getch();
            system("cls");
            if(str==0)
                printf("\n\n\n\t %s WON!!!!!!!!!",p2);
            else
                printf("\n\n\n\t %s WON!!!!!!!!!",p1);
            getch();
            system("cls");

            printf("\n\n\n\tDo you want to restart the game...\n\tIf yes Press Y otherwise N  ");
            y=getch();
            if(y=='y'||y=='Y')
            {
                system("cls");
                main();
            }
            else
                exit(0);
        }else
            if(a[0][0]=='O'&&a[0][1]=='O'&&a[0][2]=='O'||a[1][0]=='O'&&a[1][1]=='O'&&a[1][2]=='O'||a[2][0]=='O'&&a[2][1]=='O'&&a[2][2]=='O'||a[0][0]=='O'&&a[1][0]=='O'&&a[2][0]=='O'||a[1][1]=='O'&&a[0][1]=='O'&&a[2][1]=='O'||a[2][2]=='O'&&a[1][2]=='O'&&a[0][2]=='O'||a[0][0]=='O'&&a[1][1]=='O'&&a[2][2]=='O'||a[2][0]=='O'&&a[1][1]=='O'&&a[0][2]=='O')
        {
            printf("\n\t-----GAME OVER-----\n\tPress any key to see results.");
            getch();
            system("cls");
            SetConsoleTextAttribute(color,13);
            if(str==0)
                printf("\n\n\n\t %s WON!!!!!!!!!",p1);
            else
                printf("\n\n\n\t %s WON!!!!!!!!!",p2);

            getch();
            system("cls");

            SetConsoleTextAttribute(color,15);
            printf("\n\n\n\tDo you want to restart the game...\n\tIf yes Press Y otherwise N  ");
            y=getch();
            if(y=='y'||y=='Y')
            {
                system("cls");
                main();
            }
            else
                exit(0);
        }
            else
            {
                int k=0;
                  for (int i = 0; i<3; i++)
                {
                    for (int j = 0; j<3; j++)
                    {
                        if (a[i][j]!=(3*i)+j+1)
                        {
                            k++;
                        }
                    }
                }

                if(k==9)
                {
                    system("cls");
                    SetConsoleTextAttribute(color,10);
                    printf("\n\t-----GAME OVER-----\n\tPress any key to see results.");
                    getch();
                    printf("\n\n\n\tGame DRAW!!!!!");
                    getch();
                    system("cls");

                    printf("\n\n\n\tDo you want to restart the game...\n\tIf yes Press Y otherwise N  ");
                    y=getch();
                    if(y=='y'||y=='Y')
                    {
                        system("cls");
                        main();
                    }
                    else
                        exit(0);
                }
            }
}
//Code For Check Remaining Moves.
int remainMvs(int a[3][3])
{
	for (int i = 0; i<3; i++)
		for (int j = 0; j<3; j++)
			if (a[i][j]==(3*i)+j+1)
				return 1;
	return 0;
}
//Code For Check Row/Column/diagonal winning by computer.
int MM_winCheck(int a[3][3])
{
	// Checking for Rows winning.
	for (int i = 0; i<3; i++)
	{
		if (a[i][0]==a[i][1] &&
			a[i][1]==a[i][2])
		{
			if (a[i][0]=='X')
				return +10;
			else if (a[i][0]=='O')
				return -10;
		}
	}

	// Checking for Columns WINNING.
	for (int j = 0; j<3; j++)
	{
		if (a[0][j]==a[1][j] &&
			a[1][j]==a[2][j])
		{
			if (a[0][j]=='X')
				return +10;

			else if (a[0][j]=='O')
				return -10;
		}
	}

	// Checking for principal Diagonals winning.
	if (a[0][0]==a[1][1] && a[1][1]==a[2][2])
	{
		if (a[0][0]=='X')
			return +10;
		else if (a[0][0]=='O')
			return -10;
	}

	// Checking for OFF Diagonals winning.
	if (a[0][2]==a[1][1] && a[1][1]==a[2][0])
	{
		if (a[0][2]=='X')
			return +10;
		else if (a[0][2]=='O')
			return -10;
	}

	// FOR NOTHING HAPPEN.
	return 0;
}
//Code For Analyse All Posibilities by Computer.
int minimax(int a[3][3], int plar)
{
	int winChek = MM_winCheck(a);

	// if 'X' wins.
	if (winChek == 10)
		return winChek;

	//if 'O' wins.
	if (winChek == -10)
		return winChek;

	//for draw.
	if (remainMvs(a)==0)
		return 0;

	// 'X' move
	if (plar==1)
	{
		int winValue = -108;

		for (int i = 0; i<3; i++)
		{
			for (int j = 0; j<3; j++)
			{
				if (a[i][j]==(3*i)+j+1)
				{
					a[i][j] = 'X';

					winValue = max( winValue,
						minimax(a,0) );

					a[i][j]=(3*i)+j+1;
				}
			}
		}
		return winValue;
	}

	// 'O' move.
	else
	{
		int winValue = 108;

		for (int i = 0; i<3; i++)
		{
			for (int j = 0; j<3; j++)
			{
				if (a[i][j]==(3*i)+j+1)
				{
					a[i][j] = 'O';

					winValue = min( winValue,
						minimax(a,1) );

						//Code to store all lose positions by Evil Computer to cheat.(row column values store in structure.)
						if(winValue==-10&&( mx[i].row==-1 && mx[i].col==-1))
                        {
                            mx[i].row=i;
                            mx[i].col=j;
                        }

					a[i][j]=(3*i)+j+1;
				}
			}
		}
		return winValue;
	}
}
//Code For Computer's Smart Move.
int smartMove(int a[3][3],int isEvil)
{
	int smartValue = -108;
	int m=-1,n=-1;
	int varValue ;
    int evil[9]={2,2,2,2,2,2,2,2,2};

	for(int i=0;i<=9;i++)
    {
        mx[i].row=-1;
        mx[i].col=-1;
    }

	for (int i = 0; i<3; i++)
	{
		for (int j = 0; j<3; j++)
		{
			if (a[i][j]==(3*i)+j+1)
			{
				a[i][j] = 'X';

				 varValue = minimax(a,0);

				a[i][j]=(3*i)+j+1;

				//Code For Smart Computer Moves.
                if(isEvil==0 &&(varValue > smartValue))
                {
                    m = i;
                    n = j;
                    smartValue = varValue;
                }else if(isEvil==1)  //Code To Store All Win,Lose & draw Position in Array.(EvilComputer)
                        {
                            for(int i=0;i<9;i++)
                                if(evil[i]==2)
                                {
                                    evil[i]=varValue;
                                    break;

                                }

                        }
                //Evil Computer Code For More than One Lose Position Fill by Computer.
                    if(isEvil==2)
                    {
                        if((mx[i].row!=0||mx[i].col!=0))
                        {
                            a[mx[i].row][mx[i].col]='X';
                       } }
			}
		}
	}
                   a[m][n]='X';

                   //Code For Evil Computer To Return Win Or Lose Condtions.
                   if(isEvil==1)
                   {
                       int i=0;
                       for(i;i<9;i++)
                        if(evil[i]==10||evil[i]==0)
                            return 1;
                                return 0;
            }
        if(isEvil==0 )
        return 5;
}
// Code For Display Game Board.
void GameDisplay(int a[3][3],char p1[20],char p2[20])
{
     int i,j;
    HANDLE color=GetStdHandle(STD_OUTPUT_HANDLE);

    int str=strcmp("Computer",p2);
    if(str==0)
    {
     SetConsoleTextAttribute(color,9);
     printf("\n\n\n X : %-10s\n",p2);
     SetConsoleTextAttribute(color,11);
     printf(" O : %-10s",p1);
    }
    else
    {
     SetConsoleTextAttribute(color,9);
     printf("\n\n\n X : %-10s\n",p1);
     SetConsoleTextAttribute(color,11);
     printf(" O : %-10s",p2);
    }

SetConsoleTextAttribute(color,12);
printf("\n\n\n\n\n-----------------------------TIC TAC TOE-------------------------------\n\n");
SetConsoleTextAttribute(color,11);
printf("\n\t\t\t _________________\n");

for(i=0;i<3;i++)
{
    SetConsoleTextAttribute(color,i+10);
    printf("\t\t\t|     |     |     |\n\t\t\t|");

    for(j=0;j<3;j++)
    {
        SetConsoleTextAttribute(color,2*j+10);
        if(a[i][j]=='X'||a[i][j]=='O')
            printf("  %c  |",a[i][j]);
                else if(a[i][j]=='X'||a[i][j]=='O')
                    printf("  %c  |",a[i][j]);
                    else if(a[i][j]=='X'||a[i][j]=='O')
                        printf("  %c  |",a[i][j]);
                        else if(a[i][j]=='X'||a[i][j]=='O')
                            printf("  %c  |",a[i][j]);
                            else if(a[i][j]=='X'||a[i][j]=='O')
                                printf("  %c  |",a[i][j]);
                                else if(a[i][j]=='X'||a[i][j]=='O')
                                    printf("  %c  |",a[i][j]);
                                    else if(a[i][j]=='X'||a[i][j]=='O')
                                        printf("  %c  |",a[i][j]);
                                        else if(a[i][j]=='X'||a[i][j]=='O')
                                            printf("  %c  |",a[i][j]);
                                            else
                                                printf("  %d  |",a[i][j]);



        }
        SetConsoleTextAttribute(color,11);
        printf("\n\t\t\t|_____|_____|_____|\n");
    }
    SetConsoleTextAttribute(color,12);
 printf("\n\n\n-----------------------------TIC TAC TOE-------------------------------\n\n");
 SetConsoleTextAttribute(color,6);
if(flag==0)
 {
     printf("\n\n\tNOW %s's TURN -->\n",p1);
     flag=1;
 }

 else
 {
      printf("\n\n\tNOW %s's TURN -->\n",p2);
      flag=0;
 }

}
