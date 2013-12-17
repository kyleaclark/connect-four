#include <allegro.h>
#include "bitmap_load.h"
#include "display.h"

// <- VARIABLES -> //
BITMAP *buffer;
BITMAP *SQ1;
BITMAP *SQ2;
BITMAP *X_MARK;
BITMAP *O_MARK;
BITMAP *WIN;
BITMAP *LOGO;
BITMAP *PL1;
BITMAP *PL2;
BITMAP *INVALID;
//BITMAP *CIRCLE;


// <- FUNCTIONS -> //
void perform_creations(void)
 {
  buffer = create_bitmap(SCREEN_W, SCREEN_H);
  SQ1 = load_bitmap("SQ1.bmp", NULL);
  SQ2 = load_bitmap("SQ2.bmp", NULL);
  X_MARK = load_bitmap("X.bmp", NULL);
  O_MARK = load_bitmap("O.bmp", NULL);
  WIN = load_bitmap("WIN.bmp", NULL);
  LOGO = load_bitmap("LOGO.bmp", NULL);
  PL1 = load_bitmap("PL1.bmp", NULL);
  PL2 = load_bitmap("PL2.bmp", NULL);
  INVALID = load_bitmap("INVALID.bmp", NULL);
  //CIRCLE = create_bitmap(50, 50);
  //circlefill(CIRCLE, 25, 25, 25, GREEN);
  
 }
