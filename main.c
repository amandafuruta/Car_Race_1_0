#include "race.h"
#include "display.h"

int main (){
    
    char matrix[ROWS][COLUMNS];
    int keypressed ;
    int signal=0, level, randNumber, timer=0, resp, score=0, speed;
    Car carRace;
    Car obstacle1;
    Car obstacle2;
    Car obstacle3;
    Data player;
    
    start:
    keypressed=0;

    srand(time(NULL));
    begin (matrix);
    initCar(&carRace);
    
    ShowConsoleCursor(0);
    system ("cls");
    
    resp= menu ( BORDERTOP, BORDERDOWN );

    system("CLS");
    
    switch(resp){
        case 1:
            while (keypressed != ESC){
            signal++;
            
        //DETERMINA O LEVEL DE ACORDO COM A PONTUAÇÃO
            if( score < MAX_SCORE_FIRST_LVL ){
                level = 1;
            }else if ( score < MAX_SCORE_SECOND_LVL) {
                level = 2;
            }else{
                level = 3;
            }

        //DETERMINA A VELOCIDADE DE ACORDO COM O LEVEL
            if (level == 1){
                speed = 3;
            }else if (level == 2) {
                speed = 2;
            }else{
                speed = 1;
            }

        //FAZ O SORTEIO DOS CARROS
            if(timer == 0){
                randNumber = rand()%100;

                if( randNumber % 2 == 0 ){
                    initObstacle(&obstacle1, 1);
                }else {
                    initObstacle(&obstacle1, 0);
                }
            }

            if(timer == 2){
                randNumber = rand()%100;

                if( randNumber % 2 == 0 ){
                    initObstacle(&obstacle2, 1);
                }else {
                    initObstacle(&obstacle2, 0);
                }
            }

            if(timer == 4){
                randNumber = rand()%100;

                if( randNumber % 2 == 0 ){
                    initObstacle(&obstacle3, 1);
                }else {
                    initObstacle(&obstacle3, 0);
                }
            }
 
                
            gotoxy(0,0);
            printCar (matrix, SIMBOL, carRace);
            printObstacle1(matrix, SIMBOL, obstacle1);
            printObstacle2(matrix, SIMBOL, obstacle2);
            printObstacle3(matrix, SIMBOL, obstacle3);
            printMatrix (matrix, SIMBOL, signal, level, score);
            printCar (matrix, EMPTY, carRace);


        //VERIFICA COLISÃO E AUMENTA PONTUAÇÃO
            if ( signal % speed == 0 ){
                if (! collision (matrix, carRace)){
                    if ( obstacle1.i-4 < ROWS ) {
                        printObstacle1(matrix, EMPTY, obstacle1);
                        obstacle1.i++;
                    }
                    if (obstacle1.i-4 == ROWS-1){
                        score += SCORE_CAR;
                    }                        

                    if ( obstacle1.i-4 < 11){
                        timer=1;
                    } 
                    if (obstacle1.i-4 == 11){
                        timer=2;
                    }
                
                    if ( obstacle2.i-4 < ROWS ) {
                        printObstacle2(matrix, EMPTY, obstacle2);
                        obstacle2.i++;
                    }
                    if ( obstacle2.i-4 == ROWS -1){
                        score += SCORE_CAR;
                    }

                    if ( obstacle2.i-4 < 11){
                        timer = 1;
                    }
                    if ( obstacle2.i-4 == 11){
                        timer = 4;
                    }

                    if ( obstacle3.i-4 < ROWS ) {
                        printObstacle3(matrix, EMPTY, obstacle3);
                        obstacle3.i++;
                        timer=1;
                    }
                    if ( obstacle3.i-4 == ROWS-1){
                        score += SCORE_CAR;
                        timer = 0;
                    } 
                }else{

                    system("CLS");
                    ranking(BORDERTOP, BORDERDOWN, &player, score);
                    system("PAUSE");
                    exit(0);
                }
            } 
            
        //COMANDOS DO TECLADO
            keypressed = 0;
            if( kbhit() ){
                keypressed = getch();
            }
            
            if (keypressed == ARROWS){
                keypressed = getch();
            }

            switch( keypressed ){
                case BUTTON_A:
                case BUTTON_a:
                case ARROW_LEFT:
                    if(carRace.j-2>0) carRace.j=4;
                break;

                case BUTTON_D:
                case BUTTON_d:
                case ARROW_RIGHT:
                    if(carRace.j+2<COLUMNS-1) carRace.j=10;
                break;

                case SPACE_BAR:
                    speed=1;
            }
        }
            system("CLS");
            goto start;
            break;
            
            case 2: highScore(BORDERTOP, BORDERDOWN,&player);
                    break;

            case 3: exit(0);
                    break;

            default: printf("ERROR: OPCAO INVALIDA!");
}
 system("pause");
 return 0;
}