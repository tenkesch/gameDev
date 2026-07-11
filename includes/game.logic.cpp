#include <iostream>

int counter = 0;
void gameLogic() {
    // gameLogic
    counter++;
    if (counter % 60 == 0)
        std::cout << "Hell yeah, this is LOGIC" << counter << std::endl;
}
