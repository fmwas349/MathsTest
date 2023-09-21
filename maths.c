#include<stdio.h>
#include<stdlib.h>
#include "time.h"
void mainMenu();void ask_question(int min_num,int max_num);void calculateGrade(int score);int checkAnswer(char c,int num1,int num2);
int random(int lower, int upper);char generateOperator();
void main(){
    int choice;
    while (1) {
        mainMenu();
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Easy mode selected\n");
                ask_question(1,10);
                break;
            case 2:
                printf("Medium mode selected\n");
                ask_question(1,25);
                break;
            case 3:
                printf("Hard mode selected\n");
                ask_question(1,50);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice, enter 1, 2 or 3.\n");}}}
void ask_question(int min_num,int max_num){
    int answer=0,score=0,lives =0,questions=0;
    if (max_num==10){questions=5,lives=3;
        for(int i=1;i<=questions;i++){
            int no1= random(min_num,max_num);
            srand(time(NULL));
            int no2= random(min_num,max_num);
            if(lives<1){printf("Out of lives, game over!\n");
                break;}
            char op=generateOperator();
            if(i<questions){
            if(lives>1) {printf("Question %d of 5. You have %d lives remaining\nWhat is %d %c %d?", i, lives, no1, op, no2);
            }else{printf("Question %d of 5. You have %d life remaining\nWhat is %d %c %d?", i, lives, no1, op, no2);
            }}else{no1=random(max_num,max_num*2);
                no2=random(max_num,max_num*2);
                if(lives>1) {printf("Question %d of 5. You have %d lives remaining\nChallenge question\nWhat is %d %c %d?", questions, lives, no1, op, no2);
                }else{printf("Question %d of 5. You have %d life remaining\nChallenge question\nWhat is %d %c %d?", questions, lives,no1 , op, no2);}}
            scanf("%d",&answer);
            if(checkAnswer(op,no1,no2)==answer){
                printf("Correct!\n");score++;}
            else{printf("Incorrect!! The correct answer was %d\n", checkAnswer(op,no1,no2));
                lives--;}}
        printf("Test complete.\nYou scored %d/%d (%d)\nYour grade is :",score,questions,(score*100)/5);
        calculateGrade((score*100)/5);
        lives=0;
        printf("\n\nWish to start again?");}
    if(max_num==25){questions=10,lives=2;
        for(int i=1;i<=questions;i++){int no1= random(min_num,max_num),no2= random(min_num,max_num);
            if(lives<1){printf("Out of lives, game over!\n");
                break;}
            char op=generateOperator();
            if(i<questions){if(lives>1) {printf("Question %d of 10. You have %d lives remaining\nWhat is %d %c %d?", i, lives, no1, op, no2);}
                else{printf("Question %d of 10 You have %d life remaining\nWhat is %d %c %d?", i, lives, no1, op, no2);}}
            else{no1= random(max_num,max_num*2);
               no2=random(max_num,max_num*2);
                if(lives>1) {printf("Question %d of 10. You have %d lives remaining\nChallenge question\nWhat is %d %c %d?", questions, lives, no1, op, no2);
                }else{printf("Question %d of 10. You have %d life remaining\nChallenge question\nWhat is %d %c %d?", questions, lives, no1, op, no2);}}
            scanf("%d",&answer);
            if(checkAnswer(op,no1,no2)==answer){
                printf("Correct!\n");score++;
            }else{printf("Incorrect!! The correct answer was %d\n", checkAnswer(op,no1,no2));
                lives--;}}
        printf("Test complete.\nYou scored %d/%d (%d)\nYour grade is :",score,questions,(score*100)/10);calculateGrade((score*100)/10);
        lives=0;
        printf("\n\nWish to start again?");}
    else if(max_num==50){questions=15,lives=1;
        for(int i=1;i<=questions;i++){
            int no1= random(min_num,max_num),no2= random(min_num,max_num);
            if(lives<1){printf("Out of lives, game over!\n");
                break;}
            char op=generateOperator();
            if(i<questions){
                printf("Question %d of 15. You have %d life remaining\nWhat is %d %c %d?", i, lives, no1, op, no2);}
                else{no1= random(max_num,max_num*2);
                no2= random(max_num,max_num*2);
                    printf("Question %d of 15. You have %d life remaining\nChallenge question\nWhat is %d %c %d?", questions, lives,no1, op, no2);}
            scanf("%d",&answer);
            if(checkAnswer(op,no1,no2)==answer){printf("Correct!\n");score++;}
            else{printf("Incorrect!! The correct answer was %d\n", checkAnswer(op,no1,no2));
                lives--;}}
        printf("Test complete.\nYou scored %d/%d (%d)\nYour grade is :",score,questions,(score*100)/15);
        calculateGrade((score*100)/10);
        lives=0;
        printf("\n\nWish to start again?");}}
int random(int lower,int upper) {
    //srand(time(NULL));// seed value of pseudo-random number generator
    int number=(rand() %(upper-lower+1))+lower;
    return number;}
void calculateGrade(int sc){
    switch (sc) {
        case 80 ... 100:
            printf("High distinction\n");
            break;
        case 70 ... 79:
            printf("Distinction\n");
            break;
        case 60 ... 69:
            printf("Credit\n");
            break;
        case 50 ... 59:
            printf("Pass\n");
            break;
        case 0 ... 49:
            printf("Fail\n");
            break;
        default:;
    }
}
char generateOperator() {char operators[2]={'+','-'};   //array of operators
    char operator=operators[rand()%2]; //randomly gives an operator when the function is called
    return operator;}
int checkAnswer(char ch,int num1,int num2){
   int calc= ( ch=='+'?num1+num2:ch=='-'?num1-num2:0 );
    return calc;}
void mainMenu() {printf("\n\nWelcome to Maths Tester Pro\nSelect a difficulty\n1) Easy\n2) Medium\n3) Hard\n4) Exit\n");}


void forkMessage(){
printf("This is a forked repo");
}

