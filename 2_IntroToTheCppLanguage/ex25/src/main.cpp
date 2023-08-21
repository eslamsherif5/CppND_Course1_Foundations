#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>

using std::cout;
using std::string;
using std::vector;

std::vector<int> ParseLine(std::string line)
{
    // "1,0,0,0,0,"
    std::vector<int> line_v;
    std::istringstream line_ss(line);
    int n; char c;
    while (line_ss >> n >> c)
    {
        line_v.push_back(n);
    }
    return line_v;
}

// TODO: Add the ReadBoardFile function here.
std::vector<std::vector<int>> ReadBoardFile(const std::string &filePath)
{
    std::fstream file(filePath);
    if (!file)
    {
        std::cout << "Empty file passed. Exiting." << std::endl;
        return {}; // empty vector // abdo
    }

    std::vector<std::vector<int>> board;
    std::string line{};
    while (getline(file, line))
    {
        // std::cout << line << std::endl;
        board.push_back(ParseLine(line));
    }
    return board;
}

// PrintBoard not used in this exercise
void PrintBoard(const vector<vector<int>> board)
{
    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board[i].size(); j++)
        {
            cout << board[i][j];
        }
        cout << "\n";
    }
}

int main()
{
    // TODO: Call the ReadBoardFile function here.
    std::vector<std::vector<int>> boardFromFile = ReadBoardFile("1.board");
    // Leave the following line commented out.
    PrintBoard(boardFromFile);
}