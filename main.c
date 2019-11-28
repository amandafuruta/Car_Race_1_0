#include "race.h"
#include "display.h"

int main (){
    
    char matrix[ROWS][COLUMNS];
    int keypressed ;
    int signal=0, level, randNumber, timer=1, resp, score=0, speed;
    Car carRace;
    Car obstacle;
    Data player;
    
    start:
    keypressed=0;

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
            }else {
                level = 2;
            }

        //DETERMINA A VELOCIDADE DE ACORDO COM O LEVEL
            if (level == 1){
                speed = 3;
            }else {
                speed = 1;
            }

        //FAZ O SORTEIO DOS CARROS
            if(timer != 0){
                srand(time(NULL));
                randNumber = rand()%100;

                if( randNumber % 2 == 0 ){
                    initObstacle(&obstacle, 1);
                }else {
                    initObstacle(&obstacle, 0);
                }
            }
 
                
            gotoxy(0,0);
            printCar (matrix, SIMBOL, carRace);
            printObstacle(matrix, SIMBOL, obstacle);
            printMatrix (matrix, SIMBOL, signal, level, score);
            printCar (matrix, EMPTY, carRace);


        //VERIFICA COLISÃO E AUMENTA PONTUAÇÃO
            if ( signal % speed == 0 ){
                if (! collision (matrix, carRace)){
                    if ( obstacle.i-21 < ROWS ) {
                        printObstacle(matrix, EMPTY, obstacle);
                        obstacle.i++;
                        timer=0; 
                    }else {
                        timer=1;
                        score+= SCORE_CAR;
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
                    if(carRace.j-2>0) carRace.j --;
                break;

                case BUTTON_D:
                case BUTTON_d:
                case ARROW_RIGHT:
                    if(carRace.j+2<COLUMNS-1) carRace.j++;
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