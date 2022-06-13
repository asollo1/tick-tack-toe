#include "include/raylib/raylib.h"
#include <iostream>

//Variables
//Mouse position
int mousex, mousey;
//Cells
int p1, p2, p3, p4, p5, p6, p7, p8, p9;
//Playesrs
bool isPlayerOne = true, isPlayerTwo = false, isWin = false;
//Functions
int hitbox(int mousex, int mousey, int fromx, int fromy, int tox, int toy, int key){
    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && mousex >= fromx  && mousey >= fromy && mousex <= tox && mousey <= toy or IsKeyDown(key)){
        return 1;
    }
    return 0;
}
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