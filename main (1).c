#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h> 

void scrumble(char demo[],char arr[], int x) {
    for(int i=0; i<x; i++) {
        srand(time(0));
        int a=rand()%x+1;
        srand(time(0));
        int n=rand()%x+1;
        int temp=arr[a-1];
        arr[a-1]=arr[n-1];
        arr[n-1]=temp;
    }
    if(strcmp(arr,demo)==0) {
        scrumble(demo,arr,x);
    }
}
void spsgame() {
    printf("                             <<Welcome to the game of STONE PAPER SCISSOR>> \n\n\n");
    int flag=1;
    printf("THE GAME CONTAIN THREE ELEMENTS STONE, PAPER AND SCISSORS .COMPUTER WILL CHOOSE ONE OF IT ELEMENT THEN IT WILL ASK YOU TO CHOOSE ANY ONE OF ELEMENT.'IF THERE IS STONE AND PAPER THEN THEN PAPER WILL WIN AS IT CATCH STONE' ,'IF THERE IS STONE AND SCISSORS THEN STONE WILL WIN AS IT WILL DISTROY SCISSORS','IF THERE IS PAPER AND SCISSORS THEN SCISSORS WILL WIN AS IT WILL CUT THE PAPER \n\n");
    printf("\n\n");
    while(flag){
        printf("The 1 represent stone\n");
        printf("The 2 represent paper\n");
        printf("The 3 represent scissor\n");    
        int b;
        printf("Enter your choice:-");
        scanf("%d",&b);
        int a;
        srand(time(0));
        a=rand()%3+1;
        if(b>3 || b<1) {
            printf("Please Enter the number in range!!!\n");
        }
        else if(b==a) {
            int c;
            printf("You have came up with same option!\nRetry!!\n");
            continue;
        }
        else if(a==1 && b==2) {
            printf("You won....\n");
        }
        else if(a==2 && b==3) {
            printf("You won....\n");
        }
        else if(a==3 && b==1) {
            printf("you won....\n");
        }
        else {
            printf("you lose....\n");
        }
        printf("You have entered:-");
        if(b==1) {
            printf("stone");
        }
        else if(b==2) {
            printf("paper");
        }
        else if(b==3) {
            printf("scissor");
        }
        printf("\n");
        printf("computer has entered:-");
        if(a==1){
            printf("stone");
        }
        else if(a==2) {
            printf("paper");
        }
        else {
            printf("scissor");
        }
        printf("\n\n\n");
        printf("if you want to continue playing :- 1 or if you want to quit :- 0 \n");
        printf("Enter the choice :-");
        scanf("%d",&flag);
    }
}
void jumblegame() {
    printf("                            <<Welcome to the game of jumbling up word>> \n\n\n");
    printf("THE COMPUTER WILL GIVE YOU A JUMBLED WORD AND YOU TO HAVE TO UNJUMBLE THE WORD \n\n");
    int x;
    int flag=1;
    while(flag) {
        char *a[]= {"earth","space","light","plant","bird","tree","rain","moon","rice","cylinder","water"};
        char arr[100];
        char demo[100];
        char ans[100];
        srand(time(0));
        int p=rand()%10 + 1;
        strcpy(arr,a[p]);
        x=strlen(arr);
        strcpy(demo,arr);
        scrumble(demo,arr,x);
        printf("\n\n");
        printf("%s\n",arr);
        printf("Please unjumble the word\n");
        printf("Enter your response here in small letter:-");        
        scanf("%s",ans);
        if(strcmp(demo,ans)==0) {
            printf("you win.....\n\n");
        }
        else {
            printf("you loose......\n\n");
        }
        printf(">>>If you want to continue playing :- 1 or if you want to quit :- 0 \n");
        printf("Enter the choice :-");
        scanf("%d",&flag);
    }
} 

void guessgame() {
    printf("                           <<Welcome to the game of guessing>>\n\n\n");
    printf("IN THIS GAME COMPUTER WILL AUTOMATICALLY CHOOSE A NUMBER FROM 1 TO 100 AND YOU HAVE TO GUESS THE NUMBER USING CLUES GIVEN BY COMPUTER 'IF YOU CORRECTLY GUESS THE CHOOSEN NUMBER IN MAXIMUM OF 10 ATTEMPT THEN YOU WIN OTHERWISE YOU WILL LOOSE THE GAME\n\n\n");
    int flag=1;
    while(flag){
        int a=0;
        srand(time(0));
        int n = rand()%100 + 1;
        int m;
        printf("\n\n");
        printf("Guess a number:-");
        int count=0;
        scanf("%d",&m);
        while(a==0) {
            if(m==n) {
                printf("correct guess and total attempt %d\n",count);
                if(count<10) {
                    printf("you won....\n");
                }
                else {
                    printf("you loose....\n");
                }
                a=1;
            }
            else if(m>n) {
                printf("your guess is greater than the actual value\n");
                printf("enter another number:-");
                scanf("%d",&m);
                count++;
            }
            else {
                printf("your guess is smaller than the actual value\n");
                printf("enter another number:-");
                scanf("%d",&m);
                count++;
            }
        }
        printf("if you want to continue playing :- 1 or if you want to quit :- 0 \n");
        printf("Enter your choice :-");
        scanf("%d",&flag);
    }
} 

int main() {
    printf("                              >>>>>>>>>>>>Welcome to ROYAL GAMES HUB<<<<<<<<<<<\n\n\n");
    int n=1;
    while(n){ 
        int choice;
        printf(" press 1 to play jumbled up word game \n press 2 to play guessing a number game \n press 3 to play stone paper scissors game \n\n\n\n");
        printf("Enter your choice:-");
        scanf("%d",&choice);
        if(choice==1) {
            jumblegame();
        }
        else if(choice==2) {
            guessgame();
        }
        else if(choice==3){
            spsgame();
        }
        printf("\n\n");
        printf("back to main manu:-1 or exit the game :-0\n");
        printf("Enter your choice:- ");
        scanf("%d",&n);
    }
}