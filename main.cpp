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
        //click register
        //first row
        hitbox(mousex, mousey, 0, 0, 100, 100, 7);
        hitbox(mousex, mousey, 100, 0, 200, 100, 8);
        hitbox(mousex, mousey, 200, 0, 300, 100, 9);
        //second row
        hitbox(mousex, mousey, 0, 100, 100, 200, 4);
        hitbox(mousex, mousey, 100, 100, 200, 200, 5);
        hitbox(mousex, mousey, 200, 100, 300, 200, 6);
        //third row
        if (hitbox(mousex, mousey, 0, 200, 100, 300, 1) == 1){
            
        }
        hitbox(mousex, mousey, 100, 200, 200, 300, 2);
        hitbox(mousex, mousey, 200, 200, 300, 300, 3);
        EndDrawing();
    }
    CloseWindow();

    return 0;
}