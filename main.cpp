#include <iostream>
#include <stdexcept>
#include <string>
#include <strings.h>
#include <string.h>
#include <cstdlib>
#include <stdlib.h>
#include <cstdio>
#include <math.h>
#include <limits.h>
#include "tic-tac-toe_info.h"

#ifdef USE_GAMELIBS
# include "GameLibs/GameLibs.h"
#endif

using namespace std;

int main(){
        system("clear");
        cout<<"Tic-Tac-Toe - Michał Mikuła 2023"<<endl;
        int run = 0;
        while(run<1){
                cout<<"What shall we do? \n"<<endl;
                cout<<"1. Play"<<endl;
                cout<<"2. Exit"<<endl;

                string menu_in;
                cin>>menu_in;
                int menu_opt;

                try{
                        menu_opt = stoi(menu_in);
                }
                catch(invalid_argument err){
                        system("clear");
                        cout<<"Unknown option :-("<<endl;
                        continue;
                }

                switch(menu_opt){
                        case 1: {
                                        system("clear");
                                        #ifdef USE_GAMELIBS
                                                int result = gaem();
                                        #else
                                                int result = 0;
                                        #endif                                 
                                        system("clear");
                                        switch(result){
                                                case 1:{
                                                        cout<<"Winner: Circle!"<<endl;
                                                       }
                                                break;

                                                case 2:{
                                                          cout<<"Winner: Cross!"<<endl;
                                                        }
                                                break;

                                                case 3:{
                                                          cout<<"Draw! Winner: None!"<<endl;
                                                       }
                                                break;

                                                case 0:{
                                                           cout<<"No gamelibs. Sorry."<<endl;
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
                                system("clear");
                                cout<<"Unknown option :-("<<endl;
                        }
                        break;
                }
        }
        return 0;
}
