#include "race.h"
#include "display.h"

int main (){
    char matrix[ROWS][COLUMNS];
    int keypressed=0 ;
    int signal=0, level=1, randNumber, timer=1, resp;
    Car x;
    Car carRace;
    Car obstacleRight;
    Car obstacleLeft;

    initCar(&carRace);
    initObstacleRight(&obstacleRight);
    initObstacleLeft(&obstacleLeft);
    
    begin (matrix);

    ShowConsoleCursor(0);
    system ("cls");

    resp= menu(BORDERTOP, BORDERDOWN);
    system("CLS");
    
    switch(resp){
        case 1:
            while (keypressed != ESC){
                signal++;
                
            if(timer!=0){
                srand(time(NULL));
                randNumber=rand()%100;

                if(randNumber%2==0){
                    x=obstacleRight;
                }else{
                    x=obstacleLeft;
                }
            }

                
                #if DEBUG==1
                    printf("Signal: %d\n", signal);
                #endif 
                
                gotoxy(0,0);
                printCar (matrix, SIMBOL, carRace);
                printObstacle(matrix, SIMBOL, x);
                printMatrix (matrix, SIMBOL, signal, level/* , score */);
                printCar (matrix, EMPTY, carRace);

                //if(signal%2==0){
                if(! collision (matrix, carRace)){
                    if(x.i-2<=ROWS) {
                        printObstacle(matrix, EMPTY, x);
                        x.i++;
                        timer=0; 
                    }else{
                        timer=1;
                    }
                }else{
                   system("pause");
               }
                
                
                keypressed=0;
                if(kbhit()){
                    keypressed= getch();
                }
                if (keypressed == ARROWS){
                    keypressed=getch();
                }
                switch(keypressed){
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
            }
            }
            break;
            case 2: break;
            case 3: exit(0);
                    break;
            default: printf("ERROR: OPCAO INVALIDA!");
}
 system("pause");
 return 0;
}