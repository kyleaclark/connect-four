#ifndef _DISPLAY_H_
#define _DISPLAY_H_

// <- VARIABLES -> //
#define BLACK makecol(0, 0, 0)
#define RED makecol(255, 13, 13)
#define GREEN makecol(13, 255, 13)
#define BLUE makecol(13, 13, 255)
#define YELLOW makecol(255, 255, 13)


// <- FUNCTIONS -> //
void display(void);
void display_grid(void);
void display_text(void);
void display_marks(void);
void display_movement(void);


#endif


