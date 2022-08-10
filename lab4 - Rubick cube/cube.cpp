#include "cube.h"
#include <fstream>
#include <iostream>
#include <string>
/*
 *     3 1 3
       1 6 2
       5 1 5
1 2 4  1 4 2  6 6 4  6 5 2
6 5 3  1 2 6  5 3 3  6 4 4
3 5 4  6 4 1  5 3 1  3 2 6
       5 3 2
       4 1 2
       2 5 4
 */

cube::cube() {
    face.assign(3, vector<int>(3));
    back.assign(3, vector<int>(3));
    right.assign(3, vector<int>(3));
    left.assign(3, vector<int>(3));
    up.assign(3, vector<int>(3));
    down.assign(3, vector<int>(3));
    for (int i = 0; i<3; ++i){
        for (int j = 0; j<3; ++j) {
            face[i][j] = 2;
            back[i][j] = 4;
            right[i][j] = 3;
            left[i][j] = 5;
            up[i][j] = 6;
            down[i][j] = 1;
        }
    }
    commands = "";
}

void cube::read_cube(){
    ifstream in("input.txt");
    char symbol;
    for (int i = 0; i<6; ++i){
        for (int j = 0; j<3; ++j){
            for (int k = 0; k<3; ++k){
                in >> symbol;
                if (i == 0){
                    up[j][k] = (symbol - '0');
                }
                if (i == 5){
                    down[j][k] = (symbol - '0');
                }
                if (i == 1){
                    if (j == 0){
                        left[j][k] = symbol - '0';
                    }
                    if (j == 1){
                        face[0][k] = symbol - '0';
                    }
                    if (j == 2){
                        right[0][k] = symbol - '0';
                    }
                }
                if (i == 2){
                    if (j == 0){
                        back[j][k] = symbol - '0';
                    }
                    if (j == 1){
                        left[j][k] = symbol - '0';
                    }
                    if (j == 2){
                        face[1][k] = symbol - '0';
                    }
                }
                if (i == 3){
                    if (j == 0){
                        right[1][k] = symbol - '0';
                    }
                    if (j == 1){
                        back[j][k] = symbol - '0';
                    }
                    if (j == 2){
                        left[j][k] = symbol - '0';
                    }
                }
                if (i == 4){
                    if (j == 0){
                        face[2][k] = symbol - '0';
                    }
                    if (j == 1){
                        right[2][k] = symbol - '0';
                    }
                    if (j == 2){
                        back[j][k] = symbol - '0';
                    }
                }
            }
        }
    }
}

void cube::console_output() {
    cout << "       " << up[0][0] << ' ' <<up[0][1] <<' '<<up[0][2] << '\n';
    cout << "       " << up[1][0] << ' ' <<up[1][1] <<' '<<up[1][2] << '\n';
    cout << "       " << up[2][0] << ' ' <<up[2][1] <<' '<<up[2][2] << '\n';
    cout << left[0][0] << ' ' <<left[0][1]<<' '<<left[0][2]<<"  " <<face[0][0] << ' '<<face[0][1] << ' ' << face[0][2] << "  " << right[0][0] << ' ' << right[0][1] << ' '<< right[0][2] << "  " << back[0][0] << ' ' << back[0][1] << ' ' <<back[0][2] << '\n';
    cout << left[1][0] << ' ' <<left[1][1]<<' '<<left[1][2]<<"  " <<face[1][0] << ' '<<face[1][1] << ' ' << face[1][2] << "  " << right[1][0] << ' ' << right[1][1] << ' '<< right[1][2] << "  " << back[1][0] << ' ' << back[1][1] << ' ' <<back[1][2] << '\n';
    cout << left[2][0] << ' ' <<left[2][1]<<' '<<left[2][2]<<"  " <<face[2][0] << ' '<<face[2][1] << ' ' << face[2][2] << "  " << right[2][0] << ' ' << right[2][1] << ' '<< right[2][2] << "  " << back[2][0] << ' ' << back[2][1] << ' ' <<back[2][2] << '\n';
    cout << "       " << down[0][0] << ' ' <<down[0][1] <<' '<<down[0][2] << '\n';
    cout << "       " << down[1][0] << ' ' <<down[1][1] <<' '<<down[1][2] << '\n';
    cout << "       " << down[2][0] << ' ' <<down[2][1] <<' '<<down[2][2] << '\n';
    cout << "solution: " << commands << '\n';
}

void cube::print_cube() {
    ofstream out("output.txt");
    out << "       " << up[0][0] << ' ' <<up[0][1] <<' '<<up[0][2] << '\n';
    out << "       " << up[1][0] << ' ' <<up[1][1] <<' '<<up[1][2] << '\n';
    out << "       " << up[2][0] << ' ' <<up[2][1] <<' '<<up[2][2] << '\n';
    out << left[0][0] << ' ' <<left[0][1]<<' '<<left[0][2]<<"  " <<face[0][0] << ' '<<face[0][1] << ' ' << face[0][2] << "  " << right[0][0] << ' ' << right[0][1] << ' '<< right[0][2] << "  " << back[0][0] << ' ' << back[0][1] << ' ' <<back[0][2] << '\n';
    out << left[1][0] << ' ' <<left[1][1]<<' '<<left[1][2]<<"  " <<face[1][0] << ' '<<face[1][1] << ' ' << face[1][2] << "  " << right[1][0] << ' ' << right[1][1] << ' '<< right[1][2] << "  " << back[1][0] << ' ' << back[1][1] << ' ' <<back[1][2] << '\n';
    out << left[2][0] << ' ' <<left[2][1]<<' '<<left[2][2]<<"  " <<face[2][0] << ' '<<face[2][1] << ' ' << face[2][2] << "  " << right[2][0] << ' ' << right[2][1] << ' '<< right[2][2] << "  " << back[2][0] << ' ' << back[2][1] << ' ' <<back[2][2] << '\n';
    out << "       " << down[0][0] << ' ' <<down[0][1] <<' '<<down[0][2] << '\n';
    out << "       " << down[1][0] << ' ' <<down[1][1] <<' '<<down[1][2] << '\n';
    out << "       " << down[2][0] << ' ' <<down[2][1] <<' '<<down[2][2] << '\n';
    out << "solution: " << commands;
}

