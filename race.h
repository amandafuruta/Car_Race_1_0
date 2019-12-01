#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<time.h>
#include<string.h>

#define ROWS 25
#define COLUMNS 15 //tive que diminuir para arrumar o bug- car no centro com espaço sobrando 

#define ESC 27
#define SIMBOL 178
#define EMPTY 32
#define BORDERTOP 205
#define BORDERDOWN  220

#define BUTTON_A 65
#define BUTTON_D 68
#define BUTTON_a 97
#define BUTTON_d 100
#define ARROWS 224
#define ARROW_RIGHT 77
#define ARROW_LEFT 75
#define SPACE_BAR 32

#define SCORE_CAR 50
#define  MAX_SCORE_FIRST_LVL 500
#define MAX_SCORE_SECOND_LVL 1000

typedef struct{
    int i ;
    int j ;
    int width;
}Car;

typedef struct Dados {
    char nome[60];
    int pontos;
}Data;

int menu (int simbol, int simbol2);

void initCar (Car *race);

void initObstacle (Car *obstacle, int side);

void begin (char matrix[ROWS][COLUMNS]);

void printMatrix (char matrix[ROWS][COLUMNS], int simbol, int signal , int level , int score );

void printCar (char matrix[ROWS][COLUMNS], int simbol, Car race);

void printObstacle1 (char matrix[ROWS][COLUMNS], int simbol, Car obstacle1);

void printObstacle2 (char matrix[ROWS][COLUMNS], int simbol, Car obstacle2);

void printObstacle3 (char matrix[ROWS][COLUMNS], int simbol, Car obstacle3);

int collision (char matrix[ROWS][COLUMNS], Car race);

void ranking (int simbol, int simbol2, Data *player, int score);

void highScore (int simbol, int simbol2,Data *player);