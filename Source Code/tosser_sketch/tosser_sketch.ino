//Tosser
//Simple Artilery Clone for Arduboy
//Credit; RMW Games: Robert White, Michael White, Wyatt White

//importing arduboy libraries
#include <Arduboy2.h>
Arduboy2 ardb;

//variable init
byte drawx;
byte drawy;
char text[]= "RMW Games";

byte draw_text = 0;


//comument
void setup() {
  // put your setup code here, to run once:
  ardb.begin();
  ardb.setFrameRate(30);
  
}

void loop() {
  // put your main code here, to run repeatedly:

  //move cursor
  //up
  if(ardb.pressed(UP_BUTTON))
    {
      drawy --;
    }
  //down
  if(ardb.pressed(DOWN_BUTTON))
    {
      drawy ++;
    }

  //left
  if(ardb.pressed(LEFT_BUTTON))
    {
      drawx --;
    }
  //right
  if(ardb.pressed(RIGHT_BUTTON))
    {
      drawx ++;
    }

  //check if A pressed
  //draw_text = 0;
  if(ardb.pressed(A_BUTTON))
    {
      if(draw_text == 1)
        {
        draw_text = 0;
        }else{draw_text = 1;}
    }

  //setting graphics
  //clear last frame gfx
  ardb.clear();

  //check if text_draw bitis flipped
  if(draw_text == 0)
  {
    //draw cursor if button not pressed this frame
    ardb.drawPixel(drawx,drawy);
  }

  if(draw_text == 1)
    {
      //draw text if A pressed this frame
      ardb.setCursor(drawx,drawy);
      ardb.write(text);
    }
// draw screen
ardb.display();
}
