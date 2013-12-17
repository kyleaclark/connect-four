#include <allegro.h>
#include <string.h>
#include "display.h"
#include "bitmap_load.h"   //calling the bitmaps for display
#include "board.h"         //using the const ints of GX_START, GY_START, etc...

//using namespace std;

// <- VARIABLES -> //




// <- FUNCTIONS -> //
void display(void)
 { 
 
  clear_bitmap(buffer);  //clear the buffer
  
  display_grid();   //displays the blue check box
  display_text();   //displays the text
  
  display_marks();  //displays the X's and O's
  
 
  

  
  if(game_win == true)
   draw_sprite(buffer, WIN, mouse_x - ABOVE_MOUSE, mouse_y - ABOVE_MOUSE);
  else if(player == 0)
   //draws the pointer X or O as the mouse moves 
   draw_sprite(buffer, O_MARK, mouse_x - ABOVE_MOUSE, mouse_y - ABOVE_MOUSE);
   //masked_blit(CIRCLE, buffer, 0, 0, mouse_x - ABOVE_MOUSE, mouse_y - ABOVE_MOUSE, SCREEN_W, SCREEN_H);
  else if(player == 1)
   //draws the pointer X or O as the mouse moves 
   draw_sprite(buffer, X_MARK, mouse_x - ABOVE_MOUSE, mouse_y - ABOVE_MOUSE);
  
  blit(buffer, screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
  
 }
//////////////////////////////////////////////////////////////////////////////// 
void display_grid(void)
 {
  //char printstr[25];
  

 
  for(short vx = GX_START; vx <= GX_END - 50;)
   {
    for(short vy = GY_START; vy <= GY_END - 50;)
     {
      draw_sprite(buffer, SQ1, vx, vy);
      vy = vy + G_SPACE;
     }
    vx = vx + G_SPACE;
   } 
   
  //sprintf(printstr, "Press ESC to Quit!");
  //textout_centre(buffer, font, printstr, 320, 450, GREEN);
  
  //if(player == 0)
  //  textout(buffer, font, "Player 1's move", 10, 90, YELLOW);
  //else
  //  textout(buffer, font, "Player 2's move", 10, 90, RED);
  //textprintf_ex(buffer, font, 1, 1, GREEN, BLACK, "Hi");
  //
  
 }
////////////////////////////////////////////////////////////////////////////////  
void display_text(void)
 {
  //draws logo
  draw_sprite(buffer, LOGO, 92, 5);
  
  //displays whose move it is
  if(player == 0)
   draw_sprite(buffer, PL1, 10, 90);
  else 
   draw_sprite(buffer, PL2, 10, 90);
  
  //if valid move displays blue marker
  if(grid[spotx][spoty] == 'x' || grid[spotx][spoty] == 'o')
    display_movement();  
  //displays invalid move
  else if((mouse_x >= GX_START - 46 && mouse_x <= GX_END) &&
          (mouse_y >= GY_START - 46 && mouse_y <= GY_END))
   {
    if(player == 0)
     draw_sprite(buffer, INVALID, 29, 110);
    else
     draw_sprite(buffer, INVALID, 29, 110);
   }
    
 }
////////////////////////////////////////////////////////////////////////////////  
void display_marks(void)
 {
  int xdraw = 0;
  int ydraw = 0;
  
  for(short xcount = 0; xcount < 7; xcount++)
   {
    for(short ycount = 0; ycount < 6; ycount++)
     {
      if(grid[xcount][ycount] == 'X')
       {
        xdraw = GX_START + (ABOVE_MOUSE / 2) + (xcount * G_SPACE);
        ydraw = GY_START + (ABOVE_MOUSE / 2) + (ycount * G_SPACE);
        draw_sprite(buffer, X_MARK, xdraw, ydraw);
       }
      else if(grid[xcount][ycount] == 'O')
       {
        xdraw = GX_START + (ABOVE_MOUSE / 2) + (xcount * G_SPACE);
        ydraw = GY_START + (ABOVE_MOUSE / 2) + (ycount * G_SPACE);
        draw_sprite(buffer, O_MARK, xdraw, ydraw);
       }
     }  //end of 2nd for loop brace
   }  //end of 1st for loop brace
   
 }
//////////////////////////////////////////////////////////////////////////////// 
void display_movement(void)
 {
  int xdraw = 0;
  int ydraw = 0;
  
  //short x = 0;
  //short y = 0;
  
  xdraw = GX_START + (spotx * G_SPACE);
  ydraw = GY_START + (spoty * G_SPACE);
  
  draw_sprite(buffer, SQ2, xdraw, ydraw);
 
  //if(grid[spotx][placementx] == plch)
  /*hline(buffer, xdraw, ydraw, xdraw + G_SPACE, BLUE);
  hline(buffer, xdraw, ydraw + G_SPACE, xdraw + G_SPACE, BLUE);

  vline(buffer, xdraw, ydraw, ydraw + G_SPACE, BLUE);
  vline(buffer, xdraw + G_SPACE, ydraw, ydraw + G_SPACE, BLUE);*/
 } 
