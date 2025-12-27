#include<bits/stdc++.h>
using namespace std;
int R, C, N;
vector<string> grid;

int dirRow[4] = {-1 , 1, 0, 0};
int dirCol[4] = {0, 0 , -1, 1};

set<pair<int, int>> moveInDirection(int r, int c, int dir){
    set<pair<int, int>> postions;

    while(true){
        int nr = r + dirRow[dir];
        int nc = c + dirCol[dir];

        if(nr < 0 || nr >= R || nc < 0 || nc >= C || grid[nr][nc] == 'X'){
            break;
        }

        postions.insert({nr, nc});
        r = nr;
        c = nc;
    }
    return postions;
}

int main(){
    cin >> R >> C;
    grid.resize(R);

    int startR = -1, startC = -1;
    for(int i = 0; i < R; i++){
        cin >> grid[i];

        for(int j = 0; j < C; j++){
            if(grid[i][j] == '*'){
                startR = i;
                startC = j;
                grid[i][j] = '.';
            }
        }
    }

    cin >> N;
    set<pair<int, int>> currentPositions;
    currentPositions.insert({startR, startC});

    for(int i = 0; i < N; i++){
        string direction;
        cin >> direction;

        int dir;
        if(direction == "NORTH") dir = 0;
        else if(direction == "SOUTH") dir = 1;
        else if(direction == "WEST") dir = 2;
        else dir = 3;

        set<pair<int, int>> newPostions;

        for(auto& pos : currentPositions){

            int r = pos.first;
            int c = pos.second;

            set<pair<int, int>> reachable = moveInDirection(r, c, dir);

            newPostions.insert(reachable.begin(), reachable.end());

        }

        currentPositions = newPostions;
    }

    vector<string> result = grid;
    for(auto& pos : currentPositions){
        result[pos.first][pos.second] = '*';
    }

    for(int i = 0; i < R; i++){
        cout << result[i] << endl;
    }

    return 0;
}