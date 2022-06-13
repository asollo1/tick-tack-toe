#include "include/raylib/raylib.h"
#include <iostream>
#include <string>

//Variables
//Mouse position
int mousex, mousey;
//Cells
int p1, p2, p3, p4, p5, p6, p7, p8, p9;
//Score
int scoreP1 = 0, scoreP2 = 0;
const char* playerAscore, *playerBscore;
//Playesrs
bool isPlayerOne = true, isPlayerTwo = false, isWinP1 = false, isWinP2 = false;
//Functions
int win(int player){
    if(p1==player){
        if(p2 == player && p3 == player or p5 == player && p9 == player or p4 == player && p7 == player){
            isWinP2 = true;
        }
    }
    if(p2==player && p5==player && p8==player){
        isWinP2 = true;
    }
    if (p3==player){
        if(p6 == player && p9 == player or p5 == player && p7 == player){
            isWinP2 = true;
        }
    }
    if (p4==player && p5 == player && p6 == player){
        isWinP2= true;
    }
}
int hitbox(int mousex, int mousey, int fromx, int fromy, int tox, int toy, int key){
    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && mousex >= fromx  && mousey >= fromy && mousex <= tox && mousey <= toy or IsKeyDown(key)){
        return 1;
    }
    return 0;
}
//main function
int main(){
    
    //Initialization
    InitWindow(800,600,"Hello world!");
    SetTargetFPS(60);
    mousex = { GetMousePosition().x};
    mousey = { GetMousePosition().y};
    while(!WindowShouldClose()){
        BeginDrawing();
        ClearBackground(BLACK);

        //mouse position
        mousex = { GetMousePosition().x};
        mousey = { GetMousePosition().y};
        DrawText("number", mousex, mousey, 20, WHITE);
        //graphics interface
        //vertical lines
        DrawRectangle(0, 0, 10, 340, WHITE);
        DrawRectangle(110, 0, 10, 340, WHITE);
        DrawRectangle(220, 0, 10, 340, WHITE);
        DrawRectangle(330, 0, 10, 340, WHITE);
        //horizontal lines
        DrawRectangle(0, 0, 340, 10, WHITE);
        DrawRectangle(0, 110, 340, 10, WHITE);
        DrawRectangle(0, 220, 340, 10, WHITE);
        DrawRectangle(0, 330, 340, 10, WHITE);
        //score display
        playerAscore = std::to_string(scoreP1).c_str();
        playerBscore = std::to_string(scoreP2).c_str();
        //playerAscore = "Player A: " + playerAscore
        //playerBscore = "Player B: " + playerBscore
        DrawText("Score", 500, 100, 50, WHITE);
        DrawText("Player A: ", 450, 200, 50, WHITE);
        DrawText("Player B: ", 450, 300, 50, WHITE);
        DrawText(playerAscore, 700, 200, 50, WHITE);
        DrawText(playerBscore, 700, 300, 50, WHITE);
        //click register
        //first row
        hitbox(mousex, mousey, 10, 10, 110, 110, 7);
        hitbox(mousex, mousey, 110, 10, 220, 110, 8);
        hitbox(mousex, mousey, 220, 10, 330, 110, 9);
        //second row
        hitbox(mousex, mousey, 10, 120, 110, 220, 4);
        hitbox(mousex, mousey, 110, 120, 220, 220, 5);
        hitbox(mousex, mousey, 220, 120, 330, 220, 6);
        //third row
        hitbox(mousex, mousey, 10, 230, 110, 330, 1);
        hitbox(mousex, mousey, 110, 230, 220, 330, 2);
        hitbox(mousex, mousey, 220, 230, 330, 330, 3);

        //Debugging
        DrawRectangle(10, 120, 100, 100, RED);
        EndDrawing();
    }
    CloseWindow();

    return 0;
}