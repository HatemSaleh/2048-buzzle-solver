#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <fstream>
using namespace std;

class Matrix
{
    private:
    vector<vector<int>> myMatrix;
    public:
    Matrix();
    
    int getRow() {return myMatrix.size();}
    int getCol() {return myMatrix.size();}
    vector<vector<int>> getMatrix(){return myMatrix;}
    void slideRight();
    void slideLeft();
    void slideUp();
    void slideDown();
    void slide(int);
    void fillInMatrix(ifstream&, int row, int col );  
    bool impossible();
    bool isSolved();
    int count();  
    string solve(int level, Matrix&, string path, ofstream&);
};