bool cube::check_correct(){
    vector <int> colors(6);
    for (int i =0; i < 3; ++i){
        for (int j = 0; j<3; ++j){
            colors[face[i][j]]++;
            colors[back[i][j]]++;
            colors[up[i][j]]++;
            colors[left[i][j]]++;
            colors[right[i][j]]++;
            colors[down[i][j]]++;
        }
    }
    for (int i =0; i<6; ++i){
        if (colors[i] != 9){
            return false;
        }
    }

    if (up[1][1]==left[1][1] || up[1][1]==face[1][1] || up[1][1]==right[1][1] || up[1][1]==back[1][1] || up[1][1]==down[1][1] || left[1][1] == face[1][1] || left[1][1] == right[1][1] || left[1][1] == back[1][1] || left[1][1] == down[1][1] || face[1][1] == right[1][1] || face[1][1] == down[1][1] || face[1][1] == back[1][1] || right[1][1] == back[1][1] || right[1][1] == down[1][1] || down[1][1] == back[1][1] ){
        return false;
    }

    return true;
}
bool cube::check_is_ready() {
    bool flag = true;
    for (int i = 0 ; i<6; ++i){
        for (int j = 0; j<3; ++j){
            for (int k = 0; k<3; ++k){
                if (down[j][k]!=1)
                    flag = false;
                if (face[j][k]!=2)
                    flag = false;
                if (right[j][k]!=3)
                    flag = false;
                if (back[j][k]!=4)
                    flag = false;
                if (left[j][k]!=5)
                    flag = false;
                if (up[j][k]!=6)
                    flag = false;

                if (flag == false)
                    return false;
            }
        }
    }

    return true;
}

void cube::turn_side(vector<vector<int>> &tmp) {
    int buf;
    for (int i = 0; i<3/2; ++i){
        for (int j = 0; j<3-1-i; ++j){
            buf = tmp[i][j];
            tmp[i][j] = tmp[3-j-1][i];
            tmp[3-j-1][i] = tmp[3-i-1][3-j-1];
            tmp[3-i-1][3-j-1] = tmp[j][3-i-1];
            tmp[j][3-i-1] = buf;
        }
    }
}

void cube::F(){
    vector <int> tmp({left[0][2], left[1][2], left[2][2]});
    left[0][2] = down[0][0];
    left[1][2] = down[0][1];
    left[2][2] = down[0][2];

    down[0][0] = right[2][0];
    down[0][1] = right[1][0];
    down[0][2] = right[0][0];

    right[2][0] = up[2][2];
    right[1][0] = up[2][1];
    right[0][0] = up[2][0];

    turn_side(face);

    up[2][2] = tmp[0];
    up[2][1] = tmp[1];
    up[2][0] = tmp[2];
}

void cube::Ff(){
    F();
    F();
    F();
}

void cube::R(){
    vector <int> tmp({face[0][2], face[1][2], face[2][2]});
    face[0][2] = down[0][2];
    face[1][2] = down[1][2];
    face[2][2] = down[2][2];

    down[0][2] = back[2][0];
    down[1][2] = back[1][0];
    down[2][2] = back[0][0];

    back[0][0] = up[2][2];
    back[1][0] = up[1][2];
    back[2][0] = up[0][2];

    turn_side(right);

    up[0][2] = tmp[0];
    up[1][2] = tmp[1];
    up[2][2] = tmp[2];
}

void cube::Rr(){
    R();
    R();
    R();
}

void cube::U(){
    vector <int> tmp({face[0][0], face[0][1], face[0][2]});
    face[0][0] = right[0][0];
    face[0][1] = right[0][1];
    face[0][2] = right[0][2];

    right[0][0] = back[0][0];
    right[0][1] = back[0][1];
    right[0][2] = back[0][2];

    back[0][0] = left[0][0];
    back[0][1] = left[0][1];
    back[0][2] = left[0][2];

    turn_side(up);

    left[0][0] = tmp[0];
    left[0][1] = tmp[1];
    left[0][2] = tmp[2];
}

void cube::Uu(){
    U(); U(); U();
}

void cube::B(){
    vector <int> tmp ({up[0][0], up[0][1], up[0][2]});
    up[0][0] = right[0][2];
    up[0][1] = right[1][2];
    up[0][2] = right[2][2];

    right[0][2] = down[2][2];
    right[1][2] = down[2][1];
    right[2][2] = down[2][0];

    down[2][0] = left[0][0];
    down[2][1] = left[1][0];
    down[2][2] = left[2][0];
    turn_side(back);

    left[0][0] = tmp[2];
    left[1][0] = tmp[1];
    left[2][0] = tmp[0];
}

void cube::Bb(){
    B(); B(); B();
}

