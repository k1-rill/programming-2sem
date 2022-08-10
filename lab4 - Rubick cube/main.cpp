#include <iostream>
#include <fstream>
#include "cube.h"
#include <limits>
#define GL_GLEXT_PROTOTYPES
#define GL_SILENCE_DEPRECATION

#include <GLUT/glut.h>
#include <GLFW/glfw3.h>


using namespace std;



cube cub;


int main(int argc, char* argv[]) {


    cube cub;
    cub.read_cube();
    //cub.F();

    //cub.scramble();
    int n;
    cout << "if u want to show the cube after some step, print number, or print 0 or 7 if u want to solve the cube, or print 8 if u want to rotate yourself";
    cin >> n;
    if (n!=8) {
        cub.console_output();
        cub.solve(n);
        cub.print_cube();
        cub.console_output();
    }
    else{
        cout << "print E to exit program; commands: U, R, D, F, L, B and with ' print S to show cube";
        string symbol;

        while (true){
            cin >> symbol;
            if (symbol == "E"){
                break;
            }
            else if (symbol == "S"){
                cub.console_output();
            }
            else if (symbol =="U"){
                cub.U();
            }
            else if (symbol =="U'"){
                cub.Uu();
            }
            else if (symbol =="D"){
                cub.D();
            }
            else if (symbol =="D'"){
                cub.Dd();
            }
            else if (symbol =="F"){
                cub.F();
            }
            else if (symbol =="F'"){
                cub.Ff();
            }
            else if (symbol =="R"){
                cub.R();
            }
            else if (symbol =="R'"){
                cub.Rr();
            }
            else if (symbol =="L"){
                cub.L();
            }
            else if (symbol =="L'"){
                cub.Ll();
            }
            else if (symbol =="B"){
                cub.B();
            }
            else if (symbol =="B'"){
                cub.B();
            }
            else{
                cout << "no such command";
            }
        }
    }

}

