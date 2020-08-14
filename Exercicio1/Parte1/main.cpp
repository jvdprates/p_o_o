#include <iostream>
#include <fstream>
#include "string"

using namespace std;

int readChars(string filePath)
{
  int countEmpty = 0;
  ifstream myFile(filePath);
  char c;

  if (myFile.is_open())
  {
    while (myFile.good())
    {
      myFile.get(c);
      if (c == ' ')
      {
        countEmpty++;
      }
    }
  }

  if (!myFile.eof() && myFile.fail())
  {
    cout << "There was an error while attempting to read " << filePath << endl;
  }

  myFile.close();
  return countEmpty;
};

void readText(string filePath)
{
  ifstream myFile(filePath);
  string myText;

  while (getline(myFile, myText))
  {
    cout << myText << "\n";
  };

  myFile.close();
};

int main()
{
  string myText;
  const string path = "./public/file.txt";
  char myChoice = 'Y';
  char finalizeIt = 'N';

  cout << "Opening path: " << path << "\n";

  int counted = readChars(path);

  cout << "There is " << counted << " empty spaces in " << path << "\n";

  while (finalizeIt == 'N')
  {
    while (1)
    {
      cout << "Do you want me to write it out for you? [Y,N] - ";
      cin >> myChoice;
      if (myChoice == 'Y')
      {
        readText(path);
      }

      if (myChoice != 'Y' && myChoice != 'N')
      {
        cerr << "Invalid input!"
             << "\n";
      }
      else
        break;
    }

    while (1)
    {
      cout << "Do you want to terminate the program? [Y,N] - ";
      cin >> finalizeIt;

      if (finalizeIt != 'Y' && finalizeIt != 'N')
      {
        {
          cerr << "Invalid input!"
               << "\n";
        }
      }
      else
        break;
    }
  }

  cout << "See you later!"
       << "\n";

  return 0;
}