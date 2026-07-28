#include <iostream>
#include <vector>
#include <set>
#include <stack>

using namespace std;
struct PuzzleState{
    vector<vector<int>> board;
    int x,y;
    int depth;
    PuzzleState(vector<vector<int>> b, int i, int j, int d) : board(b), x(i), y(j), depth(d) {}
};

void printBoard(vector<vector<int>>& board) {
    for (auto& row : board) {
        for (auto& num : row)
            cout << num << " ";
        cout << endl;
    }
    cout << "--------" << endl;
};

int isValid(int x,int y)//Check if move valid
{
    return (x>=0 && y>=0 && x<3 && y<3);
};

bool isGoalState(vector<vector<int>>& board,vector<vector<int>>& goal)
{
    return(board==goal);
};
int row[] = {0, 0, -1, 1};//Possible values for moving
int col[] = {-1, 1, 0, 0};
int solveDfsPuzzle(vector<vector<int>> start,int x,int y,vector<vector<int>> goal){
    stack<PuzzleState> st;
    set<vector<vector<int>>> visited;
    const int maxDepth=32;
    st.push(PuzzleState(start,x,y,0));
    visited.insert(start);
    while(!st.empty())
    { 
        PuzzleState curr=st.top();//store top element before popping
        st.pop();
         if(curr.depth >= maxDepth)
            continue;
        cout<<"Depth:"<<curr.depth<<endl;
        printBoard(curr.board);
        if (isGoalState(curr.board,goal)) {
            cout << "Goal state reached at depth " << curr.depth << endl;
            return curr.depth;
        }  
        for (int i = 0; i < 4; i++) {
            int newX = curr.x + row[i];
            int newY = curr.y + col[i];
            if (isValid(newX, newY)) {
                vector<vector<int>> newBoard = curr.board;
                swap(newBoard[curr.x][curr.y], newBoard[newX][newY]);

                if (visited.find(newBoard) == visited.end()) {
                    visited.insert(newBoard);
                    st.push(PuzzleState(newBoard, newX, newY, curr.depth + 1));
                }
            }
        }
    }
    cout << "No solution found (DFS Brute Force reached depth limit)" << endl;
    return -1;
};


int main(){
    int ele,x,y;
    vector<vector<int>> start(3,vector<int>(3));
    vector<vector<int>> goal={{1,2,3},{4,5,6},{7,8,0}};
    cout<<" Goal State"<<endl;
    printBoard(goal);
    cout<<"Enter Start State"<<endl;
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            cin>>ele;
            start[i][j]=ele;   
            if(ele==0)
            {
                x=i;
                y=j;
            }
        }
    }
    cout<<"Check Your Board"<<endl;
    printBoard(start);
    solveDfsPuzzle(start,x,y,goal);
};