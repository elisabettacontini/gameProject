#include "World.hpp"

int main(){
      // Nascondo il cursore all'utente per migliorare la visibilit√† del gioco
    CONSOLE_CURSOR_INFO info;
    info.dwSize = 100;
    info.bVisible = 0;
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);
    World W;
    W.startGame();
    return 0;
}