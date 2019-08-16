//Tosser
//Simple Artilery Clone for Arduboy
//Credit; RMW Games: Robert White, Michael White, Wyatt White

//importing arduboy libraries
#include <Arduboy2.h>
Arduboy2 ardb;
Arduboy2 arduboy;
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


//background sprite

const unsigned char PROGMEM background[] =
{
  // width, height,
  8, 8,
  0x81, 0x00, 0x12, 0x40, 0x04, 0x11, 0x00, 0x04,
};

//player sprite
const unsigned char PROGMEM player[] =
{
  // width, height,
  16, 16,
  0xfe, 0x01, 0x3d, 0x25, 0x25, 0x3d, 0x01, 0x01, 0xc1, 0x01, 0x3d, 0x25, 0x25, 0x3d, 0x01, 0xfe,
  0x7f, 0x80, 0x9c, 0xbc, 0xb0, 0xb0, 0xb2, 0xb2, 0xb3, 0xb0, 0xb0, 0xb0, 0xbc, 0x9c, 0x80, 0x7f,
};
//////////////////////////////////////////////////////////////////////////////////////////////////////////////Definitions End

//////////////////////////////////////////////////////////////////////////////////////////////////////////////Game States
void draw_menu()
  {//this should draw a really simple menu
  //draw cursor @ 16 * menu_state
  //should draw a rounded rectangle under the current selection
   ardb.drawRoundRect(2,16*menu_state - 1,32,16,5);
    
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
    if(ardb.pressed(UP_BUTTON) && menu_state > 1)
      {
      menu_state --;
      }

      if(ardb.pressed(DOWN_BUTTON) && menu_state < 3)
      {
      menu_state ++;
      }

    if(ardb.pressed(A_BUTTON))
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

   
  angleA = 0;
  angleB = 0;
  powerA = 0;
  powerB = 0;
  wind = 0;
  //initiates random number for wind
  arduboy.initRandomSeed();
  //serial monitor
  Serial.begin(9600);
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

    //check buttons
  arduboy.pollButtons();

  //set angle
  if(arduboy.justPressed(DOWN_BUTTON))
  {
    angleA = angleA - 1;
  }
  if(arduboy.justPressed(UP_BUTTON))
  {
    angleA = angleA + 1;
  }
  //set powerA
  if(arduboy.justPressed(LEFT_BUTTON))
  {
    powerA = powerA - 1;
  }
  if(arduboy.justPressed(RIGHT_BUTTON))
  {
    powerA = powerA + 1;
  }
  //set random wind
  wind = random(0 - 26);

  // print results of angle, power and wind
  arduboy.setCursor(0, 0);
  arduboy.print("Angle");
  arduboy.print(angleA);
  arduboy.print("power");
  arduboy.print(powerA);
  arduboy.print("wind");
  arduboy.print(wind);
  arduboy.display();


 Serial.print("Angle");
  Serial.print(angleA);
 Serial.print("power");
  Serial.print(powerA);
  Serial.print("wind");
  Serial.print(wind);
  
  //pause for speed
  delay (1000);

  //location math
  locationX = (powerA);
  locationY = (angleA);

  //location math for ark
  /*
    if locationY <= 64
    {
    locationX = locationX + wind;
    locationY = pow(locationY,powersY);
    powersX = powersX + 1;
    powersY = powersY + 1;
    }
    else
    {
    locationX = locationX + wind;
    locationY = locationY - (angleA * powersY);
    powersY = powersY - 1;
    }
  */
  /*clear screen
  arduboy.clear();

  //draw background
  for (int backgroundx = 0; backgroundx < 128; backgroundx = backgroundx + 8)
  {
    for (int backgroundy = 0; backgroundy < 64; backgroundy = backgroundy + 8)
    {
      Sprites::drawOverwrite(backgroundx, backgroundy, background, 0);
    }
  }

  //draw player
  Sprites::drawOverwrite(locationX, locationY, player, 0);
  arduboy.display();
  */
  }
  ////////////////////////////////////////////////////////////////////////////////////////////Master loops end
