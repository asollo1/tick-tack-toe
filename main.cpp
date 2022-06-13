#include "include/raylib/raylib.h"
#include <iostream>
#include <string>

//Variables
//Mouse position
int mousex, mousey;
//Cells
struct p {
    int startposx, startposy, endposx, endposy, status, keybind;
};
struct p p1 = {10, 10, 110, 110, 0, 49}, p2 = {110, 10, 220, 110, 0, 50}, p3 = {220, 10, 330, 110, 0, 51}, p4 = {10, 120, 110, 110, 0, 52}, p5 = {110, 120, 220, 220, 0, 53}, p6 = {220, 120, 330, 220, 0, 54}, p7 = {10, 230, 110, 330, 0, 55}, p8 = {110, 230, 220, 330, 0, 56}, p9 = {220, 230, 330, 330, 0, 55};
//Score
int scoreP1 = 0, scoreP2 = 0;
const char* playerAscore, *playerBscore;
//Playesrs
bool isPlayerOne = true, isPlayerTwo = false, isWinP1 = false, isWinP2 = false;
//Functions
int clear(){
    p1.status = 0;
    p2.status = 0;
    p3.status = 0;
    p4.status = 0;
    p5.status = 0;
    p6.status = 0;
    p7.status = 0;
    p8.status = 0;
    p9.status = 0;
}
int win(int player){
    if(p1.status==player){
        if(p2.status == player && p3.status == player or p5.status == player && p9.status == player or p4.status == player && p7.status == player){
            if(player==1){
                isWinP1 = true;
            }
            else{
                isWinP2 = true;
            }
            clear();
        }
    }
    if(p2.status==player && p5.status==player && p8.status==player){
        if(player==1){
            isWinP1 = true;
        }
        else{
            isWinP2 = true;
        }
        clear();
    }
    if (p3.status==player){
        if(p6.status == player && p9.status == player or p5.status == player && p7.status == player){
            if(player==1){
                isWinP1 = true;
            }
            else{
                isWinP2 = true;
            } 
            clear();
        }
    }
    if (p4.status==player && p5.status == player && p6.status == player){
        if(player==1){
            isWinP1 = true;
        }
        else{
            isWinP2 = true;
        }
        clear();
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
        //win check
        win(1);
        win(2);
        //Debugging
        DrawRectangle(10, 120, 100, 100, RED);
        EndDrawing();
    }
    CloseWindow();

    return 0;
}