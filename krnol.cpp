#include <iostream>

using namespace std;

int correct_placement(int x, int y) {
    if ((0 < x) && (x < 4)) {
        if ((0 < y) && (y < 4)) {
            return 1;
        }
    }
    return 0;
}

int is_not_occupied(int x, int y, int(&desk_t)[3][3]) {
    if (desk_t[x - 1][y - 1] != 0) {
        return 0;
    } else {
        return 1;
    }
}

char hod_igroka(int *player_place_x_t, int *player_place_y_t, int(&desk_t)[3][3]) {
    int place_x, place_y;
    while (true) {
        cout << "Введите координаты хода x y (1-3) (1-3):" << '\n';
        cin >> place_x >> place_y;
        if ((correct_placement(place_x, place_y) != 0) and is_not_occupied(place_x, place_y, desk_t)) {
            desk_t[place_x - 1][place_y - 1] = 1;

            return 0;
        } else {
            cout << "Неправильный ввод, попробуйте еще раз. Пожалуйста, не вводите координаты уже занятых клеток поля." << '\n';
        }

    }
}


void drawing_desk(int ( desk_t )[3][3]) {
    char desk_beauty[3][3];
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            switch (desk_t[i][j]) {
                case 0:
                    desk_beauty[i][j] = ' ';
                    break;
                case 1:
                    desk_beauty[i][j] = 'X';
                    break;
                case 2:
                    desk_beauty[i][j] = '0';
                    break;
            }
        }
    }
    
    cout << "╔═══╤═══╤═══╗" << '\n';
    cout << "║ " << desk_beauty[0][0] << " │ " << desk_beauty[1][0] << " │ " << desk_beauty[2][0] << " ║" << '\n';
    cout << "╟───┼───┼───╢" << '\n';
    cout << "║ " << desk_beauty[0][1] << " │ " << desk_beauty[1][1] << " │ " << desk_beauty[2][1] << " ║" << '\n';
    cout << "╟───┼───┼───╢" << '\n';
    cout << "║ " << desk_beauty[0][2] << " │ " << desk_beauty[1][2] << " │ " << desk_beauty[2][2] << " ║" << '\n';
    cout << "╚═══╧═══╧═══╝" << '\n';

}

int CheckGameState(int (arr)[3][3]) {
    //получает на вход двумерный массив -- выводит элемент победившего в случае победы, 0 в случае продолжения игры и 3 в случае ничьи
    for (int i = 0; i < 3; i++){
        if ((arr[i][0] == arr[i][1]) && (arr[i][1] == arr[i][2]) && (arr[i][0] != 0)) return arr[i][0]; // проверка по строкам
        else if ((arr[0][i] == arr[1][i]) && (arr[1][i] == arr[2][i]) && (arr[0][i] != 0)) return arr[0][i]; // проверка по столбцам
    }

    if ((arr[0][0] == arr[1][1]) && (arr[1][1] == arr[2][2]) && (arr[0][0] != 0)) return arr[0][0]; // проверка по главной диагонали
    else if  ((arr[2][0] == arr[1][1]) && (arr[1][1] == arr[0][2]) && (arr[2][0] != 0)) return arr[2][0]; // проверка по побочной диагонали

    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++) if (arr[i][j] == 0) return 0; //проверка на ничью
    }

    return 3;
}

int AITurn(int (&desk_t)[3][3]) {
    int x_r = std::rand() % 3 + 1;
    int y_r = std::rand() % 3 + 1;
    while (is_not_occupied(x_r, y_r, desk_t) == 1) {
        srand((unsigned) time(NULL));
        x_r = std::rand() % 3 + 1;
        y_r = std::rand() % 3 + 1;
    }
    cout << x_r << y_r << '\n';


    for (int i = 0; i < 3; i++) {
        for (int j = 0; i < 3; i++) {
            if (desk_t[i][j] == 0) {
                desk_t[i][j] = 2;
                if (CheckGameState(desk_t) == 2) {
                    return 0;
                }
                else {
                    desk_t[i][j] = 0;
                }
            }
        }
    }
    for (int i = 0; i < 3; i++) {
        for (int j = 0; i < 3; i++) {
            if (desk_t[i][j] == 0) {
                desk_t[i][j] = 1;
                if (CheckGameState(desk_t) == 1) {
                    desk_t[i][j] = 2;
                    return 0;
                }
                else {
                    desk_t[i][j] = 0;
                }
            }
        }
    }
    desk_t[x_r][y_r] = 2;
}
int main() {
    int player_place_x, player_place_y;
    int desk[3][3];
    desk[2][2] = 0;
    while (CheckGameState(desk) == 0){
        drawing_desk(desk);
        hod_igroka(&player_place_x, &player_place_y, desk);
        if (CheckGameState(desk) != 0) {
            break;
        }
        AITurn(desk);
    }
    drawing_desk(desk);
    if (CheckGameState(desk) == 1) {
        cout << "Победил игрок!" << '\n';
    }
    else if (CheckGameState(desk) == 2) {
        cout << "Победил компьютер!" << '\n';
    }
    else if (CheckGameState(desk) == 3) {
        cout << "Победила дружба!" << '\n';
    }





}