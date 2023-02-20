#include <iostream>
#include <stdexcept>
#include <string>
#include <strings.h>
#include <string.h>
#include <cstdlib>
#include <cstdio>
#include <math.h>
#include <limits.h>

using namespace std;

char check_win_condition(char plansza[][3]){
        for(int i = 0; i < 3; i++){
                if(
                                plansza[i][0] == 'X' &&
                                plansza[i][1] == 'X' &&
                                plansza[i][2] == 'X'
                  ){
                        return 'X';
                } else if (
                                plansza[i][0] == 'O' &&
                                plansza[i][1] == 'O' &&
                                plansza[i][2] == 'O'
                          ) {
                        return 'O';
                }
                else if (
                                plansza[0][i] == 'X' &&
                                plansza[1][i] == 'X' &&
                                plansza[2][i] == 'X'
                        ){
                        return 'X';
                }
                else if(
                                plansza[0][i] == 'O' &&
                                plansza[1][i] == 'O' &&
                                plansza[2][i] == 'O'
                       ){
                        return 'O';
                }
        }

        if(
                        plansza[0][0] == 'X' &&
                        plansza[1][1] == 'X' &&
                        plansza[2][2] == 'X'
          ){
                return 'X';
        }
        else if(
                        plansza[0][0] == 'O' &&
                        plansza[1][1] == 'O' &&
                        plansza[2][2] == 'O'
               ){
                return 'O';
        }
        else if(
                        plansza[0][2] == 'X' &&
                        plansza[1][1] == 'X' &&
                        plansza[2][0] == 'X'
               ){
                return 'X';
        }
        else if(
                        plansza[0][2] == 'O' &&
                        plansza[1][1] == 'O' &&
                        plansza[2][0] == 'O'
               ){
                return 'O';
        }

        int empty_cells = 0;
        for(int i = 0; i < 3; i++){
                for(int j = 0; j < 3; j++){
                        if(plansza[i][j] == '.'){
                                empty_cells++;
                        }
                }
        }
        if(empty_cells == 0) return 'D';
        else return 'N';
}

int gaem(){
        char plansza[3][3];
        for(int i = 0; i < 3; i++){
                for(int j = 0; j < 3; j++){
                        plansza[i][j] = '.';
                }
        }
        
        signed int game_run = 0;
        char cur_player = 'O';
        while(game_run<1){
                cout<<"Plansza: "<<endl;
                for(int i = 0; i < 3; i++){
                        cout<<plansza[i][0]<<" | "<<plansza[i][1]<<" | "<<plansza[i][2]<<endl;
                }
                string cur_player_mnemonic = (cur_player == 'O') ? "Kółko!" : "Krzyżyk!";

                cout<<cur_player_mnemonic<<" Wykonaj ruch! Podaj pozycję, którą chcesz zająć: (format: numer kolumny,numer wiersza)"<<endl;

                string pos;
                cin>>pos;
                
                int pos_x, pos_y;
                try{
                        if(pos == "wyjdź") throw 2;

                        pos_x = stoi(pos.substr(0,1));
                        pos_y = stoi(pos.substr(2,1));

                        if(
                                        (pos_x > 3 || pos_x < 1) ||
                                        (pos_y > 3 || pos_y < 1)
                          ){
                                throw 1;
                        }
                }
                catch(invalid_argument err){
                        cout<<"Nieprawidłowy format odpowiedzi :-("<<endl;
                        continue;
                }
                catch(int err){
                        if(err == 1){
                        cout<<"Nieprawidłowy format odpowiedzi :-("<<endl;
                        continue;
                        }
                        else if(err == 2){
                                cout<<"Gra przerwana"<<endl;
                                game_run++;
                                continue;
                        }
                }

                if(plansza[pos_y-1][pos_x-1] != 'O' && plansza[pos_y-1][pos_x-1] != 'X'){
                        plansza[pos_y-1][pos_x-1] = cur_player;
                        cur_player = (cur_player == 'O') ? 'X' : 'O';
                } else {
                        cout<<"To miejsce jest zajęte :-("<<endl;
                        continue;
                }

                char game_result = check_win_condition(plansza);

                if(game_result != 'N'){
                        game_run++;
                        switch(game_result){
                                case 'O':{
                                                return 1;
                                        }
                                break;
        
                                case 'X':{
                                                 return 2;
                                         }
                                break;
                        
                                case 'D':{
                                                return 3;
                                        }
                                break;
                        }
                }
        }

        return 0;
}

int main(){
        cout<<"Kółko i krzyżyk - Michał Mikuła 2023"<<endl;
        int run = 0;
        while(run<1){
                cout<<"Co chcesz zrobić? \n"<<endl;
                cout<<"1. Zagraj"<<endl;
                cout<<"2. Wyjdź"<<endl;

                string menu_in;
                cin>>menu_in;
                int menu_opt;

                try{
                        menu_opt = stoi(menu_in);
                }
                catch(invalid_argument err){
                        cout<<"Nieznana komenda :-("<<endl;
                        continue;
                }

                switch(menu_opt){
                        case 1: {
                                        int result = gaem();
                                        switch(result){
                                                case 1:{
                                                               cout<<"Wygrało Kółko!"<<endl;
                                                       }
                                                break;

                                                case 2:{
                                                          cout<<"Wygrał Krzyżyk!"<<endl;
                                                        }
                                                break;

                                                case 3:{
                                                          cout<<"Remis! Nikt nie wygrał!"<<endl;
                                                       }
                                                break;
                                        }
                                }
                        break;
                        case 2: {
                                cout<<"Bye-bye"<<endl;
                                run++;
                                }
                        break;
                        default: {
                                cout<<"Nieznana opcja :-("<<endl;
                        }
                        break;
                }
        }
        return 0;
}
