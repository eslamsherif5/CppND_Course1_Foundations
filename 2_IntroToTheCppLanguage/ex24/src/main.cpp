#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using std::cout;
using std::ifstream;
using std::string;
using std::vector;


// TODO: Add the ParseLine function here.
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
void ReadBoardFile(string path)
{
    ifstream myfile(path);
    if (myfile)
    {
        string line;
        while (getline(myfile, line))
        {
            cout << line << "\n";
        }
    }
}

// For testing.
void PrintVector(vector<int> v) {
  cout << "{ ";
  for (auto item : v) {
    cout << item << " ";
  }
  cout << "}" << "\n";
}

void TestParseLine() {
  cout << "----------------------------------------------------------" << "\n";
  cout << "TestParseLine: ";
  string line = "0,1,0,0,0,0,";
  vector<int> solution_vect{0,1,0,0,0,0};
  vector<int> test_vect;
  test_vect = ParseLine(line);
  if (test_vect != solution_vect) {
    cout << "failed" << "\n";
    cout << "\n" << "Test input string: " << line << "\n";
    cout << "Your parsed line: ";
    PrintVector(test_vect);
    cout << "\n";
  } else {
    cout << "passed" << "\n";
  }
  cout << "----------------------------------------------------------" << "\n";
  return;
}

int main()
{
    std::istringstream test;
    ReadBoardFile("1.board");
    TestParseLine(); // For testing.
                     // Leave commented out.
                     // PrintBoard(board);
}
