#include "GameController.h"
#include <ctime>
#include <cstdlib>

int main() {
    srand(static_cast<unsigned int>(time(nullptr)));

    Player player("Faradis", 100, 50, 20, 5);
    GameController gc(&player);

    gc.start();
    return 0;
}
