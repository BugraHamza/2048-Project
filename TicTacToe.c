#include <stdio.h>
#include <time.h>
int main()
{
    int i, j, place, row, column, movement, tour, endgame = 1, winrate, win = 0, score = 0;
    char symbol, M[3][3], move, pcsymbol;
    srand(time(NULL));
    for(i = 0; i < 3; i++)
    {
        for(j = 0; j < 3; j++)
        {
            M[i][j] = 0;
        }
    }
    printf("TICTACTOE GAME  implemented by TheBuG v1.0.0.0\nBefore you start which side are you in, are you an X or an O follower?\nPress X or O:\t");
    do
    {
        move = getch();
        if(move == 'X' || move == 'x')
            symbol = 'X';
        if(move == 'O' || move == 'o')
            symbol = 'O';
    }while(symbol != 'X' && symbol != 'O');
    if(symbol == 'X')
        pcsymbol = 'O';
    else
        pcsymbol = 'X';
    system("cls");
    while(endgame != 0){
        movement = 0;
        tour = 0;
        winrate = 2;
        printf("TICTACTOE GAME  implemented by TheBuG v1.0.0.0\nSCORE : %d\n", score);
        for(i = 0; i < 3; i++)
        {
            printf("-------------\n");
            for(j = 0; j < 3; j++)
            {
                printf("|%3c", M[i][j]);
            }
            printf("|\n");
        }
        printf("-------------");
        move = getch();
        if(move == 'e' || move == 'E')
            endgame = 0;
        else if(move == 'r' || move == 'R')
        {
            for(i = 0; i < 3; i++)
            {
                for(j = 0; j < 3; j++)
                    M[i][j] = 0;
            }
        }
        else if(move == '7' && (M[0][0] != 'X' && M[0][0] != 'O'))
        {
        M[0][0] = symbol;
        movement = 1;
        }
        else if(move == '8' && (M[0][1] != 'X' && M[0][1] != 'O'))
        {
        M[0][1] = symbol;
        movement = 1;
        }
        else if(move == '9' && (M[0][2] != 'X' && M[0][2] != 'O'))
        {
        M[0][2] = symbol;
        movement = 1;
        }
        else if(move == '4' && (M[1][0] != 'X' && M[1][0] != 'O'))
        {
        M[1][0] = symbol;
        movement = 1;
        }
        else if(move == '5' && (M[1][1] != 'X' && M[1][1] != 'O'))
        {
        M[1][1] = symbol;
        movement = 1;
        }
        else if(move == '6' && (M[1][2] != 'X' && M[1][2] != 'O'))
        {
        M[1][2] = symbol;
        movement = 1;
        }
        else if(move == '1' && (M[2][0] != 'X' && M[2][0] != 'O'))
        {
        M[2][0] = symbol;
        movement = 1;
        }
        else if(move == '2' && (M[2][1] != 'X' && M[2][1] != 'O'))
        {
        M[2][1] = symbol;
        movement = 1;
        }
        else if(move == '3' && (M[2][2] != 'X' && M[2][2] != 'O'))
        {
        M[2][2] = symbol;
        movement = 1;
        }
        printf("\n");
        for(i = 0; i < 3; i++)
        {
            for(j = 0; j < 3; j++)
            {
                if(M[i][j] == 'X' || M[i][j] == 'O')
                    tour++;
            }
        }
        do
        {
            row = rand() % 3;
            column = rand() % 3;
        }while((M[row][column] == 'X' || M[row][column] == 'O') && tour != 9);
        if(movement == 1 && tour != 9)
            M[row][column] = pcsymbol;




        for(i = 0; i < 3; i++)
        {
            if(M[i][0] == M[i][1] && M[i][1] == M[i][2])
            {
                if(M[i][1] == symbol)
                    winrate = 1;
                else if(M[i][1] == pcsymbol)
                    winrate = 0;
            }
            else if(M[0][i] == M[1][i] && M[1][i] == M[2][i])
            {
                if(M[0][i] == symbol)
                    winrate = 1;
                else if(M[0][i] == pcsymbol)
                    winrate = 0;
            }
        }
        if(M[0][0] == M[1][1] && M[1][1] == M[2][2])
        {
            if(M[0][0] == symbol)
                winrate = 1;
            else if(M[0][0] == pcsymbol)
                winrate = 0;
        }
        else if(M[0][2] == M[1][1] && M[1][1] == M[2][0] && M[0][2] == symbol && M[1][1] == symbol && M[2][0] == symbol)
        {
            if(M[0][2] == symbol)
                winrate = 1;
            else if(M[0][2] == pcsymbol)
                winrate = 0;
        }
        if(winrate == 1 )
        {
            printf("You won !!!");
            win++;
            score += win;
            printf("\nPress Enter to continue..");
            getchar();

        }
        else if(winrate == 2 && tour == 9)
        {
            win = 0;
            printf("It's draw !!!");
            printf("\nPress Enter to continue..");
            getchar();
        }
        else if(winrate == 0)
        {
            win = 0;
            printf("You lost !!!");
            printf("\nPress Enter to continue..");
            getchar();
        }
        if(winrate == 0 || winrate == 1 || tour == 9)
        {
            for(i = 0; i < 3; i++)
            {
                for(j = 0; j < 3; j++)
                    M[i][j] = 0;
            }
        }
        system("cls");
    }
    printf("See you next time :)");
    return 0;
}
