//Tosser
//Simple Artilery Clone for Arduboy
//Credit; RMW Games: Robert White, Michael White, Wyatt White

//importing arduboy libraries
#include <Arduboy2.h>
Arduboy2 ardb;
//////////////////////////////////////////////////////////////////////////////////////////////////////////////Definitions
//variable init // these were used in the initial test, have since been removed
//byte drawx;
//byte drawy;
//char intro[]= "RMW Games";

//menu definitions
const char play[] = "Play";
const char help[] = "Help";
const char credit[] = "Credit";

//didn't actually need these, so commented out, just used math instead
//const byte playy = 16;
//const byte helpy = 32;
//const byte credity = 48;

//define game state (0 = Menu, 1 = game, 2 = help, 3 = credit) 
byte game_state = 0;
byte menu_state = 1;
//////////////////////////////////////////////////////////////////////////////////////////////////////////////Definitions End

//////////////////////////////////////////////////////////////////////////////////////////////////////////////Game States
void draw_menu()
  {//this should draw a really simple menu
  //draw cursor @ 16 * menu_state
  //should draw a rounded rectangle under the current selection
   ardb.drawRoundRect(2,16*menu_state,32,16,5);
    
   //play item // menu state 1
    ardb.setCursor(3,16 * 1);
    ardb.write(play);
   
   //help item // menu state 2
    ardb.setCursor(3,16 * 2);
    ardb.write(help);

   //credit item // menu state 3
    ardb.setCursor(3,16 * 3);
    ardb.write(credit);
   
   //move cursor
    if(ardb.justPressed(UP_BUTTON) && menu_state > 1)
      {
      menu_state += -1;
      }

      if(ardb.justPressed(DOWN_BUTTON) && menu_state < 2)
      {
      menu_state += 1;
      }

    if(ardb.justPressed(A_BUTTON))
     {
      //Sets game state = menu state // (0 = Menu, 1 = game, 2 = help, 3 = credit) 
      game_state = menu_state;
     }
  }

void draw_credit()
  {//this should just draw our names
    
  }
/////////////////////////////////////////////////////////////////////////////////////////////////Game states end

/////////////////////////////////////////////////////////////////////////////////////////////////Master loops
void setup() {
  // put your setup code here, to run once:
  ardb.begin();
  ardb.setFrameRate(30);
  
}

void loop() 
  {
  // put your main code here, to run repeatedly:
  ardb.clear();
  if(game_state == 0)//menu
    {draw_menu();}
  //if(game_state == 1)//menu
  //  {draw_game();}
  //if(game_state == 2)//help
  //  {draw_menu();}
  if(game_state == 3)//credit
    {draw_credit();}

    
  // draw screen
  ardb.display();
  }
  ////////////////////////////////////////////////////////////////////////////////////////////Master loops end
