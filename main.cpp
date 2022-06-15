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
struct p p1 = {10, 10, 110, 110, 0, 49}, p2 = {120, 10, 220, 110, 0, 50}, p3 = {230, 10, 330, 110, 0, 51}, p4 = {10, 120, 110, 220, 0, 52}, p5 = {120, 120, 220, 220, 0, 53}, p6 = {230, 120, 330, 220, 0, 54}, p7 = {10, 230, 110, 330, 0, 55}, p8 = {120, 230, 220, 330, 0, 56}, p9 = {230, 230, 330, 330, 0, 55};
//Score
int scoreP1 = 0, scoreP2 = 0, count = 0;
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
    isPlayerTwo = false;
    isPlayerOne = true;
    if (isWinP1){
        scoreP1 = scoreP1 +1;
    }
    else if(isWinP2){
        scoreP2 = scoreP2 +1;
    }
    isWinP1 = false;
    isWinP2 = false;
    count = 0;
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
        return true;
    }
    return false;
}
int cellfill(int status, int x, int y){
    x = x + 50;
    y = y + 50;
    if (status == 1){
        DrawCircle(x, y, 45, RED);
        DrawCircle(x, y, 30, BLACK);
    }
    if (status == 2){
        int endx, endy;
        x = x - 40;
        y = y + 40;
        endx = x + 80;
        endy = y - 80;
        DrawLine(x, y, endx, endy, GREEN);
        DrawLine(endx, y, x, endy, GREEN);
    }
}
//main function
int main(){
    
    //Initialization
    InitWindow(800,600,"Tick tack toe");
    SetTargetFPS(60);
    mousex = { GetMousePosition().x};
    mousey = { GetMousePosition().y};
    while(!WindowShouldClose()){
        BeginDrawing();
        ClearBackground(BLACK);

        //mouse position
        mousex = { GetMousePosition().x};
        mousey = { GetMousePosition().y};
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
        DrawText("Score", 500, 100, 50, WHITE);
        DrawText("Player A: ", 450, 200, 50, WHITE);
        DrawText("Player B: ", 450, 300, 50, WHITE);
        DrawText(std::to_string(scoreP1).c_str(), 700, 200, 50, WHITE);
        DrawText(std::to_string(scoreP2).c_str(), 700, 300, 50, WHITE);
        //click register
        //first row
        if(hitbox(mousex, mousey, p1.startposx, p1.startposy, p1.endposx, p1.endposy, p1.keybind)){
            if (p1.status==0){
                if (isPlayerOne){
                    isPlayerOne = false;
                    isPlayerTwo = true;
                    p1.status = 1;
                    count++;continue;
                }
                if (isPlayerTwo){
                    isPlayerTwo = false;
                    isPlayerOne = true;
                    p1.status = 2;
                    count++;continue;
                }
            }
        }
        if(hitbox(mousex, mousey, p2.startposx, p2.startposy, p2.endposx, p2.endposy, p2.keybind)){
            if (p2.status==0){
                if (isPlayerOne){
                    isPlayerOne = false;
                    isPlayerTwo = true;
                    p2.status = 1;
                    count++;continue;
                }
                if (isPlayerTwo){
                    isPlayerTwo = false;
                    isPlayerOne = true;
                    p2.status = 2;
                    count++;continue;
                }
            }
        }
        if(hitbox(mousex, mousey, p3.startposx, p3.startposy, p3.endposx, p3.endposy, p3.keybind)){
            if (p3.status==0){
                if (isPlayerOne){
                    isPlayerOne = false;
                    isPlayerTwo = true;
                    p3.status = 1;
                    count++;continue;
                }
                if (isPlayerTwo){
                    isPlayerTwo = false;
                    isPlayerOne = true;
                    p3.status = 2;
                    count++;continue;
                }
            }
        }
        //second row
        if(hitbox(mousex, mousey, p4.startposx, p4.startposy, p4.endposx, p4.endposy, p4.keybind)){
            if (p4.status==0){
                if (isPlayerOne){
                    isPlayerOne = false;
                    isPlayerTwo = true;
                    p4.status = 1;
                    count++;continue;
                }
                if (isPlayerTwo){
                    isPlayerTwo = false;
                    isPlayerOne = true;
                    p4.status = 2;
                    count++;continue;
                }
            }
        }
        if(hitbox(mousex, mousey, p5.startposx, p5.startposy, p5.endposx, p5.endposy, p5.keybind)){
            if (p5.status==0){
                if (isPlayerOne){
                    isPlayerOne = false;
                    isPlayerTwo = true;
                    p5.status = 1;
                    count++;continue;
                }
                if (isPlayerTwo){
                    isPlayerTwo = false;
                    isPlayerOne = true;
                    p5.status = 2;
                    count++;continue;
                }
            }
        }
        if(hitbox(mousex, mousey, p6.startposx, p6.startposy, p6.endposx, p6.endposy, p6.keybind)){
            if (p6.status==0){
                if (isPlayerOne){
                    isPlayerOne = false;
                    isPlayerTwo = true;
                    p6.status = 1;
                    count++;continue;
                }
                if (isPlayerTwo){
                    isPlayerTwo = false;
                    isPlayerOne = true;
                    p6.status = 2;
                    count++;continue;
                }
            }
        }
        //third row
        if(hitbox(mousex, mousey, p7.startposx, p7.startposy, p7.endposx, p7.endposy, p7.keybind)){
            if (p7.status==0){
                if (isPlayerOne){
                    isPlayerOne = false;
                    isPlayerTwo = true;
                    p7.status = 1;
                    count++;continue;
                }
                if (isPlayerTwo){
                    isPlayerTwo = false;
                    isPlayerOne = true;
                    p7.status = 2;
                    count++;continue;
                }
            }
        }
        if(hitbox(mousex, mousey, p8.startposx, p8.startposy, p8.endposx, p8.endposy, p8.keybind)){
            if (p8.status==0){
                if (isPlayerOne){
                    isPlayerOne = false;
                    isPlayerTwo = true;
                    p8.status = 1;
                    count++;continue;
                }
                if (isPlayerTwo){
                    isPlayerTwo = false;
                    isPlayerOne = true;
                    p8.status = 2;
                    count++;continue;
                }
            }
        }
        if(hitbox(mousex, mousey, p9.startposx, p9.startposy, p9.endposx, p9.endposy, p9.keybind)){
            if (p9.status==0){
                if (isPlayerOne){
                    isPlayerOne = false;
                    isPlayerTwo = true;
                    p9.status = 1;
                    count++;continue;
                }
                if (isPlayerTwo){
                    isPlayerTwo = false;
                    isPlayerOne = true;
                    p9.status = 2;
                    count++;continue;
                }
            }
        }
        // Circles and exes
        //first row
        cellfill(p1.status, p1.startposx, p1.startposy);
        cellfill(p2.status, p2.startposx, p2.startposy);
        cellfill(p3.status, p3.startposx, p3.startposy);
        //second row
        cellfill(p4.status, p4.startposx, p4.startposy);
        cellfill(p5.status, p5.startposx, p5.startposy);
        cellfill(p6.status, p6.startposx, p6.startposy);
        //third row
        cellfill(p7.status, p7.startposx, p7.startposy);
        cellfill(p8.status, p8.startposx, p8.startposy);
        cellfill(p9.status, p9.startposx, p9.startposy);
        //win check
        win(1);
        win(2);
        if (count == 9){
            clear();
        }
        EndDrawing();
    }
    CloseWindow();

    return 0;
}