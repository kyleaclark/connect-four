#ifndef _SETUP_H_
#define _SETUP_H_

// <- VARIABLES -> //
extern volatile int counter;

extern volatile int mouse_x;
extern volatile int mouse_y;
extern volatile int mouse_z;
extern volatile int mouse_b;
extern volatile int mouse_pos;


// <- FUNCTIONS -> //
void init(void);
void deinit(void);
void update_counter(void);


#endif


