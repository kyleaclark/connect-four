#include <allegro.h>
#include "board.h"


// <- VARIABLES -> //
const int GX_START = 145;
const int GX_END = 495;
const int GY_START = 90;
const int GY_END = 390;
const int G_SPACE = 50;  //48 + 2; 24x24 will be the placement mark size
const int ABOVE_MOUSE = 2;  //the difference of 50 - size of placement mark

char grid[7][6];  //holds the X's and O's on the grid value system

short lowx[7];   //holds the low values of X on the 7 rows
short highx[7];  //holds the high values of X on the 7 rows
short lowy[6];   //holds the low values of Y on the 6 columns
short highy[6];  //holds the high values of Y on the 6 columns

short spotx;
short spoty;

int xbefore;
int ybefore;

bool player;
bool game_win;


// <- FUNCTIONS -> //
void set_grid(void)
 {  
  for(short count = 0; count < 7; count++)
   {
    lowx[count] = GX_START + (G_SPACE * count);
    highx[count] = GX_START + G_SPACE + (G_SPACE * count); 
   }
   
  for(short count = 0; count < 6; count++)
   {
    lowy[count] = GY_START + (G_SPACE * count);
    highy[count] = GY_START + G_SPACE + (G_SPACE * count); ;
   }
  
  //initializing the entire grid to be blank (' ') spaces 
  for(short xcount = 0; xcount < 7; xcount++)
   {
    for(short ycount = 0; ycount < 6; ycount++)
     {
      grid[xcount][ycount] = ' ';
     }
   }
   
  //POSITIONS THE MOUSE IN THE DESIGNATED BEGINNING MOVE SPOT 
  repos_mouse(); 
  player = 0;
  game_win = false;

 } 
////////////////////////////////////////////////////////////////////////////////
void find_loc(int mx, int my, bool click)
 {
  xbefore = mx;
  ybefore = my; 
  
  mx = mx - (ABOVE_MOUSE / 2);
  my = my - (ABOVE_MOUSE / 2);
  
  char chr1;
  char chr2;
  
  if(player == 0)
   {
    chr1 = 'O';
    chr2 = 'o';
   }
  else
   {
    chr1 = 'X';
    chr2 = 'x';
   }   
  
  for(short count = 0; count < 7; count++) 
   {
    if(mx >= lowx[count] && mx <= highx[count])
     {
      spotx = count;
      break;
     }
   }
   
  for(short count = 0; count < 6; count++) 
   {
    if(my >= lowy[count] && my <= highy[count])
     {
      spoty = count;
      break;
     }
   }
  
  //Checks if the mouse has been clicked and it is a valid move
  if(click == true && 
     (xbefore <= GX_END && xbefore >= GX_START - 46) &&
     (ybefore <= GY_END && ybefore >= GY_START - 46))
   {
    //Checks to see if the bottom row is OPEN
    if(spoty == 5 && (grid[spotx][spoty] != 'X' && grid[spotx][spoty] != 'O'))
     {
      grid[spotx][spoty] = chr1;
      
      //REPOSITIONS THE MOUSE AFTER A COMPLETED MOVE AND SWITCHES PLAYERS
      repos_mouse();
        
      //CHECK FOR WIN
      if(check_win(chr1) == true)
       game_win = true; 
     }
    //Checks to see if the row Below has a piece in it and if the spot is OPEN
    else if(spoty < 5 && 
           (grid[spotx][spoty+1] == 'X' || grid[spotx][spoty+1] == 'O') &&
           ( grid[spotx][spoty] != 'X' && grid[spotx][spoty] != 'O'))
     {
      grid[spotx][spoty] = chr1;
      
      //REPOSITIONS THE MOUSE AFTER A COMPLETED MOVE AND SWITCHES PLAYERS
      repos_mouse();
      
      //CHECK FOR WIN
      if(check_win(chr1) == true)
       game_win = true; 
       
     }
   }
  //Checks to see if the marker is out of the board area
  else if(click == false && 
          grid[spotx][spoty] != 'O' && grid[spotx][spoty] != 'X' &&
          ((xbefore > GX_END || xbefore < GX_START - 46) ||
          (ybefore > GY_END || ybefore < GY_START - 46)))
   {
    grid[spotx][spoty] = ' ';
   }
  //Checks to see if the bottom row is a valid possible move
  else if(click == false && spoty == 5 && grid[spotx][spoty] == ' ')
   {
    grid[spotx][spoty] = chr2;
   }
  //Checks to see if any row above the bottom is a valid possible move
  else if(click == false && spoty < 5 && 
          (grid[spotx][spoty] != 'X' && grid[spotx][spoty] != 'O') &&
          (grid[spotx][spoty+1] == 'X' || grid[spotx][spoty+1] == 'O'))
   {
    grid[spotx][spoty] = chr2;
   }  
     
 }
////////////////////////////////////////////////////////////////////////////////
void repos_mouse(void)
 {
  //repositions the mouse after a move is completed and switches players
  if(player == 0)
   {
    player = 1;
    position_mouse(47, 216);
   }
  else
   {
    player = 0;
    position_mouse(47, 216);
   }
   
 }
////////////////////////////////////////////////////////////////////////////////  
bool check_win(char mark)
 {
   int col;
   int row;
   
   
   //checking horizontally//
   for(col = 0; col < 7; col++)
    {
     if(mark == grid[col][spoty] &&
        mark == grid[col+1][spoty] && 
        mark == grid[col+2][spoty] &&
        mark == grid[col+3][spoty])
      {
       return true;
      }
    } 
   
   //checking vertically
   if(spoty < 3)
    {
     if(mark == grid[spotx][spoty] &&
        mark == grid[spotx][spoty+1] && 
        mark == grid[spotx][spoty+2] &&
        mark == grid[spotx][spoty+3])
      {
       return 1;
      }
    }

   //checking diagonally NE
   for(row = 5; row > 2; row--)
    {
     for(col = 0; col < 4; col++)
      {
       if(mark == grid[col][row] &&
          mark == grid[col+1][row-1] && 
          mark == grid[col+2][row-2] &&
          mark == grid[col+3][row-3])
        {
         return 1;
        }
      }
    }
    
   //checking diagonally NW
   for(row = 5; row > 2; row--)
    {
     for(col = 6; col > 2; col--)
      {
       if(mark == grid[col][row] &&
          mark == grid[col-1][row-1] && 
          mark == grid[col-2][row-2] &&
          mark == grid[col-3][row-3])
        {
         return 1;
        }
      }
    }

  //NO WIN
  return 0;

 }
