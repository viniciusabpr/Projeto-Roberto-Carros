#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<time.h>

#define col 50
#define rows 20
#define foods 10

char board[col * rows];

int isGameOver = 0;

// Configura a estrutura do mapa
void fill_board(){
    int x,y;

    for(y=0;y<rows;y++){
        for(x=0;x<col;x++){
            if (x == 0 || y == 0 || x == col-1 || y == rows-1){
                board[y*col + x] = '#';
            }else{
                board[y*col + x] = ' ';
            }
        }
    }
}

// Atualiza a tela para não printar vários mapas
void clear_screen(){
    system("cls");
}

// Printa o mapa
void print_board(){
    int x,y;

    for (y=0;y<rows;y++){
        for(x=0;x<col;x++){
            putch(board[y*col + x]);
        }
        putch('\n');
    }
}

#define SNAKE_MAX_LEN 256
struct Snakepart{
    int x,y;
};
struct Snake{
    int length;
    struct Snakepart part[SNAKE_MAX_LEN];
};

// Estrutura do tipo Snake com nome snake, cria a cobra com as características configuradas em Snake
struct Snake snake;

// Configura as comidas e cria um tipo de comida (food) do tipo Food
struct Food{
    int x, y;
    int consumed;
};
struct Food food[foods];

// Printa a cobra na tela
void draw_snake(){
    int i;

    for(i=snake.length-1; i>0; i--){
        board[snake.part[i].y*col + snake.part[i].x] = '+';
    }
    board[snake.part[0].y*col + snake.part[0].x] = '@';
}

// Configura os movimentos da cobra e suas partes
void move_snake(int deltaX, int deltaY){
    int i;
    for(i=snake.length-1; i>0; i--){
        snake.part[i] = snake.part[i-1];
    }

    snake.part[0].x += deltaX;
    snake.part[0].y += deltaY;
}

// Configura os movimentos a partir dos comandos do teclado
void read_keyboard(){
    int ch = getch();

    switch(ch){
        case 'w': move_snake(0,-1);
            break;
        case 's': move_snake(0,1);
            break;
        case 'a': move_snake(-1,0);
            break;
        case 'd': move_snake(1,0);
            break;
    }
}

// Printa a comida a partir da lógica criada em Food
void draw_food(){
    int i;

    for (i = 0; i < foods; i++) {
        if (!food[i].consumed) {
            board[food[i].y * col + food[i].x] = '+';
        }
    }
}

// Configura de maneira aleatória o spawn das comidas
void setup_food(){
    int i;
    for(i=0; i<foods; i++) {
        food[i].x = 1 + rand() % (col-2);
        food[i].y = 1 + rand() % (rows-2);
        food[i].consumed = 0;
    }
}

// Configura o tamanho e lugar de spawn da cobra (o lugar é aleatório)
void setup_snake(){
    snake.length = 1;
    snake.part[0].x = 1 + rand() % (col-2);
    snake.part[0].y = 1 + rand() % (rows-2);
}

// Verifica se todas as comidas foram consumidas e gera novas comidas se necessário
void check_and_reset_food() {
    int i;
    int all_consumed = 1;

    for (i = 0; i < foods; i++) {
        if (!food[i].consumed) {
            all_consumed = 0;
            break;
        }
    }

    if (all_consumed) {
        setup_food();
    }
}

// Define as regras para acabar o jogo caso a cobra encoste nas bordas do mapa ou em si mesma e cresça quando comer
void game_rules(){
    int i;

    for(i=0; i<foods; i++){
        if(!food[i].consumed){
            if(food[i].x == snake.part[0].x && food[i].y == snake.part[0].y){
                food[i].consumed = 1;
                snake.length++;
            }
        }
    }
    check_and_reset_food();

    if(snake.part[0].x == 0 || snake.part[0].x == col-1 ||
       snake.part[0].y == 0 || snake.part[0].y == rows-1){
        isGameOver=1;
    }

    for(i=1; i<snake.length; i++){  // Corrigi para começar em 1
        if(snake.part[0].x == snake.part[i].x &&
           snake.part[0].y == snake.part[i].y){
            isGameOver=1;
        }
    }
}

int main(int argc, char **argv){
    srand(time(0));

    setup_snake();
    setup_food();

    while (!isGameOver) {
        fill_board();
        draw_food();
        draw_snake();
        game_rules();
        clear_screen();
        printf("Score: %d\n", snake.length);
        print_board();
        if (!isGameOver) {
            read_keyboard();
        }
    }

    printf("Game over, final score: %d\n", snake.length);
    system("pause");
    return 0;
}
