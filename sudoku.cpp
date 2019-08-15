/* Elchin Mamedaliev
 CP 2200
 Sudoku
 */

#include <iostream>
#include <iomanip>
using namespace std;
const int ROWS = 9;
const int COLS = 9;
bool is_sudocu_right(int[][COLS]);
bool is_line_valid(int[][COLS], int, bool);
bool subsquare1( int [][COLS],int ,int);


int main()
{
    int arr[ROWS][COLS] =  {{2,4,6,8,3,9,5,1,7},
        {5,7,8,6,4,1,9,3,2},
        {3,9,1,2,5,7,6,8,4},
        {9,1,3,9,2,5,4,7,6},
        {4,2,5,1,7,6,8,9,3},
        {7,6,9,4,8,3,2,5,1},
        {1,5,4,7,6,8,3,2,9},
        {6,8,7,3,9,2,1,4,5},
        {9,3,2,5,1,4,7,6,8}};
    
    // {3,9,1,2,5,7,6,8,4}, correct row 3
    // {8,1,3,9,2,5,4,7,6}, correct row 4
    
    bool is_right = is_sudocu_right(arr);
    
    if(is_right==1)// if is_sudoku_right returns true, sudoku is right
        cout<<"Sudoku is right!";
    else
        cout<<"Sudoku is NOT right!";
    
    
    
    return 0;
}
// general method calling the other methods
bool is_sudocu_right(int array[][COLS])
{
    bool is_right = true;
    bool is_subsquare1_right = true;
    bool is_row_right = true;
    bool is_column_right = true;
    
    int i;
    for (i = 0; i < 9; i++) {
        is_row_right = is_line_valid(array, i, true);// passing true to check a row
        is_column_right = is_line_valid(array, i, false);// passing false to check a column
        
        // if the two upper lines fail is_sudoku_right returns false
        if(!is_row_right || !is_column_right){
            is_right=false;
            break;
        }
        
    }
    
    //calling every subsquare with different coordinates
    
    for(int x=0;x<9;x+=3)
    {
        for(int y=0;y<9;y+=3)
        {
            is_subsquare1_right = subsquare1(array,x,y);
            
        }
        if(!is_subsquare1_right )
            is_right=false;
    }
    return is_right;
}

// method checks either line or column depends on position, if position is false method cheks columns and vice verse.
bool is_line_valid(int arr[][COLS], int j, bool position) {// j is number of row or column
    bool is_right = true;
    int x,y;
    int flags[] = { 0,0,0,0,0,0,0,0,0 };// additional cheking array (flags) , works only with specific length of an array, but works.
    for (int i = 0; i < 9; i++) {
        if (position) {//rows
            x=j;
            y=i;
        }
        else{//columns
            y=j;
            x=i;
        }
        
        int a = 0;
        a = arr[x][y];
        //        cout << a << "  ";
        if (flags[a - 1] != 1) { // a-1, because if number 9 goes into the flags it becomes an index, but the last indext in the array is 8.
            flags[a - 1] = 1;
        }
        else {
            is_right = false;
            break;
        }
    }
    //cout << endl;
    return is_right;
}

// method checks a subsquare with different coordinates
bool subsquare1( int arr[][COLS], int x ,int y){
    bool is_right=true;
    
    int flags[] = { 0,0,0,0,0,0,0,0,0 };
    
    for (int i = x; i < x+3; i++)
    {
        for (int j = y; j< y+3; j++)
        {
            int a = 0;
            a = arr[i][j];
            if (flags[a - 1] != 1) {
                flags[a - 1] = 1;
            }
            else {
                cout<<"Bad coder!  "<<"The number "<<a<<" is repeated in the subsquare: "<<endl;
                for (int i = x; i < x + 3; i++)
                {
                    for  (int j = y; j< y+3; j++)
                    {
                        cout<<arr[i][j]<<"  ";
                    }
                    cout<<endl;
                }
                
                cout<<"Subsquare starts at coordinates "<<"["<<x+1<<"]"<<" "<<"["<<y+1<<"]"<<" and ends at "<<"["<<x+3<<"]"<<" "<<"["<<y+3<<"]"<<endl;
                cout<<endl;
                is_right = false;
                break;
            }
            //cout<<arr[i][j]<<"  ";
        }
        //cout<<endl;
    }
    return is_right;
}






