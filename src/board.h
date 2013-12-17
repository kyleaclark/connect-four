#ifndef _BOARD_H_
#define _BOARD_H_


// <- VARIABLES -> //

/*
extern const int GX_START = 145;
extern const int GX_END = 495;
extern const int GY_START = 90;
extern const int GY_END = 390;
extern const int G_SPACE = 50;  //48 + 2; 24x24 will be the placement mark size
extern const int ABOVE_MOUSE = 24;  //the size of the placement mark */


extern const int GX_START;
extern const int GX_END;
extern const int GY_START;
extern const int GY_END;
extern const int G_SPACE;  //48 + 2; 24x24 will be the placement mark size
extern const int ABOVE_MOUSE;  //the size of the placement mark

extern char grid[7][6];  //holds the X's and O's on the grid value system

extern short lowx[7];   //holds the low values of X on the 7 rows
extern short highx[7];  //holds the high values of X on the 7 rows
extern short lowy[6];   //holds the low values of Y on the 6 columns
extern short highy[6];  //holds the high values of Y on the 6 columns

extern short spotx;
extern short spoty;

extern int xbefore;
extern int ybefore;

extern bool player;
extern bool game_win;

// <- FUNCTIONS -> //
void set_grid(void);
void find_loc(int mx, int my, bool click);
void repos_mouse(void);
bool check_win(char mark);

#endif
