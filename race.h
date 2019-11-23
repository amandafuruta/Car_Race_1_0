#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<time.h>

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

typedef struct{
    int tipo;
    int i ;
    int j ;
    int height ;
    int width ;
}Car;

int menu(int simbol, int simbol2);

void initCar(Car *race);

void initObstacleRight(Car *obstacleRight);

void initObstacleLeft(Car *obstacleLeft);

void begin (char matrix[ROWS][COLUMNS]);

void printMatrix (char matrix[ROWS][COLUMNS], int simbol, int signal , int level/* , int score */);

void printCar (char matrix[ROWS][COLUMNS], int simbol, Car race);

void printObstacle(char matrix[ROWS][COLUMNS], int simbol, Car obstacle);

int collision (char matrix[ROWS][COLUMNS], Car race);