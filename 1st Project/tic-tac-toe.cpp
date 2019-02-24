#include <stdio.h>
#include <stdlib.h>

// Crea el tablero
char matrix[3][3]; 

/* Inicializa la matriz del tablero */
void init_matrix(void)
{
    int i, j;

    for (i = 0; i < 3; i++)
        for (j = 0; j < 3; j++)
            matrix[i][j] = ' ';
}

/* Lee el movimiento del jugador */
void get_player_move(void)
{
    int x, y;

    printf("\nIngresa tu movimiento con un espacio de separacion (1 1): ");
    scanf("%d%*c%d", &x, &y);

    x--;
    y--;

    if (matrix[x][y] != ' ')
    {
        printf("\nMovimiento no valido\n");
        get_player_move();
    }

    else
        matrix[x][y] = 'X';
}

/* Genera un movimiento para la PC */
void get_computer_move(void)
{
    int i, j;

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
            if (matrix[i][j] == ' ')
                break;
        if (matrix[i][j] == ' ')
            break;
    }

    if (i * j == 9)
    {
        printf("draw\n");
        exit(0);
    }

    else
        matrix[i][j] = 'O';
}

/* Muestra el tablero en pantalla */
void disp_matrix(void)
{
    int t;

    for (t = 0; t < 3; t++)
    {
        printf(" %c | %c | %c ", matrix[t][0],
               matrix[t][1], matrix[t][2]);

        if (t != 2)
            printf("\n---|---|---\n");
    }

    printf("\n");
}

/* Revisa si hay un ganador */
char check(void)
{
    int i;

    /* Revisa filas */
    for (i = 0; i < 3; i++) 
        if (matrix[i][0] == matrix[i][1] && matrix[i][0] == matrix[i][2])
            return matrix[i][0];

    /* Revisa columnas */
    for (i = 0; i < 3; i++) 
        if (matrix[0][i] == matrix[1][i] && matrix[0][i] == matrix[2][i])
            return matrix[0][i];

    /* Revisa diagonal 1 */
    if (matrix[0][0] == matrix[1][1] && matrix[1][1] == matrix[2][2])
        return matrix[0][0];

    /* Revisa diagonal 2 */
    if (matrix[0][2] == matrix[1][1] && matrix[1][1] == matrix[2][0])
        return matrix[0][2];

    return ' ';
}

int main(void)
{
    char done;

    printf("Juguemos Gato\n");
    printf("Player 1 vs PC\n");

    done = ' ';

    init_matrix();

    do
    {
        disp_matrix();
        get_player_move();
        done = check(); 

        if (done != ' ')
            break; 

        get_computer_move();
        done = check(); 

    } while (done == ' ');

    if (done == 'X')
        printf("El ganador eres tu!\n");

    else
        printf("Parece que ha ganado la computadora :)\n");

    disp_matrix(); 

    return 0;
}

