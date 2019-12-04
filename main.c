#include "race.h"
#include "display.h"

int main()
{

    char matrix[ROWS][COLUMNS];
    int keypressed;
    int signal = 0, level = 0, randNumber = 0, timer = 0, resp = 0, score = 0, speed = 0;
    Car carRace;
    Car obstacle[3];
    // Car obstacle[1];
    // Car obstacle[2];
    Data player;

start:
    keypressed = 0;

    srand(time(NULL));
    begin(matrix);
    initCar(&carRace);

    ShowConsoleCursor(0);
    system("cls");

    //CHAMADA DO MENU
    resp = menu(BORDERTOP, BORDERDOWN);

    system("CLS");

    //RESULTADO DA ESCOLHA DAS OPÇÕES NO MENU
    switch (resp)
    {
    case 1:
        while (keypressed != ESC)
        {
            signal++;

            //DETERMINA O LEVEL DE ACORDO COM A PONTUAÇÃO
            if (score < MAX_SCORE_FIRST_LVL)
            {
                level = 1;
            }
            else if (score < MAX_SCORE_SECOND_LVL)
            {
                level = 2;
            }
            else
            {
                level = 3;
            }

            //DETERMINA A VELOCIDADE DE ACORDO COM O LEVEL
            if (level == 1)
            {
                speed = 3;
            }
            else if (level == 2)
            {
                speed = 2;
            }
            else
            {
                speed = 1;
            }

            //FAZ O SORTEIO DOS CARROS
            //CARRO 1
            if (timer == 0)
            {
                randNumber = rand() % 100;

                if (randNumber % 2 == 0)
                {
                    initObstacle(&obstacle[0], 1);
                }
                else
                {
                    initObstacle(&obstacle[0], 0);
                }
            }

            //CARRO 2
            if (timer == 2)
            {
                randNumber = rand() % 100;

                if (randNumber % 2 == 0)
                {
                    initObstacle(&obstacle[1], 1);
                }
                else
                {
                    initObstacle(&obstacle[1], 0);
                }
            }

            //CARRO 3
            if (timer == 4)
            {
                randNumber = rand() % 100;

                if (randNumber % 2 == 0)
                {
                    initObstacle(&obstacle[2], 1);
                }
                else
                {
                    initObstacle(&obstacle[2], 0);
                }
            }

            gotoxy(0, 0);
            printCar(matrix, SIMBOL, carRace);
            printObstacle1(matrix, SIMBOL, obstacle[0]);
            printObstacle2(matrix, SIMBOL, obstacle[1]);
            printObstacle3(matrix, SIMBOL, obstacle[2]);
            printMatrix(matrix, SIMBOL, signal, level, score);
            printCar(matrix, EMPTY, carRace);

            //VERIFICA COLISÃO E AUMENTA PONTUAÇÃO
            if (signal % speed == 0)
            {
                if (!collision(matrix, carRace))
                {
                    if (obstacle[0].i - 4 < ROWS)
                    {
                        printObstacle1(matrix, EMPTY, obstacle[0]);
                        obstacle[0].i++;
                    }
                    if (obstacle[0].i - 4 == ROWS - 1)
                    {
                        score += SCORE_CAR;
                    }

                    if (obstacle[0].i - 4 < 11)
                    {
                        timer = 1;
                    }
                    if (obstacle[0].i - 4 == 11)
                    {
                        timer = 2; //PARA FAZER CHAMAR O SORTEIO DO CARRO 2
                    }

                    if (obstacle[1].i - 4 < ROWS)
                    {
                        printObstacle2(matrix, EMPTY, obstacle[1]);
                        obstacle[1].i++;
                    }
                    if (obstacle[1].i - 4 == ROWS - 1)
                    {
                        score += SCORE_CAR;
                    }

                    if (obstacle[1].i - 4 < 11)
                    {
                        timer = 1;
                    }
                    if (obstacle[1].i - 4 == 11)
                    {
                        timer = 4; //CHAMA O SORTEIO DO CARRO 3
                    }

                    if (obstacle[2].i - 4 < ROWS)
                    {
                        printObstacle3(matrix, EMPTY, obstacle[2]);
                        obstacle[2].i++;
                        timer = 1;
                    }
                    if (obstacle[2].i - 4 == ROWS - 1)
                    {
                        score += SCORE_CAR;
                        timer = 0;
                    }
                }
                else
                {

                    system("CLS");
                    ranking(BORDERTOP, BORDERDOWN, &player, score);
                    system("PAUSE");
                    exit(0);
                }
            }

            //COMANDOS DO TECLADO
            keypressed = 0;
            if (kbhit())
            {
                keypressed = getch();
            }

            if (keypressed == ARROWS)
            {
                keypressed = getch();
            }

            switch (keypressed)
            {
            case BUTTON_A:
            case BUTTON_a:
            case ARROW_LEFT:
                if (carRace.j - 2 > 0)
                    carRace.j = 4;
                break;

            case BUTTON_D:
            case BUTTON_d:
            case ARROW_RIGHT:
                if (carRace.j + 2 < COLUMNS - 1)
                    carRace.j = 10;
                break;

            case SPACE_BAR:
                speed = 1;
            }
        }
        system("CLS");
        goto start;
        break;

    //ESCOLHA DA SEGUNDA OPÇÃO DO MENU- MOSTRA O HIGH SCORE
    case 2:
        highScore(BORDERTOP, BORDERDOWN, &player);
        break;

    //TERCEIRA ESCOLHA NO MENU - SAI DO JOGO
    case 3:
        exit(0);
        break;

    default:
        printf("ERROR: OPCAO INVALIDA!");
    }
    system("pause");
    return 0;
}