void cube::L(){
    vector <int> tmp({face[0][0], face[1][0], face[2][0]});
    face[0][0] = up[0][0];
    face[1][0] = up[1][0];
    face[2][0] = up[2][0];

    up[0][0] = back[2][2];
    up[1][0] = back[1][2];
    up[2][0] = back[0][2];

    back[0][2] = down[2][0];
    back[1][2] = down[1][0];
    back[2][2] = down[0][0];

    turn_side(left);

    down[2][0] = tmp[2];
    down[1][0] = tmp[1];
    down[0][0] = tmp[0];
}

void cube::Ll(){
    L(); L(); L();
}

void cube::D(){
    vector<int> tmp({face[2][0], face[2][1], face[2][2]});
    face[2][0] = left[2][0];
    face[2][1] = left[2][1];
    face[2][2] = left[2][2];

    left[2][0] = back[2][0];
    left[2][1] = back[2][1];
    left[2][2] = back[2][2];

    back[2][0] = right[2][0];
    back[2][1] = right[2][1];
    back[2][2] = right[2][2];

    turn_side(down);

    right[2][0] = tmp[0];
    right[2][1] = tmp[1];
    right[2][2] = tmp[2];
}

void cube::Dd(){
    D(); D(); D();
}

void cube::first_step() {
    int flag = 0;
    while (true) {
        if (face[0][1] == 2 && up[2][1] == 1) {
            F();
            F();
            flag = 0;
            commands += "F'' ";
        } else if (right[0][1] == 3 &&  up[1][2] == 1) {
            R();
            R();
            flag = 0;
            commands += "R'' ";
        } else if (left[0][1] == 5 && up[1][0] == 1) {
            L();
            L();
            flag = 0;
            commands += "L'' ";
        } else if (back[0][1] == 4 &&  up[0][1] == 1) {
            B();
            B();
            flag = 0;
            commands += "B'' ";
        } else if (face[0][1] == 1 && up[2][1] == 2 ) {
            Uu();//6' 3' 23
            Rr();
            F();
            R();
            flag = 0;
            commands += "U' R' F R ";
        } else if ( up[1][2] == 3  && right[0][1] == 1) {
            //6' 4' 34
            Uu();
            Bb();
            R();
            B();
            flag = 0;
            commands += "U' B' R B ";
        } else if ( left[0][1] == 1 && up[1][0] == 5 ) {
            //6' 2' 52
            Uu();
            Ff();
            L();
            F();
            flag = 0 ;
            commands += "U' F' L F ";
        } else if (back[0][1] == 1 && up[0][1] == 4 ) {
            //6'5'45
            Uu();
            Ll();
            B();
            L();
            flag = 0;
            commands += "U' L' B L ";
        } else if (face[1][2] == 1) {
            //2'6'2
            Ff();
            Uu();
            F();
            flag = 0;
            commands += "F' U' F ";
        } else if ( right[1][2] == 1 ) {
            //3'6'3
            Rr();
            Uu();
            R();
            flag = 0;
            commands += "R' U' R ";
        } else if (left[1][2] == 1) {
            //5'6'5
            Ll();
            Uu();
            L();
            flag = 0;
            commands += "L' U' L ";
        } else if (back[1][2] == 1) {
            //4'6'4
            Bb();
            Uu();
            B();
            flag = 0;
            commands += "B' U' B ";
        } else if (face[1][0] == 1 ) {
            //26'2'
            F();
            Uu();
            Ff();
            flag = 0;
            commands += "F U' F' ";
        } else if (right[1][0] == 1 ) {
            //36'3'
            R();
            Uu();
            Rr();
            flag = 0;
            commands += "R U' R' ";
        } else if (left[1][0] == 1 ) {
            //56'5'
            L();
            Uu();
            Ll();
            flag = 0;
            commands += "L U' L' ";
        } else if (back[1][0] == 1 ) {
            //46'4'
            B();
            Uu();
            Bb();
            flag = 0;
            commands += "B U' B' ";
        } else if ( face[2][1] == 1 ) {
            //2'' 6'2''
            F();
            F();
            Uu();
            F();
            F();
            flag = 0;
            commands += "F'' U' F'' ";
        } else if (right[2][1] == 1 ) {
            //3'' 6'3''
            R();
            R();
            Uu();
            R();
            R();
            flag = 0;
            commands += "R'' U' R'' ";
        } else if (left[2][1] == 1) {
            //5''6'5''
            L();
            L();
            Uu();
            L();
            L();
            flag = 0;
            commands += "L'' U' L'' ";
        } else if (back[2][1] == 1 ) {
            //4''6'4''
            B();
            B();
            Uu();
            B();
            B();
            flag = 0;
            commands += "B'' U' B'' ";
        } else if ( face[2][1] != 2 && down[0][1] == 1) {
            //2''6'2''
            F();
            F();
            Uu();
            F();
            F();
            flag = 0;
            commands += "F'' U' F'' ";
        } else if (right[2][1] != 3 && down[1][2] == 1) {
            //3''6'3''
            R();
            R();
            Uu();
            R();
            R();
            flag = 0;
            commands += "R'' U' R'' ";
        } else if (left[2][1] != 5 &&  down[1][0] == 1) {
            //5''6'5''
            L();
            L();
            Uu();
            L();
            L();
            flag = 0;
            commands += "L'' U' L'' ";
        } else if (back[2][1] != 4 && down[2][1] == 1) {
            //4''6'4''
            B();
            B();
            Uu();
            B();
            B();
            flag = 0;
            commands += "B'' U' B'' ";
        }
        else{
            flag+=1;
            U();
            commands += "U ";
        }
        if (flag == 4)
            break;
    }
}

