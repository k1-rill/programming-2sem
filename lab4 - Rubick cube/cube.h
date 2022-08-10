#ifndef LAB4_CUBE_H
#define LAB4_CUBE_H
#include <vector>
#include <string>
using namespace std;
/*
 * 1 - green
 * 2 - white
 * 3 - blue
 * 4 - yellow
 * 5 - orange
 * 6 - red
 *
 *     6 6 6
       6 6 6
       6 6 6
5 5 5  2 2 2  3 3 3  4 4 4
5 5 5  2 2 2  3 3 3  4 4 4
5 5 5  2 2 2  3 3 3  4 4 4
       1 1 1
       1 1 1
       1 1 1
 */

class cube{
private:
    vector <vector<int>> face; // 2
    vector <vector<int>> back; // 4
    vector <vector<int>> right; // 3
    vector <vector<int>> left; // 1
    vector <vector<int>> down; // 5
    vector <vector<int>> up; // 0
    string commands;

public:
    cube();

    void read_cube();

    void print_cube();

    bool check_correct();

    bool check_is_ready();
    void console_output();
    void turn_side(vector<vector<int>> & buf);

    void R();
    void Rr();
    void F();
    void Ff();
    void U();
    void Uu();
    void B();
    void Bb();
    void L();
    void Ll();
    void D();
    void Dd();

    void first_step();
    void second_step();
    void third_step();
    void forth_step();
    void fifth_step();
    void sixth_step();
    void seventh_step();

    void solve(int n);

    void scramble();

};


#endif //LAB4_CUBE_H
