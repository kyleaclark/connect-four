#include <allegro.h>
#include <string.h>
#include "setup.h"
#include "bitmap_load.h"
#include "board.h"
#include "display.h"

//using namespace std;



int main() 
 {
  //mouse variables
  int mickey_x, mickey_y;
 
  init();

  set_grid();
  //show_mouse(screen);
  display();
  
      /*uncomment later on.  used to detect if the OS needs to have the mouse
      polled for the variables
    if(mouse_needs_poll() == true)
	  poll_mouse();  
    */ 

  while (!key[KEY_ESC]) 
   {
    // How much has the mouse moved? //
    get_mouse_mickeys( &mickey_x, &mickey_y );
    
    //do this if the left mouse button is clicked
    if(mouse_b & 1)
     {
      /*mouse_x, mouse_y are to send the mouse coordinates to the function
      the 1 is to indicate player 1 is in use (irrelevant so far)
      the true is to indicate that mouse button has been clicked
      if true then a marker should appear in the grid*/
      find_loc(mouse_x, mouse_y, true);
      
      //displays the graphics
      display();
     } 
    /*checks to make sure the mouse button hasn't been clicked and also checks
    to see if there has been any mouse movement since the last call*/   
    else if(mickey_x != 0 || mickey_y != 0)
     {
      /*if false then the mouse keeps moving but highlights the part of the grid
      it is hovering over*/
      find_loc(mouse_x, mouse_y, false);
      
      //displays the graphics
      display();
     }  

   } //end main while brace
   

  deinit();
  
  return 0;
 }
END_OF_MAIN();