void cube::second_step() {
    int flag = 0;
    while (true){
        if (face[2][1] == 2 && face[0][2] == 1 && up[2][2]==2 && right[0][0] == 3 && right[2][1]==3){
            //2'6'2
            Ff();
            Uu();
            F();
            flag = 0;
            commands += "F' U' F ";
        }
        else if (face[2][1] == 2 && face[0][0] == 2 &&  left[2][1]==5 && left[0][2]==1 &&  up[2][0]==5){
            //5'6'5
            Ll();
            Uu();
            L();
            flag = 0;
            commands+="L' U' L ";
        }
        else if (back[0][0] == 4 && back[2][1]==4 && up[0][2]==3 && right[2][1] == 3 && right[0][2] == 1){
            //3'6'3
            Rr();
            Uu();
            R();
            flag = 0;
            commands+= "R' U' R ";
        }
        else if ( back[2][1] == 4 && back[0][2]==1 && up[0][0] == 4 && left[2][1] ==5 && left[0][0]==5){
            //4'6'4
            Bb();
            Uu();
            B();
            flag = 0;
            commands += "B' U' B ";
        }
        else if (face[2][1]==2 && face[0][2] == 2 &&  up[2][2] == 3 &&  right[0][0] == 1 && right[2][1] == 3){
            //363'
            R();
            U();
            Rr();
            flag = 0;
            commands += "R U R' ";
        }
        else if (face[2][1]==2 && face[0][0] == 1 && left[2][1] == 5 && left[0][2] == 5 && up[2][0] == 2){
            //262'
            F();
            U();
            Ff();
            flag = 0;
            commands+= "F U F' ";
        }
        else if (back[0][0] == 1 && back[2][1]==4 && up[0][2]==4 && right[2][1] == 3 && right[0][2] == 3){
            //464'
            B();
            U();
            Bb();
            flag = 0;
            commands+= "B U B' ";
        }
        else if (back[2][1] == 4 && back[0][2]==4 && up[0][0] == 5 && left[2][1] ==5 && left[0][0]==1){
            //565'
            L();
            U();
            Ll();
            flag = 0;
            commands += "L U L' ";
        }
        else if (face[2][1]==2 && face[0][2] == 3  && up[2][2] == 1 && right[0][0] == 2 && right[2][1] == 3){
            //36'3' 6'' 363'
            R();
            Uu();
            Rr();
            U(); U();
            R();
            U();
            Rr();
            flag = 0;
            commands += "R U' R' U'' R U R' ";
        }
        else if ( face[2][1]==2 && face[0][0] == 5 && left[2][1] == 5 && left[0][2] == 2 &&  up[2][0] == 1){
            //26'2'6''262'
            F();
            Uu();
            Ff();
            U(); U();
            F();
            U();
            Ff();
            flag = 0;
            commands+= "F U' F' U'' F U F' ";
        }
        else if ( back[0][0] == 3 && back[2][1]==4 && up[0][2]==1 &&  right[2][1] == 3 && right[0][2] == 4){
            //46'4'6''464'
            B();
            Uu();
            Bb();
            U(); U();
            B();
            U();
            Bb();
            flag = 0;
            commands+= "B U' B' U'' B U B' ";
        }
        else if (back[2][1] == 4 && back[0][2]==5 && up[0][0] == 1 && left[2][1] ==5 && left[0][0]==4){
            //56'5'6''565'
            L();
            Uu();
            Ll();
            U(); U();
            L();
            U();
            Ll();
            flag = 0;
            commands += "L U' L' U'' L U L' ";
        }
        else if ( face[2][1] == 2 && face[2][2] == 1 &&  right[2][1] == 3){
            //2'6'2
            Ff();
            Uu();
            F();
            flag = 0;
            commands += "F' U' F ";
        }
        else if ( face[2][1] == 2  && left[2][1] == 5 && left[2][2] == 1){
            //5'6'5
            Ll();
            Uu();
            L();
            flag = 0;
            commands+="L' U' L ";
        }
        else if ( back[2][1] == 4 && right[2][1] == 3 && right[2][2] == 1){
            //3'6'3
            Rr();
            Uu();
            R();
            flag = 0;
            commands+="R' U' R ";
        }
        else if (back[2][1] == 4 && back[2][2] == 1 && left[2][1] == 5){
            //4'6'4
            Bb();
            Uu();
            B();
            flag = 0;
            commands+="B' U' B ";
        }
        else if (face[2][1] == 2 && right[2][0] == 1 && right[2][1] == 3 ){
            //2'6'2
            Ff();
            Uu();
            F();
            flag = 0;
            commands += "F' U' F ";
        }
        else if ( face[2][1] == 2  &&  left[2][1] == 5 && face[2][0] == 1 ){
            //5'6'5
            Ll();
            Uu();
            L();
            flag = 0;
            commands+="L' U' L ";
        }
        else if (back[2][1] == 4 &&  right[2][1] == 3 && back[2][0] == 1){
            //3'6'3
            Rr();
            Uu();
            R();
            flag = 0;
            commands+="R' U' R ";
        }
        else if ( back[2][1] == 4 && left[2][0] == 1 &&  left[2][1] == 5){
            //4'6'4
            Bb();
            Uu();
            B();
            flag = 0;
            commands+="B' U' B ";
        }
        else if ( face[2][1] == 2 && (left[2][2]!=5 || face[2][0]!=2) && left[2][1] == 5 && down[0][0] == 1 && down[0][1] == 1 && down[1][0] == 1 && down[1][2] == 1 && down[2][1] == 1){
            //26'2'
            F();
            Uu();
            Ff();
            flag = 0;
            commands += "F U' F' ";
        }
        else if (face[2][1] == 2 && (face[2][2]!=2 || right[2][0]!=3)  &&  right[2][1] == 3 && down[0][2] == 1 && down[0][1] == 1 && down[1][0] == 1 && down[1][2] == 1 && down[2][1] == 1){
            //36'3'
            R();
            Uu();
            Rr();
            flag = 0;
            commands += "R U' R' ";
        }
        else if (back[2][1] == 4 && (back[2][0]!=4 || right[2][2]!=3) &&  right[2][1] == 3 && down[0][1] == 1 && down[1][0] == 1 && down[1][2] == 1 && down[2][1] == 1 && down[2][2] == 1){
            //46'4'
            B();
            Uu();
            Bb();
            flag = 0;
            commands += "B U' B' ";
        }
        else if( back[2][1] == 4 && (back[2][2] != 4 || left[2][0]!= 5) &&  right[2][1] == 5 && down[0][1] == 1 && down[1][0] == 1 && down[1][2] == 1 && down[2][1] == 1 && down[2][0] == 1){
            //56'5'
            L();
            Uu();
            Ll();
            flag = 0;
            commands += "L U' L' ";
        }
        else{
            flag ++;
            U();
            commands += "U ";
        }
        if (flag == 4)
            break;
    }
}

