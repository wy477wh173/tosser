//Tosser
//Simple Artilery Clone for Arduboy
//Credit; RMW Games: Robert White, Michael White, Wyatt White

//importing arduboy libraries
#include <Arduboy2.h>
Arduboy2 ardb;
//Arduboy2 arduboy;
//////////////////////////////////////////////////////////////////////////////////////////////////////////////Definitions
//variable init // these were used in the initial test, have since been removed
//byte drawx;
//byte drawy;
const char rmw_games[] = "RMW Games";
const char  devs[] = "Robert White,\n Michael White,\n and Wyatt White";

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

const byte menu_spacer = 12;//dictates spacing of menu items

//define player values
byte player_turn = 1;

/*player1
short p1_power = 0;
short p1_angle = 0;
byte p1_fired = 0;
byte p1_life = 3;
short p1_ammo = 24;

short p2_power = 0;
short p2_angle = 0;
byte p2_fired = 0;
byte p2_life = 3;
short p2_ammo = 24;
*/
byte angleA = 0;
byte angleB = 0;
byte powerA = 0;
byte powerB = 0;
byte wind = 0;
byte locationX;
byte locationY;
byte powersX;
byte powesY;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////Definitions End

//////////////////////////////////////////////////////////////////////////////////////////////////////////////Game States
void draw_menu()
{ //this should draw a really simple menu
  //draw cursor @ 16 * menu_state
  //should draw a rounded rectangle under the current selection

  //ardb.drawRoundRect(2, 16 * menu_state - 1, 32, 16, 5);

  ardb.drawRoundRect(2, menu_spacer * menu_state, 32, menu_spacer, 5);


  //play item // menu state 1
  ardb.setCursor(3, menu_spacer * 1);
  ardb.write(play);

  //help item // menu state 2
  ardb.setCursor(3, menu_spacer * 2);
  ardb.write(help);

  //credit item // menu state 3
  ardb.setCursor(3, menu_spacer * 3);
  ardb.write(credit);

  //move cursor
  if (ardb.justPressed(UP_BUTTON) && menu_state > 1)
  {
    menu_state += -1;
  }

  if (ardb.justPressed(DOWN_BUTTON) && menu_state < 3)
  {
    menu_state += 1;
  }


  if (ardb.pressed(A_BUTTON))
  {
    //Sets game state = menu state // (0 = Menu, 1 = game, 2 = help, 3 = credit)
    game_state = menu_state;
  }
}

void draw_credit()
{ //this should just draw our names
  //draw RMW Games
  ardb.setCursor(WIDTH / 2, 0);
  ardb.write(rmw_games);

  ardb.setCursor(1, 12);
  ardb.write(devs);

  if (ardb.justPressed(B_BUTTON))
  { //go back to main menu
    game_state = 0;
  }
}





void draw_game()
{
  //this should be a really simple fire & fire loop
  //

  /*if (player_turn == 1)
  { // first player turn
    //aiming up and down
    if (ardb.justPressed(UP_BUTTON))
    {
      p1_angle += 1;
    }
    if (ardb.justPressed(DOWN_BUTTON))
    {
      p1_angle += -1;
    }

    if (ardb.justPressed(RIGHT_BUTTON) && p1_power < 10)
    {
      p1_power += 1;
    }
    if (ardb.justPressed(LEFT_BUTTON) && p1_power > 0)
    {
      p1_power += -1;
    }

    if (ardb.justPressed(A_BUTTON)) //firing
    {
      //this should trigger firing thing
    }
  }

  if (player_turn == 2)
  { //second player turn
    //aiming up and down
    if (ardb.justPressed(UP_BUTTON)) //maybe we want to check this per-frame?
    {
      p2_angle += 1;
    }
    if (ardb.justPressed(DOWN_BUTTON))
    {
      p2_angle += -1;
    }

    if (ardb.justPressed(RIGHT_BUTTON) && p2_power < 10)
    {
      p2_power += 1;
    }
    if (ardb.justPressed(LEFT_BUTTON) && p2_power > 0)
    {
      p2_power += -1;
    }

    if (ardb.justPressed(A_BUTTON)) //firing
    {
      //this should trigger firing thing
    }
  }

  //we should draw both players and their shots down here.
  //. . . . somehow
*/
  //ardb.pollButtons();
  //set angle
  if (ardb.justPressed(DOWN_BUTTON))
  {
    angleA = angleA - 1;
  }
  if (ardb.justPressed(UP_BUTTON))
  {
    angleA = angleA + 1;
  }
  //set powerA
  if (ardb.justPressed(LEFT_BUTTON))
  {
    powerA = powerA - 1;
  }
  if (ardb.justPressed(RIGHT_BUTTON))
  {
    powerA = powerA + 1;
  }
  //set random wind
  if (ardb.justPressed(A_BUTTON))
  {
    wind = random(0 - 26);
  }
  //wind = random(0 - 26);

  // print results of angle, power and wind
  ardb.setCursor(0, 0);
  ardb.print("Angle");
  ardb.print(angleA);
  ardb.print("power");
  ardb.print(powerA);
  ardb.print("wind");
  ardb.print(wind);

  Serial.print("Angle");
  Serial.print(angleA);
  Serial.print("power");
  Serial.print(powerA);
  Serial.print("wind");
  Serial.print(wind);


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
    //draw background
    for (int backgroundx = 0; backgroundx < 128; backgroundx = backgroundx + 8)
    {
    for (int backgroundy = 0; backgroundy < 64; backgroundy = backgroundy + 8)
    {
      //Sprites::drawOverwrite(backgroundx, backgroundy, background, 0);
    }
    }

    //draw player
    Sprites::drawOverwrite(locationX, locationY, player, 0);
    
  
}
/////////////////////////////////////////////////////////////////////////////////////////////////Game states end

/////////////////////////////////////////////////////////////////////////////////////////////////Master loops
void setup() {
  // put your setup code here, to run once:
  ardb.begin();
  ardb.setFrameRate(30);


  /*int angleA = 0;
    int angleB = 0;
    int powerA = 0;
    int powerB = 0;
    int wind = 0;
  */
  //initiates random number for wind
  ardb.initRandomSeed();
  //serial monitor
  Serial.begin(9600);
}

void loop()
{
  // put your main code here, to run repeatedly:
  ardb.clear();
  ardb.pollButtons();//for justPressed and justReleased
  if (game_state == 0) //menu
  {
    draw_menu();
  }
  if(game_state == 1)//menu
    {draw_game();}
  //if(game_state == 2)//help
  //  {draw_help();}
  if (game_state == 3) //credit
  {draw_credit();}


  // draw screen
  ardb.display();

  
}
////////////////////////////////////////////////////////////////////////////////////////////Master loops end
