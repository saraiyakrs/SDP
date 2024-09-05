#include "FEHLCD.h"

#include "stdio.h"

#include "FEHUtility.h"

#include "math.h"

// Draw the menu

FEHIcon::Icon MenuDraw(FEHIcon::Icon square_button1[5])

{

    LCD.Clear(FEHLCD::Black);

    char labels[5][20] = {"Play Game!", "View Statistics", "View Instructions", "View Credits", "Exit"};

    FEHIcon::DrawIconArray(square_button1, 5, 1, 20, 20, 50, 50, labels, WHITE, WHITE);
}

FEHIcon::Icon Level1(int *winlvl1)

{

    // draw back button

    FEHIcon::Icon backbutton[5];

    char back[1][20] = {"Back"};

    float x, y, player_center, distance_from_enemy1,distance_from_enemy2,distance_from_enemy3;

    FEHIcon::DrawIconArray(backbutton, 1, 1, 200, 2, 2, 250, back, WHITE, WHITE);

    // draw four boxes for movement

    FEHIcon::Icon move_down_button;

    FEHIcon::Icon move_left_button;

    FEHIcon::Icon move_right_button;

    FEHIcon::Icon move_up_button;

    move_down_button.SetProperties("D", 235, 210, 25, 25, WHITE, WHITE);

    move_up_button.SetProperties("U", 235, 185, 25, 25, WHITE, WHITE);

    move_left_button.SetProperties("L", 210, 210, 25, 25, WHITE, WHITE);

    move_right_button.SetProperties("R", 260, 210, 25, 25, WHITE, WHITE);

    move_down_button.Draw();

    move_up_button.Draw();

    move_right_button.Draw();

    move_left_button.Draw();

    // draw playing field

    LCD.SetFontColor(BLUE);

    LCD.DrawRectangle(20, 20, 250, 150);

    // draw player box

    LCD.SetFontColor(RED);

    LCD.DrawRectangle(22, 22, 10, 10);

    // draw end goal

    LCD.SetFontColor(GOLD);

    LCD.DrawRectangle(250, 160, 20, 10);

    //set enemy y position (for now)
      float enemy_x1 =100,enemy_y1 = 100, enemy_x2 =150, enemy_y2=100, enemy_x3=200, enemy_y3=100;
    // draw enemies that move
    LCD.SetFontColor(GREEN);
    LCD.FillCircle(enemy_x1, enemy_y1, 10);
    LCD.SetFontColor(GREEN);
    LCD.FillCircle(enemy_x2, enemy_y2, 10);
    LCD.SetFontColor(GREEN);
    LCD.FillCircle(enemy_x3, enemy_y3, 10);

    

    // move player down when button is pressed

    float playery = 22, playerx = 22;

    while (!backbutton[0].Pressed(x, y, 0) && *winlvl1 != 1)

    {

        if (LCD.Touch(&x, &y))

        {
            if (enemy_y1<150)
            {
                LCD.SetFontColor(BLACK);
                LCD.FillCircle(enemy_x1, enemy_y1,10);
                enemy_y1+=5;
                LCD.SetFontColor(GREEN);
                LCD.FillCircle(enemy_x1, enemy_y1,10);
                Sleep(10);
            }
            if (enemy_y1>=150)
            {
                LCD.SetFontColor(BLACK);
                LCD.FillCircle(enemy_x1, enemy_y1,10);
                enemy_y1=32;
                LCD.SetFontColor(GREEN);
                LCD.FillCircle(enemy_x1, enemy_y1,10);
            }
           if (enemy_y2>32)
            {
                LCD.SetFontColor(BLACK);
                LCD.FillCircle(enemy_x2, enemy_y2,10);
                enemy_y2-=3;
                LCD.SetFontColor(GREEN);
                LCD.FillCircle(enemy_x2, enemy_y2,10);
                Sleep(10);
            }
            if (enemy_y2<=32)
            {
                LCD.SetFontColor(BLACK);
                LCD.FillCircle(enemy_x2, enemy_y2,10);
                enemy_y2=158;
                LCD.SetFontColor(GREEN);
                LCD.FillCircle(enemy_x2, enemy_y2,10);
            }
            if (enemy_y3<150)
            {
                LCD.SetFontColor(BLACK);
                LCD.FillCircle(enemy_x3, enemy_y3,10);
                enemy_y3+=5;
                LCD.SetFontColor(GREEN);
                LCD.FillCircle(enemy_x3, enemy_y3,10);
                Sleep(10);
            }
            if (enemy_y3>=150)
            {
                LCD.SetFontColor(BLACK);
                LCD.FillCircle(enemy_x3, enemy_y3,10);
                enemy_y3=32;
                LCD.SetFontColor(GREEN);
                LCD.FillCircle(enemy_x3, enemy_y3,10);
            }
            if (move_down_button.Pressed(x, y, 0))

            {

                LCD.SetFontColor(BLACK);

                LCD.FillRectangle(playerx, playery, 10, 10);

                if (playery < 156)
                playery += 2;

                LCD.SetFontColor(RED);

                LCD.DrawRectangle(playerx, playery, 10, 10);
            }

            if (move_up_button.Pressed(x, y, 0))

            {

                LCD.SetFontColor(BLACK);

                LCD.FillRectangle(playerx, playery, 10, 10);

                if (playery > 22)
                playery -= 2;

                LCD.SetFontColor(RED);

                LCD.DrawRectangle(playerx, playery, 10, 10);
            }

            if (move_right_button.Pressed(x, y, 0))

            {

                LCD.SetFontColor(BLACK);

                LCD.FillRectangle(playerx, playery, 10, 10);

                if (playerx < 255)
                playerx += 2;

                LCD.SetFontColor(RED);

                LCD.DrawRectangle(playerx, playery, 10, 10);
            }

            if (move_left_button.Pressed(x, y, 0))

            {

                LCD.SetFontColor(BLACK);

                LCD.FillRectangle(playerx, playery, 12, 12);

                if (playerx > 22)
                playerx -= 2;

                LCD.SetFontColor(RED);

                LCD.DrawRectangle(playerx, playery, 10, 10);


            }

            distance_from_enemy1 = pow(pow(enemy_x1-playerx-5,2)+pow(enemy_y1-playery+5,2),0.5);
            distance_from_enemy2 = pow(pow(enemy_x2-playerx-5,2)+pow(enemy_y2-playery+5,2),0.5);
            distance_from_enemy3 = pow(pow(enemy_x3-playerx-5,2)+pow(enemy_y3-playery+5,2),0.5);
            if (distance_from_enemy1<15.0 || distance_from_enemy2<15.0 || distance_from_enemy3<15.0)
            {
                LCD.SetFontColor(BLACK);

                LCD.FillRectangle(playerx, playery, 10, 10);
                 LCD.SetFontColor(BLACK);
                LCD.FillCircle(enemy_x1, enemy_y1,10);
                LCD.SetFontColor(GREEN);
                LCD.FillCircle(enemy_x1, enemy_y1,10);
                playerx=22;
                playery=22;
                LCD.SetFontColor(RED);

                LCD.DrawRectangle(22, 22, 10, 10);
            }
            if (playerx >= 250 && playerx <= 270 && playery >= 140 && playery <= 190)

            {

                *winlvl1 = 1;
            }

        } // delete this after
    }


    // draw start and end points

    FEHIcon::Icon start;

    FEHIcon::Icon stop;

     //draw enemies and obstacles
   
    
}