void cube::third_step() {
    int flag = 0;
    while (true){
        if (face[2][0] == 2 && face[2][1] == 2 && face[2][2] == 2 && face[0][1] == 2 && left[2][0] == 5 && left[2][1] == 5 && left[2][2] == 5 && up[2][1] == 5){
            //6' 5' 65626'2'
            Uu();
            Ll();
            U();
            L();
            U();
            F();
            Uu();
            Ff();
            flag = 0;
            commands += "U' L' U L U F U' F' ";
        }
        else if (face[2][0] == 2 && face[2][1] == 2 && face[2][2] == 2 && right[2][0] == 3 && right[2][1] == 3 && right[2][2] == 3 && right[0][1] == 3 && up[1][2] == 2){
            //6'2'62636'3'
            Uu();
            Ff();
            U();
            F();
            U();
            R();
            Uu();
            Rr();
            flag = 0;
            commands += "U' F' U F U R U' R' ";
        }
        else if (back[2][0] == 4 && back[2][1] == 4 && back[2][2] == 4 && back[0][1] == 4 && right[2][0] == 3 && right[2][1] == 3 && right[2][2] == 3 && up[0][1] == 3){
            //6'3'63646'4'
            Uu();
            Rr();
            U();
            R();
            U();
            B();
            Uu();
            Bb();
            flag = 0;
            commands += "U' R' U R U B U' B' ";
        }
        else if (back[2][0] == 4 && back[2][1] == 4 && back[2][2] == 4 && left[2][0] == 5 && left[2][1] == 5 && left[2][2] == 5 && left[0][1] == 5 && up[1][0] == 4){
            //6'4'64 656'5'
            Uu();
            Bb();
            U();
            B();
            U();
            L();
            Uu();
            Ll();
            flag = 0;
            commands += "U' B' U B U L U' L' ";
        }
        else if (face[2][0] == 2 && face[2][1] == 2 && face[2][2] == 2 && right[2][0] == 3 && right[2][1] == 3 && right[2][2] == 3 && face[0][1] == 2 && up[2][1] == 3){
            //636'3' 6'2'62
            U();
            R();
            Uu();
            Rr();
            Uu();
            Ff();
            U();
            F();
            flag = 0;
            commands += "U R U' R' U' F' U F ";
        }
        else if (face[2][0] == 2 && face[2][1] == 2 && face[2][2] == 2 && left[0][1] == 5 && left[2][0] == 5 && left[2][1] == 5 && left[2][2] == 5 && up[1][0] == 2){
            //626'2' 6'5'65
            U();
            F();
            Uu();
            Ff();
            Uu();
            Ll();
            U();
            L();
            flag = 0;
            commands += "U F U' F' U' L' U L ";
        }
        else if (back[2][0] == 4 && back[2][1] == 4 && back[2][2] == 4 && left[2][0] == 5 && left[2][1] == 5 && left[2][2] == 5 && back[0][1] == 4 && up[0][1] == 5){
            //656'5' 6'4'64
            U();
            L();
            Uu();
            Ll();
            Uu();
            Bb();
            U();
            B();
            flag = 0;
            commands += "U L U' L' U' B' U B ";
        }
        else if (back[2][0] == 4 && back[2][1] == 4 && back[2][2] == 4  && right[2][0] == 3 && right[2][1] == 3 && right[2][2] == 3 && right[0][1] == 3 && up[1][2] == 4){
            //646'4' 6'3'63
            U();
            B();
            Uu();
            Bb();
            Uu();
            Rr();
            U();
            R();
            flag = 0;
            commands += "U B U' B' U' R' U R ";
        }
        else {
            flag ++;
            U();
            commands += "U ";
        }
        if (flag == 4){
            if (face[2][0] == 2 && face[2][1] == 2 && face[2][2] == 2 && right[2][0] == 3 && right[2][1] == 3 && right[2][2] == 3 && (face[1][2] != 2 || right[1][0] != 3)){
                //636'3' 6'2'62
                U();
                R();
                Uu();
                Rr();
                Uu();
                Ff();
                U();
                F();
                flag = 0;
                commands += "U R U' R' U' F' U F ";
            }
            else if (face[2][0] == 2 && face[2][1] == 2 && face[2][2] == 2 && left[2][0] == 5 && left[2][1] == 5 && left[2][2] == 5 && (face[1][0] != 2 || left[1][2]!=5 )){
                //626'2' 6'5'65
                U();
                F();
                Uu();
                Ff();
                Uu();
                Ll();
                U();
                L();
                flag = 0;
                commands += "U F U' F' U' L' U L ";
            }
            else if (back[2][0] == 4 && back[2][1] == 4 && back[2][2] == 4 && left[2][0] == 5 && left[2][1] == 5 && left[2][2] == 5 && (back[1][2] != 4 || left[1][0] != 5)){
                //656'5' 6'4'64
                U();
                L();
                Uu();
                Ll();
                Uu();
                Bb();
                U();
                B();
                flag = 0;
                commands += "U L U' L' U' B' U B ";
            }
            else if (back[2][0] == 4 && back[2][1] == 4 && back[2][2] == 4  && right[2][0] == 3 && right[2][1] == 3 && right[2][2] == 3 && (right[1][2] != 3 || back[1][0] != 4)){
                //646'4' 6'3'63
                U();
                B();
                Uu();
                Bb();
                Uu();
                Rr();
                U();
                R();
                flag = 0;
                commands += "U B U' B' U' R' U R ";
            }
            else {
                break;
            }
        }
    }
}

