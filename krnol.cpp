#include <iostream>

using namespace std;
int correct_placement(int x, int y){
    if ((0 < x) && (x < 4)) {
        if ((0 < y) && (y < 4)){
            return 1;
        }
    }
    return 0;

}
char hod_igroka(int* player_place_x_t, int* player_place_y_t) {
    int place_x, place_y;
    while (true) {
        cout << "Введите координаты хода x y (1-3) (1-3):" << '\n';
        cin >> place_x >> place_y;
        if (correct_placement(place_x, place_y) != 0) {
            *player_place_x_t = place_x;
            *player_place_y_t = place_y;

            return 0;
        }
        else {
            cout << "Неправильный ввод, попробуйте еще раз" << '\n';
        }

    }
}


void drawing_desk(int ( desk_t )[3][3]) {


    cout << "╔═══╤═══╤═══╗" << '\n';
    cout << "║ " << desk_t[0][0] << " │ " << desk_t[1][0] << " │ " << desk_t[2][0] << " ║" << '\n';
    cout << "╟───┼───┼───╢" << '\n';
    cout << "║ " << desk_t[1][1] << " │ " << desk_t[1][1] << " │ " << desk_t[2][1] << " ║" << '\n';
    cout << "╟───┼───┼───╢" << '\n';
    cout << "║ " << desk_t[1][2] << " │ " << desk_t[1][2] << " │ " << desk_t[2][2] << " ║" << '\n';
    cout << "╚═══╧═══╧═══╝" << '\n';

}

int main() {
    int player_place_x,player_place_y;
    int desk[3][3];
    desk[2][2] = 0;
    drawing_desk(desk);
    hod_igroka(&player_place_x, &player_place_y);



    cout << player_place_x << player_place_y;
}