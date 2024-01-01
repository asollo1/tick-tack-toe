#include "include/raylib/raylib.h"
#include <iostream>
#include <string>

//Variables
//Mouse position
float mousex, mousey;
//Cells
struct p {
    int startposx, startposy, endposx, endposy, status;
};
struct p pola[3][3];
//Score
int scoreP1 = 0, scoreP2 = 0, count = 0;
//Players
bool isPlayerOne = true, isPlayerTwo = false, isWinP1 = false, isWinP2 = false;
//Game
bool isTitle = true, isGame = false, isWin = false;
int winner = 0;
Sound winsound;
//Functions
void clear(){
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            pola[i][j].status = 0;
        }
    }
    PlaySound(winsound);
    isWin = true;
    isGame = false;
    if (isWinP1){
        scoreP1 = scoreP1 +1;
        winner = 1;
    }
    else{
        scoreP2 = scoreP2 +1;
        winner = 2;
    }
    isWinP1 = false;
    isWinP2 = false;
    count = 0;
}
void win(int player){
    if(pola[0][0].status==player){
        if((pola[0][1].status == player) && (pola[0][2].status == player) || (pola[1][1].status == player) && (pola[2][2].status == player) or (pola[1][0].status == player) && (pola[2][0].status == player)){
            if(player==1){
                isWinP1 = true;
            }else{
                isWinP2 = true;
            }
            clear();
        }
    }
    if(pola[0][1].status==player && pola[1][1].status==player && pola[2][1].status==player){
        if(player==1){
            isWinP1 = true;
        }else{
            isWinP2 = true;
        }
        clear();
    }
    if (pola[0][2].status==player){
        if(pola[1][2].status == player && pola[2][2].status == player or pola[1][1].status == player && pola[2][0].status == player){
            if(player==1){
                isWinP1 = true;
            }else{
                isWinP2 = true;
            } 
            clear();
        }
    }
    if (pola[1][0].status==player && pola[1][1].status == player && pola[1][2].status == player){
        if(player==1){
            isWinP1 = true;
        }else{
            isWinP2 = true;
        }
        clear();
    }
    if (pola[2][0].status==player && pola[2][1].status == player && pola[2][2].status == player){
        if(player==1){
            isWinP1 = true;
        }
        else{
            isWinP2 = true;
        }
        clear();
    }
}
int hitbox(int mousex, int mousey, int fromx, int fromy, int tox, int toy){
    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && mousex >= fromx  && mousey >= fromy && mousex <= tox && mousey <= toy){
        return true;
    }
    return false;
}
//game elements
void cellfill(int status, int x, int y, Texture2D circle, Texture2D xs){
    if (status == 1){
        DrawTexture(circle, x, y, WHITE);
    }
    if (status == 2){
        DrawTexture(xs, x, y, WHITE);
    }
}


//main function
int main(){
    for (int i=0; i<3; i++){
        for (int j=0; j<3; j++){
            pola[i][j] = {20+(j*110),20+(i*110),120+(j*110),120+(i*110), 0};
        }
    }   
    //Initialization
    InitWindow(800,360,"Tick tack toe");
    InitAudioDevice();
    SetTargetFPS(60);
    mousex = { GetMousePosition().x};
    mousey = { GetMousePosition().y};
    //loading textures
    Texture2D circle = LoadTexture("images/circle.png"), xs = LoadTexture("images/x.png"), titlescreen = LoadTexture("images/title.png"), button = LoadTexture("images/button.png"), button_again = LoadTexture("images/button_again.png");
    //loading sounds
    Sound circlesound = LoadSound("sounds/circle.wav");
    Sound xsound = LoadSound("sounds/x.wav");
    Sound winsound = LoadSound("sounds/win.wav");
    while(!WindowShouldClose()){
        //mouse position
        mousex = { GetMousePosition().x};
        mousey = { GetMousePosition().y};
        BeginDrawing();
        ClearBackground(DARKBLUE);
        if (isTitle){
            DrawTexture(titlescreen, 0, 0, WHITE);
            DrawTexture(button, 350, 130, WHITE);
            if (hitbox(mousex, mousey, 350, 130, 450, 180)){
                isTitle = false;
                isGame = true;
                PlaySound(circlesound);
            }
        }
        if(isWin){
            if (winner == 2){
                DrawText("Player 1 wins!", 250, 100, 50, WHITE);
            }
            if (winner == 1){
                DrawText("Player 2 wins!", 250, 100, 50, WHITE);
            }
            DrawTexture(button_again, 350, 230, WHITE);
            if (hitbox(mousex, mousey, 350, 230, 450, 280)){
                isWin = false;
                isGame = true;
                PlaySound(xsound);
            }
        }
        if (isGame){
            //graphics interface
            //vertical lines
            for(int i = 10; i <= 340; i+=110){
                DrawRectangle(i, 10, 10, 340, WHITE);
            }
            //horizontal lines
            for(int i = 10; i <= 340; i+=110){
                DrawRectangle(10, i, 340, 10, WHITE);
            }
            //score display
            if(isPlayerOne){
                DrawText("Turn of Player A", 450, 50, 30, WHITE);
            } else {
                DrawText("Turn of Player B", 450, 50, 30, WHITE);
            }
             
            DrawText("Player A: ", 450, 150, 50, WHITE);
            DrawText("Player B: ", 450, 200, 50, WHITE);
            DrawText(std::to_string(scoreP1).c_str(), 700, 150, 50, WHITE);
            DrawText(std::to_string(scoreP2).c_str(), 700, 200, 50, WHITE);
            //click register
            for(int i = 0; i < 3; i++){
                for(int j = 0; j < 3; j++){
                    if(hitbox(mousex, mousey, pola[i][j].startposx, pola[i][j].startposy, pola[i][j].endposx, pola[i][j].endposy)){
                        if (pola[i][j].status==0){
                            if (isPlayerOne){
                                isPlayerOne = false;
                                isPlayerTwo = true;
                                pola[i][j].status = 2;
                                PlaySound(xsound); 
                                count++;
                                continue;
                            }
                            if (isPlayerTwo){
                                isPlayerTwo = false;
                                isPlayerOne = true;
                                pola[i][j].status = 1;
                                PlaySound(circlesound);
                                count++;
                                continue;
                            }
                        }
                    }
                }
            }
            // Circles and exes
            for(int i = 0; i < 3; i++){
                for(int j = 0; j < 3; j++){
                    cellfill(pola[i][j].status, pola[i][j].startposx, pola[i][j].startposy, circle, xs);
                }
            }
            //win check
            win(1);
            win(2);
            if (count == 9){
                clear();
            }
        }
        EndDrawing();
    }
    CloseWindow();
    return 0;
}