void cube::forth_step() {
    if (face[2][0] == 2 && face[2][1] == 2 && face[2][2] == 2 && face[1][0] == 2 && face[1][2] == 2 && face[0][1] == 6 && right[2][0] == 3 && right[2][1] == 3 && right[2][2] == 3 && right[1][0] == 3 && right[1][2] == 3 && right[0][1] == 6 && up[1][0] == 6 && up[0][1] == 6) {
        //2636'3'2'
        F();
        U();
        R();
        Uu();
        Rr();
        Ff();
        commands += "F U R U' R' F' ";
    }
    else if (face[2][0] == 2 && face[2][1] == 2 && face[2][2] == 2 && face[1][0] == 2 && face[1][2] == 2 && face[0][1] == 6 && left[2][0] == 5 && left[2][1] == 5 && left[2][2] == 5 && left[1][0] == 5 && left[1][2] == 5 && left[0][1] == 6 && up[0][1] == 6 && up[1][2] == 6){
        //5626'2'5'
        L();
        U();
        F();
        Uu();
        Ff();
        Ll();
        commands += "L U F U' F' L' ";
    }
    else if (back[2][0] == 4 && back[2][1] == 4 && back[2][2] == 4 && back[1][0] == 4 && back[1][2] == 4 && back[0][1] == 6 && right[2][0] == 3 && right[2][1] == 3 && right[2][2] == 3 && right[1][0] == 3 && right[1][2] == 3 && right[0][1] == 6 && up[2][1] == 6 && up[1][0] == 6){
        //3646'4'3'
        R();
        U();
        B();
        Uu();
        Bb();
        Rr();
        commands += "R U B U' B' R' ";
    }
    else if (back[2][0] == 4 && back[2][1] == 4 && back[2][2] == 4 && back[1][0] == 4 && back[1][2] == 4 && back[0][1] == 6 && left[2][0] == 5 && left[2][1] == 5 && left[2][2] == 5 && left[1][0] == 5 && left[1][2] == 5 && left[0][1] == 6 && up[2][1] == 6 && up[1][2] == 6){
        //4656'5'4'
        B();
        U();
        L();
        Uu();
        Ll();
        Bb();
        commands += "B U L U' L' B' ";
    }
    else if (face[2][0] == 2 && face[2][1] == 2 && face[2][2] == 2 && face[1][0] == 2 && face[1][2] == 2 && face[0][1] == 6 && right[2][0] == 3 && right[2][1] == 3 && right[2][2] == 3 && right[1][0] == 3 && right[1][2] == 3 && up[1][0] == 6 && up[1][2] == 6 && back[0][1] == 6){
        //2363'6'2'
        F();
        R();
        U();
        Rr();
        Uu();
        Ff();
        commands += "F R U R' U' F' ";
    }
    else if (face[2][0] == 2 && face[2][1] == 2 && face[2][2] == 2 && face[1][0] == 2 && face[1][2] == 2  && right[2][0] == 3 && right[2][1] == 3 && right[2][2] == 3 && right[1][0] == 3 && right[1][2] == 3 && right[0][1] == 6 && up[0][1] == 6 && up[2][1] == 6 && left[0][1] == 6){
        //3464'6'3'
        R();
        B();
        U();
        Bb();
        Uu();
        Rr();
        commands += "R B U B' U' R' ";
    }
    else if (face[2][0] == 2 && face[2][1] == 2 && face[2][2] == 2 && face[1][0] == 2 && face[1][2] == 2 && face[0][1] == 6 && right[2][0] == 3 && right[2][1] == 3 && right[2][2] == 3 && right[1][0] == 3 && right[1][2] == 3 && right[0][1] == 6 && back[0][1] == 6 && left[0][1] == 6){
        //2636'3'2'3464'6'3'
        F();
        U();
        R();
        Uu();
        Rr();
        Ff();
        R();
        B();
        U();
        Bb();
        Uu();
        Rr();
        commands += "F U R U' R' F' R B U B' U' R' ";
    }
}

