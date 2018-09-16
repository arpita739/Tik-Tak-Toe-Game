#include<stdio.h>
#include<windows.h>
#include<stdlib.h>
#include<conio.h>
struct myDataType
{
    int i;
    char ch;
}
inputValue();

void run();
int check(char sym[16],char ch,int count);
struct myDataType inputValue(char sym[16],int count);
void Display(char sym[16]);

void main()
{    
    char reStart;
    again:
	run();
	printf("\nIf You Want To Play Again Press 1: \nElse Any:");
	scanf("%s",&reStart);
	if(reStart == '1')
        {
            system("cls");
            goto again;
        }
    else
        exit(0);
}

void run()
{
    int count = 0;
    struct myDataType info;
    char symbol[16] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p'} ;
    Display(symbol);
    again:
    info = inputValue(symbol,count);
    symbol[info.i] = info.ch;
    system("cls");
    Display(symbol);
    if(check(symbol,info.ch,count)==1);
    else{
        count++;
        goto again;
    }
}
struct myDataType inputValue(char sym[16],int count){
    char value;
    int i;
    struct myDataType info;
    inputAgain:
    if(count%2 == 0){
        printf("\nEnter Your Choice X:");
    }else{
        printf("\nEnter Your Choice O:");
    }
    scanf("%s",&value);
    for(i=0;i<16;i++){

        if(value == sym[i]){
            info.i = i;
            if(count%2 == 0)
                info.ch = 'X';
            else
                info.ch = 'O';
            break;
        }else{
            info.i = -1;
            info.ch = ' ';
        }
    }
    if(info.i == -1){
        printf("\nInput is not Valid");
        goto inputAgain;
    }
    return info;
}
int check(char sym[16],char ch,int count){
    int i;
    for(i = 0;i<=8; i+=4)//it's for row
        if(sym[i] == ch && sym[i+1]==ch&&sym[i+2]==ch && sym[i+3]==ch){
            printf("\nthe Winner is : %c",ch);return 1;
        }
    for(i = 0;i<4; i++)//it's for column
        if(sym[i]==ch && sym[i+4]==ch&&sym[i+8]==ch && sym[i+12]==ch){
            printf("\nthe Winner is : %c",ch);return 1;
        }
    if(sym[0]==ch && sym[5]==ch&&sym[10]==ch && sym[15]==ch){
            printf("\nthe Winner is : %c",ch);return 1;
        }
    else if(sym[3]==ch && sym[6]==ch && sym[9]==ch &&sym[12]==ch){
            printf("\nthe Winner is : %c",ch);return 1;
        }
    else if(count==15){
        printf("the Game is DRAW");
        return 1;
    }else 
	return 0;
}

void Display(char sym[16])
{
	printf("\t\t\t\tT i c	t a c	t o e");
	printf("\nPlayers 1 Symbol: X");
	printf("\nPlayers 2 Symbol: O");
	printf("\n\t\t\t       |       |       |     ");
	printf("\n\t\t\t   %c   |   %c   |   %c   |   %c   ",sym[0],sym[1],sym[2],sym[3]);
	printf("\n\t\t\t-------|-------|-------|-------");
	printf("\n\t\t\t   %c   |   %c   |   %c   |   %c   ",sym[4],sym[5],sym[6],sym[7]);
	printf("\n\t\t\t-------|-------|-------|-------");
	printf("\n\t\t\t   %c   |   %c   |   %c   |   %c   ",sym[8],sym[9],sym[10],sym[11]);
	printf("\n\t\t\t-------|-------|-------|-------");
	printf("\n\t\t\t   %c   |   %c   |   %c   |  %c   ",sym[12],sym[13],sym[14],sym[15]);
	printf("\n\t\t\t       |       |       |     ");
}
