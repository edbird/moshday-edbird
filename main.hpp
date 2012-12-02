
#ifndef __MAIN__HPP__
#define __MAIN__HPP__

// Put other main-*.cpp file function definitions here.
void cleanup();
void initRendering();
void handleResize(int, int);
void drawScene();
void handleKeyboard(unsigned char, int, int);
void handleKeyboardUp(unsigned char, int, int);
void handleKeyboardSpecial(int, int, int);
void handleTimer(int);

// Put global constants here example:
extern char keys[0x100];
extern double time_step;
extern double fps;
extern int ms_delay;
extern bool human_is_playing; // Human is either observing or playing

//const int EXIT_WITHOUT_ERROR = 0x0;
//const int EXIT_HAD_ERROR = 0x1;

#endif