void cube::fifth_step() {
    if (face[2][0] == 2 && face[2][1] == 2 && face[2][2] == 2 && face[1][0] == 2 && face[1][2] == 2  && right[2][0] == 3 && right[2][1] == 3 && right[2][2] == 3 && right[1][0] == 3 && right[1][2] == 3 && right[0][1] == 2 && up[0][1] == 6 && up[1][0] == 6 && up[1][2] == 6 && up[2][1] == 6){
        //65'6'' 565'65
        U();
        Ll();
        U(); U();
        L();
        U();
        Ll();
        U();
        L();
        commands += "U L' U'' L U L' U L ";
    }
    else if (face[2][0] == 2 && face[2][1] == 2 && face[2][2] == 2 && face[1][0] == 2 && face[1][2] == 2  && left[2][0] == 5 && left[2][1] == 5 && left[2][2] == 5 && left[1][0] == 5 && left[1][2] == 5 && left[0][1] == 2 && up[0][1] == 6 && up[1][0] == 6 && up[1][2] == 6 && up[2][1] == 6){
        //64'6''464'64
        U();
        Bb();
        U(); U();
        B();
        U();
        Bb();
        U();
        B();
        commands += "U B' U'' B U B' U B ";
    }
    else if (face[2][0] == 2 && face[2][1] == 2 && face[2][2] == 2 && face[1][0] == 2 && face[1][2] == 2  && right[2][0] == 3 && right[2][1] == 3 && right[2][2] == 3 && right[1][0] == 3 && right[1][2] == 3 && up[0][1] == 6 && up[1][0] == 6 && up[1][2] == 6 && up[2][1] == 6 && back[0][1] ==2){
        //63'6'' 363'63 64'6''464'64 63'6''363'63
        U();
        Rr();
        U(); U();
        R();
        U();
        Rr();
        U();
        R();

        U();
        Bb();
        U(); U();
        B();
        U();
        Bb();
        U();
        B();

        U();
        Rr();
        U();U();
        R();
        U();
        Rr();
        U();
        R();
        commands += "U R' U'' R U R' U R U B' U'' B U B' U B U R' U'' R U R' U R ";
    }
    if (back[2][0] == 4 && back[2][1] == 4 && back[2][2] == 4 && back[1][0] == 4 && back[1][2] == 4 && back[0][1] == 3 && right[2][0] == 3 && right[2][1] == 3 && right[2][2] == 3 && right[1][0] == 3 && right[1][2] == 3  && up[0][1] == 6 && up[2][1] == 6 && up[1][0] == 6 && up[1][2] == 6){
        //62'6''262'62
        U();
        Ff();
        U(); U();
        F();
        U();
        Ff();
        U();
        F();
        commands += "U F' U'' F U F' U F ";
    }
    else if (back[2][0] == 4 && back[2][1] == 4 && back[2][2] == 4 && back[1][0] == 4 && back[1][2] == 4 && right[2][0] == 3 && right[2][1] == 3 && right[2][2] == 3 && right[1][0] == 3 && right[1][2] == 3  && up[0][1] == 6 && up[2][1] == 6 && up[1][0] == 6 && up[1][2] == 6 && left[0][1] == 3){
        //64'6''464'64 65'6''565'65 64'6''464'64
        U();
        Bb();
        U(); U();
        B();
        U();
        Bb();
        U();
        B();

        U();
        Ll();
        U(); U();
        L();
        U();
        Ll();
        U();
        L();

        U();
        Bb();
        U(); U();
        B();
        U();
        Bb();
        U();
        B();
        commands += "U B' U'' B U B' U B U L' U'' L U L' U L U B' U'' B U B' U B ";
    }
    if (back[2][0] == 4 && back[2][1] == 4 && back[2][2] == 4 && back[1][0] == 4 && back[1][2] == 4  && left[2][0] == 5 && left[2][1] == 5 && left[2][2] == 5 && left[1][0] == 5 && left[1][2] == 5 && left[0][1] == 4 && up[2][1] == 6 && up[1][2] == 6 && up[1][0] == 6 && up[0][1] == 6){
        //63'6''363'63
        U();
        Rr();
        U();U();
        R();
        U();
        Rr();
        U();
        R();
        commands += "U R' U'' R U R' U R ";
    }
}

