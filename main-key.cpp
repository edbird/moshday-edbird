
#include "team.hpp"

// Globals (for keyboard)
char keys[0x100];

void handleKeyboard(unsigned char key_code, int mouse_x, int mouse_y){
    // glutGetModifiers...
    // glutGetModifiers;
    keys[key_code] = 1;
}

void handleKeyboardUp(unsigned char key_code, int mouse_x, int mouse_y){
    keys[key_code] = 0;
}