FEHIcon::Icon Level2(int *winlvl2) {
    FEHIcon::Icon backbutton[5];

    char back[1][20] = {"Back"};

    float x, y;

    FEHIcon::DrawIconArray(backbutton, 1, 1, 200, 2, 2, 250, back, WHITE, WHITE);
    FEHIcon::Icon move_down_button;

    FEHIcon::Icon move_left_button;

    FEHIcon::Icon move_right_button;

    FEHIcon::Icon move_up_button;

    move_down_button.SetProperties("D", 235, 210, 25, 25, WHITE, WHITE);

    move_up_button.SetProperties("U", 235, 185, 25, 25, WHITE, WHITE);

    move_left_button.SetProperties("L", 210, 210, 25, 25, WHITE, WHITE);

    move_right_button.SetProperties("R", 260, 210, 25, 25, WHITE, WHITE);

    move_down_button.Draw();

    move_up_button.Draw();

    move_right_button.Draw();

    move_left_button.Draw();

    // draw playing field

    LCD.SetFontColor(BLUE);

    LCD.DrawRectangle(20, 20, 250, 150);

    // draw player box

    LCD.SetFontColor(RED);

    LCD.DrawRectangle(22, 22, 10, 10);

    // draw end goal

    LCD.SetFontColor(GOLD);

    LCD.DrawRectangle(250, 120, 20, 10);
    int playery = 22, playerx = 22;

    while (!backbutton[0].Pressed(x, y, 0) && *winlvl2 != 1)

    {

        if (LCD.Touch(&x, &y))

        {


            if (move_down_button.Pressed(x, y, 0))

            {

                LCD.SetFontColor(BLACK);

                LCD.FillRectangle(playerx, playery, 10, 10);

                if (playery < 156)
                playery += 2;

                LCD.SetFontColor(RED);

                LCD.DrawRectangle(playerx, playery, 10, 10);
            }

            if (move_up_button.Pressed(x, y, 0))

            {

                LCD.SetFontColor(BLACK);

                LCD.FillRectangle(playerx, playery, 10, 10);

                if (playery > 22)
                playery -= 2;

                LCD.SetFontColor(RED);

                LCD.DrawRectangle(playerx, playery, 10, 10);
            }

            if (move_right_button.Pressed(x, y, 0))

            {

                LCD.SetFontColor(BLACK);

                LCD.FillRectangle(playerx, playery, 10, 10);

                if (playerx < 255)
                playerx += 2;

                LCD.SetFontColor(RED);

                LCD.DrawRectangle(playerx, playery, 10, 10);
            }

            if (move_left_button.Pressed(x, y, 0))

            {

                LCD.SetFontColor(BLACK);

                LCD.FillRectangle(playerx, playery, 12, 12);

                if (playerx > 22)
                playerx -= 2;

                LCD.SetFontColor(RED);

                LCD.DrawRectangle(playerx, playery, 10, 10);


            }

            if (playerx >= 250 && playerx <= 270 && playery >= 120 && playery <= 190)

            {

                *winlvl2 = 1;
            }

        } // delete this after
    }

}
FEHIcon::Icon Level3() {
    
}
FEHIcon::Icon Level4() {
    
}
FEHIcon::Icon Level5() {
    
}

