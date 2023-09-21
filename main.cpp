#include <iostream>

using namespace std;

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


int main(){
    int arr[3][3];
    cout << CheckGameState((arr)) << "\n";
    return 0;
}
