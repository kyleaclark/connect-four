#include <allegro.h>
#include "setup.h"
#include "bitmap_load.h"

// <- VARIABLES -> //
volatile int counter;



// <- FUNCTIONS -> //
void init() {
	int depth, res;	
	allegro_init();	
	depth = desktop_color_depth();	
	if (depth == 0) 
     depth = 32;    
	set_color_depth(depth);	
	res = set_gfx_mode(GFX_AUTODETECT_WINDOWED, 640, 480, 0, 0);
	perform_creations();  //to create bitmaps, etc...
	if (res != 0) 
     {
		allegro_message(allegro_error);
		exit(-1);
	 }

	install_timer();
	install_keyboard();
	install_mouse();
	
	if(mouse_needs_poll() == true)
	  poll_mouse();
	/* add other initializations here */
}
//////////////////////////////////////////////////////////////////////////////// 
void update_counter()
 {
  counter++;
 }
//////////////////////////////////////////////////////////////////////////////// 
void deinit() 
{
	clear_keybuf();
	destroy_bitmap(buffer);
	/* add other deinitializations here */
}
