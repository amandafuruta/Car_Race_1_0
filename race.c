#include "race.h"
int menu (int simbol, int simbol2){
    char s = simbol, s2 = simbol2;
    int op, i;
    printf ("\n\n\n\t\t\t\t");
    for (i = 0; i < 43; i++){
        printf("%c",s2);
    }
    
    printf ("\n\t\t\t\t\t\tCAR RACING\n");
    printf ("\t\t\t\t");
    for (i = 0; i < 43; i++){
        printf ("%c",s);
    }
    printf ("\n\t\t\t\t\t\t1.Novo Jogo");
    printf ("\n\t\t\t\t\t\t2.High Scores");
    printf ("\n\t\t\t\t\t\t3.Sair\n");
    printf ("\t\t\t\t");
    for (i = 0; i < 43; i++){
        printf ("%c",s);
    }
    printf ("\n\t\t\t\tSelecione uma opcao: ");
    printf ("\n\t\t\t\t");
    for (i = 0; i < 43; i++){
        printf ("%c",s2);
    }

    scanf("%d",&op);

    return op;
}


void initCar(Car *race){
    race->i = 24;
    race->j = 7; 
    race->width = 5;
}

void initObstacle(Car *obstacle, int side){
    if (side) {
        obstacle->i = 0;
        obstacle->j = 11;
        obstacle->width= 5;
    }else {
        obstacle->i = 0;
        obstacle->j = 3;
        obstacle->width= 5;
    }
}

void begin (char matrix[ROWS][COLUMNS]){
    int i, j;
    for (i = 0; i < ROWS; i++){
        for (j = 0; j < COLUMNS; j++){
            matrix[i][j]= ' ';
        }
    }
}

void printMatrix (char matrix[ROWS][COLUMNS], int simbol, int signal, int level , int score ){
    int i, j, speed;
    char s;
    
    s = simbol;

    if(level==1)
        speed=4;
    else
        speed=2;

    if (score > 1 ){
        printf("SCORE: %d", score); 
    }
    
    printf("\n\n");
    printf("\t\t\t\t\t");
     for(j=0; j<=COLUMNS+3; j++){
         printf ("*");
     }
     printf("\n");

     for (i=0; i<ROWS; i++){
         printf("\t\t\t\t\t*");
         if(signal%speed==0){
             if(i%2==0 )
              printf("%c",s);
             else
                printf(" ");
         }
         
         if (signal%speed!=0){
             if(i%2!=0)
             printf("%c",s);
            else
             printf(" ");
         }


         for(j=0; j<COLUMNS; j++){
    
            printf("%c", matrix[i][j]);
            
         } 

         if(signal%speed==0){
             if(i%2==0 ){
             printf("%c*\n",s);
            }else
            printf(" *\n");
         }
         if(signal%speed!=0){
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
    
    //CARRO 3:

        if(obstacle.i < ROWS+21 ) {
            if(obstacle.i-21>=0)matrix[obstacle.i-21][obstacle.j]=simbol;
        }

        if(obstacle.i < ROWS+20 ) {
            if(obstacle.i-20>=0)matrix[obstacle.i-20][obstacle.j]=simbol;
            if(obstacle.i-20>=0)matrix[obstacle.i-20][obstacle.j-1]=simbol;
            if(obstacle.i-20>=0)matrix[obstacle.i-20][obstacle.j-2]=simbol;
            if(obstacle.i-20>=0)matrix[obstacle.i-20][obstacle.j+1]=simbol;
            if(obstacle.i-20>=0)matrix[obstacle.i-20][obstacle.j+2]=simbol;
        }

        if(obstacle.i < ROWS+19 ) {
            if(obstacle.i-19>=0)matrix[obstacle.i-19][obstacle.j]=simbol;
        }
        
        if(obstacle.i < ROWS+18 ) {
            if(obstacle.i-18>=0)matrix[obstacle.i-18][obstacle.j-1]=simbol;
            if(obstacle.i-18>=0)matrix[obstacle.i-18][obstacle.j-2]=simbol;
            if(obstacle.i-18>=0)matrix[obstacle.i-18][obstacle.j+1]=simbol;
            if(obstacle.i-18>=0)matrix[obstacle.i-18][obstacle.j+2]=simbol;
        }


        //CARRO 2:

        if(obstacle.i < ROWS+12 ) {
            if(obstacle.i-12>=0)matrix[obstacle.i-12][obstacle.j]=simbol;
        }

        if(obstacle.i < ROWS+11 ) {
            if(obstacle.i-11>=0)matrix[obstacle.i-11][obstacle.j]=simbol;
            if(obstacle.i-11>=0)matrix[obstacle.i-11][obstacle.j-1]=simbol;
            if(obstacle.i-11>=0)matrix[obstacle.i-11][obstacle.j-2]=simbol;
            if(obstacle.i-11>=0)matrix[obstacle.i-11][obstacle.j+1]=simbol;
            if(obstacle.i-11>=0)matrix[obstacle.i-11][obstacle.j+2]=simbol;
        }

        if(obstacle.i < ROWS+10 ) {
            if(obstacle.i-10>=0)matrix[obstacle.i-10][obstacle.j]=simbol;
        }
        
        if(obstacle.i < ROWS+9 ) {
            if(obstacle.i-9>=0)matrix[obstacle.i-9][obstacle.j-1]=simbol;
            if(obstacle.i-9>=0)matrix[obstacle.i-9][obstacle.j-2]=simbol;
            if(obstacle.i-9>=0)matrix[obstacle.i-9][obstacle.j+1]=simbol;
            if(obstacle.i-9>=0)matrix[obstacle.i-9][obstacle.j+2]=simbol;
        }

    //CARRO 1:

        if(obstacle.i < ROWS+3 ) {
            if(obstacle.i-3>=0)matrix[obstacle.i-3][obstacle.j]=simbol;
        }

        if(obstacle.i < ROWS+2 ) {
            if(obstacle.i-2>=0)matrix[obstacle.i-2][obstacle.j]=simbol;
            if(obstacle.i-2>=0)matrix[obstacle.i-2][obstacle.j-1]=simbol;
            if(obstacle.i-2>=0)matrix[obstacle.i-2][obstacle.j-2]=simbol;
            if(obstacle.i-2>=0)matrix[obstacle.i-2][obstacle.j+1]=simbol;
            if(obstacle.i-2>=0)matrix[obstacle.i-2][obstacle.j+2]=simbol;
        }

        if(obstacle.i < ROWS+1 ) {
            if(obstacle.i-1>=0)matrix[obstacle.i-1][obstacle.j]=simbol;
        }
        
        if(obstacle.i < ROWS ) {
            matrix[obstacle.i][obstacle.j-1]=simbol;
            matrix[obstacle.i][obstacle.j-2]=simbol;
            matrix[obstacle.i][obstacle.j+1]=simbol;
            matrix[obstacle.i][obstacle.j+2]=simbol;
        }

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