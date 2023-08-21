#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using std::abs;
using std::cout;
using std::ifstream;
using std::istringstream;
using std::string;
using std::vector;

enum class State
{
    kEmpty,
    kObstacle
};

vector<State> ParseLine(string line)
{
    istringstream sline(line);
    int n;
    char c;
    vector<State> row;
    while (sline >> n >> c && c == ',')
    {
        if (n == 0)
        {
            row.push_back(State::kEmpty);
        }
        else
        {
            row.push_back(State::kObstacle);
        }
    }
    return row;
}

vector<vector<State>> ReadBoardFile(string path)
{
    ifstream myfile(path);
    vector<vector<State>> board{};
    if (myfile)
    {
        string line;
        while (getline(myfile, line))
        {
            vector<State> row = ParseLine(line);
            board.push_back(row);
        }
    }
    return board;
}

// TODO: Write the Search function stub here.
std::vector<vector<State>> Search(std::vector<vector<State>> copy_Board, int start[2], int goal[2])
{
    std::cout << "No path found!" << std::endl;
    std::vector<vector<State>> board_with_path;
    return board_with_path;
}

string CellString(State cell)
{
    switch (cell)
    {
    case State::kObstacle:
        return "⛰️   ";
    default:
        return "0   ";
    }
}

void PrintBoard(const vector<vector<State>> board)
{
    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board[i].size(); j++)
        {
            cout << CellString(board[i][j]);
        }
        cout << "\n";
    }
}

int main()
{
    // TODO: Declare "init" and "goal" arrays with values {0, 0} and {4, 5} respectively.
    int init[2] = {0,0};
    int goal[2] = {4,5};

    auto board = ReadBoardFile("1.board");

    // TODO: Call Search with "board", "init", and "goal". Store the results in the variable "solution".
    auto solution = Search(board, init, goal);

    // TODO: Change the following line to pass "solution" to PrintBoard.
    PrintBoard(solution);
}