FEHIcon::Icon CreateMenu()

{

    LCD.Update();

    // clear screen to black to see icon

    LCD.Clear(BLACK);

    // declare icon array called square_button of size 5

    FEHIcon::Icon square_button1[5];

    FEHIcon::Icon backbutton[5];

    // Declare Four Separate icons for Movement

    // declare string for icon label

    char backlabel[5][20] = {"Back", "Back", "Back", "Back", "Back"};

    // draw icon in a 1 by 1 array, with top and bottom margins of 20 pixels and left and right margins of 60 pixels

    // use label, and make icon border white and icon text white

    // update the LCD screen

    LCD.Update();

    // continuously check to see if the icon is pressed and

    // increment the number of presses label if so

    int n = 0;

    float x, y;

    int winlvl1 = 0;
    int winlvl2 = 0;

    int gamestate = 0;

    char back[1][20] = {"Back"};

    char move[4][10] = {"Left", "Right", "Up", "Down"};

    char levelmenu[2][30] = {"Level Select", "Start New Game"};

    MenuDraw(square_button1);

    while (true)

    {

        if (LCD.Touch(&x, &y))

        {

            if (gamestate == 0)

            {

                if (square_button1[0].Pressed(x, y, 0))

                {

                    LCD.Clear(FEHLCD::Black);

                    LCD.WriteLine("Welcome to");

                    LCD.WriteLine("FEH's Hardest Game!");

                    // Sleep(2.25);

                    LCD.WriteLine("What you are about");

                    LCD.WriteLine("to experience...");

                    // Sleep(2.25);

                    LCD.WriteLine("May be harder");

                    LCD.WriteLine("Than FEH itself");

                    // Sleep(2.5);

                    LCD.Clear(FEHLCD::Black);

                    LCD.WriteLine("Good Luck!");

                    // Sleep(2.25);

                    LCD.Clear(FEHLCD::Black);

                    LCD.WriteLine("Level 1");

                    gamestate = 1;

                    FEHIcon::DrawIconArray(backbutton, 1, 1, 200, 2, 2, 250, back, WHITE, WHITE);

                    Sleep(0.25);

                    // play level one

                    Level1(&winlvl1);

                    if (winlvl1 == 1) {
                    LCD.Clear(FEHLCD::Black);
                    LCD.SetFontColor(WHITE);
                    LCD.WriteLine("You thought that was easy didn't you?");
                    Sleep(3.0);
                    LCD.SetFontColor(WHITE);
                    LCD.WriteLine("Maybe you are better than I thought.");
                    Sleep(3.0);
                    LCD.SetFontColor(WHITE);
                    LCD.WriteLine("Now we will see how you do on level 2.");
                    Sleep(3.0);
                    LCD.SetFontColor(WHITE);
                    LCD.Clear(FEHLCD::Black);
                    LCD.WriteLine("Level 2");
                    
                }
                    Level2(&winlvl2); 
                    if (winlvl2 == 1) {
                    LCD.Clear(FEHLCD::Black); 
                    LCD.SetFontColor(WHITE);
                    LCD.WriteLine("You are better than I thought.");
                    Sleep(3.0);
                    }

                else if (square_button1[1].Pressed(x, y, 0))

                {

                    LCD.Clear(FEHLCD::Black);

                    LCD.WriteLine("Fail Counter: 0");

                    LCD.WriteLine("Levels Successfully Completed: 0");

                    FEHIcon::DrawIconArray(backbutton, 1, 1, 175, 2, 2, 250, back, WHITE, WHITE);

                    gamestate = 1;

                    Sleep(0.25);
                }

                else if (square_button1[2].Pressed(x, y, 0))

                {

                    LCD.Clear(FEHLCD::Black);

                    LCD.WriteLine("Instructions:");

                    LCD.WriteLine("1. User will start in the top left corner of the screen.");

                    LCD.WriteLine("2. User will use up, down, left, and right buttons to move.");

                    LCD.WriteLine("3. User will complete level by reaching the end corner of the screen.");

                    gamestate = 1;

                    FEHIcon::DrawIconArray(backbutton, 1, 1, 175, 2, 2, 250, back, WHITE, WHITE);

                    Sleep(0.25);
                }

                else if (square_button1[3].Pressed(x, y, 0))

                {

                    LCD.Clear(FEHLCD::Black);

                    LCD.WriteLine("Game Created By:");

                    LCD.WriteLine("Krishna Saraiya and Isaac Shah");

                    LCD.WriteLine("\n");

                    LCD.WriteLine("Refrences: FEH Proteus Guide, SDP Design Project Files");

                    FEHIcon::DrawIconArray(backbutton, 1, 1, 175, 2, 2, 250, back, WHITE, WHITE);

                    gamestate = 1;

                    Sleep(0.25);
                }

                else if (square_button1[4].Pressed(x, y, 0))

                {

                    LCD.Clear(FEHLCD::Black);

                    Sleep(1.0);

                    break;
                }
            }

            else if (gamestate == 1)

            {

                if (backbutton[0].Pressed(x, y, 0))

                {

                    gamestate = 0;

                    MenuDraw(square_button1);

                    Sleep(0.25);
                }
            }
        }
    }
}

}

int main()

{

    CreateMenu();

    return 0;
}