void cube::sixth_step() {
    if ((face[0][0] == 2 && up[2][0] == 6 && left[0][2] == 3) || (face[0][0] == 2 && up[2][0] == 3 && left[0][2] == 6) || (face[0][0] == 3 && up[2][0] == 2 && left[0][2] == 6) || (face[0][0] == 3 && up[2][0] == 6 && left[0][2] == 2) || (face[0][0] == 6 && up[2][0] == 2  && left[0][2] == 3) || (face[0][0] == 6 && up[2][0] == 3 && left[0][2] == 2)){
        //2'5'2 3'2'523
        Ff();
        Ll();
        F();
        Rr();
        Ff();
        L();
        F();
        R();
        commands += "F' L' F R' F' L F R ";
    }
    else if ((back[0][0]==2 && up[0][2] == 3 && right[0][2] == 6) || (back[0][0]==2 && up[0][2] == 6 && right[0][2] == 3) || (back[0][0]==3 && up[0][2] == 2 && right[0][2] == 6) || (back[0][0]==3 && up[0][2] == 6 && right[0][2] == 2) || (back[0][0]==6 && up[0][2] == 2 && right[0][2] == 3) || (back[0][0]==6 && up[0][2] == 3 && right[0][2] == 2)){
        //3'2'5' 232'52
        Rr();
        Ff();
        Ll();
        F();
        R();
        Ff();
        L();
        F();
        commands += "R' F' L' F R F' L F ";
    }
    else if ((back[0][2] == 2 && up[0][0] == 3 && left[0][0] == 6) || (back[0][2] == 2 && up[0][0] == 6 && left[0][0] == 3) || (back[0][2] == 3 && up[0][0] == 2 && left[0][0] == 6) || (back[0][2] == 3 && up[0][0] == 6 && left[0][0] == 2) || (back[0][2] == 6 && up[0][0] == 3 && left[0][0] == 2) || (back[0][2] == 6 && up[0][0] == 2 && left[0][0] == 3)){
        // 2' 5'4'525'45
        Ff();
        Ll();
        Bb();
        L();
        F();
        Ll();
        B();
        L();
        commands += "F' L' B' L F L' B L ";
    }
    else{
        if ((face[0][0] == 3 && up[2][0] == 4 && left[0][2] == 6) || (face[0][0] == 3 && up[2][0] == 6 && left[0][2] == 4) || (face[0][0] == 4 && up[2][0] == 3 && left[0][2] == 6) || (face[0][0] == 4 && up[2][0] == 6 && left[0][2] == 3) || (face[0][0] == 6 && up[2][0] == 4  && left[0][2] == 3) || (face[0][0] == 6 && up[2][0] == 3 && left[0][2] == 4)){
            //4'3'4 5'4'345
            Bb();
            Rr();
            B();
            Ll();
            Bb();
            R();
            B();
            L();
            commands += "B' R' B L' B' R B L ";
        }
        else if ((back[0][2] == 3 && up[0][0] == 4 && left[0][0] == 6) || (back[0][2] == 3 && up[0][0] == 6 && left[0][0] == 4) || (back[0][2] == 4 && up[0][0] == 3 && left[0][0] == 6) || (back[0][2] == 4 && up[0][0] == 6 && left[0][0] == 3) || (back[0][2] == 6 && up[0][0] == 3 && left[0][0] == 4) || (back[0][2] == 6 && up[0][0] == 4 && left[0][0] == 3)) {
            //5'4'3' 454'34
            Ll();
            Bb();
            Rr();
            B();
            L();
            Bb();
            R();
            B();
            commands += "L' B' R' B L B' R B ";
        }
    }
}

void cube::seventh_step(){

    if (up[1][0] == 6 && up[0][1] == 6 && up[1][2] == 6 && up[2][1] == 6 && right[0][0] == 6) {
        //2'323' 2'323'
        Ff();
        R();
        F();
        Rr();
        Ff();
        R();
        F();
        Rr();
        commands += "F' R F R' F' R F R' ";
    } else if (up[1][0] == 6 && up[0][1] == 6 && up[1][2] == 6 && up[2][1] == 6 && face[0][2] == 6) {
        //32'3'2 32'3'2
        R();
        Ff();
        Rr();
        F();
        R();
        Ff();
        Rr();
        F();
        commands += "R F' R' F R F' R' F ";
    }
    else{
        U();
        commands+="U ";
    }

    for (int i =0; i<4 ; ++i) {
        if (up[1][0] == 6 && up[0][1] == 6 && up[1][2] == 6 && up[2][1] == 6 && right[0][0] == 6) {
            //2'323' 2'323'
            Ff();
            R();
            F();
            Rr();
            Ff();
            R();
            F();
            Rr();
            commands += "F' R F R' F' R F R' ";

        } else if (up[1][0] == 6 && up[0][1] == 6 && up[1][2] == 6 && up[2][1] == 6 && face[0][2] == 6) {
            //32'3'2 32'3'2
            R();
            Ff();
            Rr();
            F();
            R();
            Ff();
            Rr();
            F();
            commands += "R F' R' F R F' R' F ";
        }
        U();
        commands += "U ";
    }

    int flag = 0;
    while (!check_is_ready()){
        U();
        flag ++;
        if (flag == 4) {
            throw std::invalid_argument("the cube was wrong, program can not solve this!");
            break;
        }
    }
}

void cube::solve(int n) {
    if (n == 0 || n==7) {
        first_step();
        second_step();
        third_step();
        forth_step();
        fifth_step();
        sixth_step();
        seventh_step();
    }
    else{
        if (n==1){
            fifth_step();
            print_cube();
        }
        else if (n==2){
            first_step();
            second_step();
            print_cube();
        }
        else if (n==3){
            first_step();
            second_step();
            third_step();
            print_cube();
        }
        else if (n==4){
            first_step();
            second_step();
            third_step();
            forth_step();
            print_cube();
        }
        else if (n == 5){
            first_step();
            second_step();
            third_step();
            forth_step();
            fifth_step();
            print_cube();
        }
        else if (n == 6){
            first_step();
            second_step();
            third_step();
            forth_step();
            fifth_step();
            sixth_step();
            print_cube();
        }
        else
            cout << "i told u to print 0-7";
    }
}

void cube::scramble() {
    int k = rand() % 4 + 1;
    for (int i = 0; i<k; ++i){
        U();
        R();
    }
    k = rand() % 4 + 1;
    for (int i = 0; i<k; ++i){
        L();
        D();
    }
    k = rand() % 4 + 1;
    for (int i = 0; i<k; ++i){
        Rr();
        Ff();
    }
}
