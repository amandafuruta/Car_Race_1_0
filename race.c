#include "race.h"
int menu(int simbol, int simbol2){
    char s=simbol, s2=simbol2;
    int op, i;
    printf("\n\n\n\t\t\t\t");
    for(i=0; i<43; i++){
        printf("%c",s2);
    }
    
    printf("\n\t\t\t\t\t\tCAR RACING\n");
    printf("\t\t\t\t");
    for(i=0; i<43; i++){
        printf("%c",s);
    }
    printf("\n\t\t\t\t\t\t1.Novo Jogo");
    printf("\n\t\t\t\t\t\t2.High Scores");
    printf("\n\t\t\t\t\t\t3.Sair\n");
    printf("\t\t\t\t");
    for(i=0; i<43; i++){
        printf("%c",s);
    }
    printf("\n\t\t\t\tSelecione uma opcao: ");
    printf("\n\t\t\t\t");
    for(i=0; i<43; i++){
        printf("%c",s2);
    }
    scanf("%d",&op);
    
    return op;
}
void initCar(Car *race){
    race->i=24;
    race->j=7;
    race->width=5;
    race->height=4;  
}

void initObstacleRight(Car *obstacleRight){
    obstacleRight->i=0;
    obstacleRight->j=11;
    obstacleRight->width=5;
    obstacleRight->height=4;
}

void initObstacleLeft(Car *obstacleLeft){
    obstacleLeft->i=0;
    obstacleLeft->j=3;
    obstacleLeft->width=5;
    obstacleLeft->height=4;
}

void begin (char matrix[ROWS][COLUMNS]){
    int i, j;
    for (i=0; i<ROWS; i++){
        for(j=0; j<COLUMNS; j++){
            matrix[i][j]= ' ';
        }
    }
}

void printMatrix (char matrix[ROWS][COLUMNS], int simbol, int signal, int level/* , int score */){
    int i, j, n;
    char s;
    s=simbol;

    if(level==1)
        n=4;
    else
        n=2;
    /* printf("SCORE: %d", score); */
    printf("\n\n");
    printf("\t\t\t\t\t");
     for(j=0; j<=COLUMNS+3; j++){
         printf ("*");
     }
     printf("\n");

     for (i=0; i<ROWS; i++){
         printf("\t\t\t\t\t*");
         if(signal%n==0){
             if(i%2==0 )
              printf("%c",s);
             else
                printf(" ");
         }
         
         if (signal%n!=0){
             if(i%2!=0)
             printf("%c",s);
            else
             printf(" ");
         }


         for(j=0; j<COLUMNS; j++){
    
            printf("%c", matrix[i][j]);
            
         } 

         if(signal%n==0){
             if(i%2==0 ){
             printf("%c*\n",s);
            }else
            printf(" *\n");
         }
         if(signal%n!=0){
             if(i%2!=0 ){
             printf("%c*\n",s);
            }else
            printf(" *\n");
         }
     }
     printf("\t\t\t\t\t");
     for(j=0; j<=COLUMNS+3; j++){
         printf ("*");
     }
     printf("\n\n");
}


void printCar (char matrix[ROWS][COLUMNS], int simbol, Car race){
            matrix[race.i-1][race.j]=simbol;
            matrix[race.i-2][race.j]=simbol;
            matrix[race.i-2][race.j-1]=simbol;
            matrix[race.i-2][race.j-2]=simbol;
            matrix[race.i-2][race.j+1]=simbol;
            matrix[race.i-2][race.j+2]=simbol;
            matrix[race.i-3][race.j]=simbol;
            matrix[race.i][race.j-1]=simbol;
            matrix[race.i][race.j-2]=simbol;
            matrix[race.i][race.j+1]=simbol;
            matrix[race.i][race.j+2]=simbol;     
}

void printObstacle(char matrix[ROWS][COLUMNS], int simbol, Car obstacle){
    
        if(obstacle.i-1>=0)matrix[obstacle.i-1][obstacle.j]=simbol;
        if(obstacle.i-2>=0)matrix[obstacle.i-2][obstacle.j]=simbol;
        if(obstacle.i-2>=0)matrix[obstacle.i-2][obstacle.j-1]=simbol;
        if(obstacle.i-2>=0)matrix[obstacle.i-2][obstacle.j-2]=simbol;
        if(obstacle.i-2>=0)matrix[obstacle.i-2][obstacle.j+1]=simbol;
        if(obstacle.i-2>=0)matrix[obstacle.i-2][obstacle.j+2]=simbol;
        if(obstacle.i-3>=0)matrix[obstacle.i-3][obstacle.j]=simbol;
        matrix[obstacle.i][obstacle.j-1]=simbol;
        matrix[obstacle.i][obstacle.j-2]=simbol;
        matrix[obstacle.i][obstacle.j+1]=simbol;
        matrix[obstacle.i][obstacle.j+2]=simbol;

}

int collision (char matrix[ROWS][COLUMNS], Car race){
    int retorno=0;
    if(matrix[race.i-4][race.j+(race.width/2)]!=EMPTY){
        retorno=1;
    }
    if(matrix[race.i-4][race.j-(race.width/2)]!=EMPTY){
        retorno=1;
    }
    /* if(matrix [race.i-4][race.j]!=EMPTY){
        retorno=1;
    } */
    return retorno;
}