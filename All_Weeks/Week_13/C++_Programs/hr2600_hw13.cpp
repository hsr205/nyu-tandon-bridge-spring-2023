#include <iostream>
#include <ctime>
#include <cstdlib>
#include <map>

using namespace std;

class Organism
{

public:
    Organism(){};

    virtual void move(){};
    virtual void breed(){};
};

class Ant : public Organism
{
private:
    char symbol = 'o';
    map<int, int> positionMap;

public:
    void move() override
    {
        cout << "Ant is moving." << endl;
    }

    void breed() override
    {
        cout << "Ant is breeding." << endl;
    }

    char getSymbol()
    {
        return this->symbol;
    }
};

class DoodleBug : public Organism
{
private:
    char symbol = 'X';
    map<int, int> positionMap;

public:
    void move() override
    {
        cout << "DoodleBug is moving." << endl;
    }

    void breed() override
    {
        cout << "DoodleBug is breeding." << endl;
    }
    void starve()
    {
        cout << "DoodleBug is starving." << endl;
    }

    char getSymbol()
    {
        return this->symbol;
    }
};

class GameBoard
{
private:
    int rows = 20;
    int columns = 20;
    int maxAnts = 100;
    int maxDoodleBugs = 5;

public:
    int getRows()
    {
        return this->rows;
    }
    int getColumns()
    {
        return this->columns;
    }

    char populateGameBoard(char matrix[][20], char antChar, char doodlebugChar)
    {
        srand(time(nullptr));

        for (int i = 0; i < this->rows; ++i)
        {
            for (int j = 0; j < this->columns; ++j)
            {
                matrix[i][j] = '-';
            }
        }

        for (int i = 0; i < maxDoodleBugs; ++i)
        {
            int randomRow = rand() % this->rows;
            int randomColumn = rand() % this->columns;

            for (int j = 0; j < maxDoodleBugs; ++j)
            {
                matrix[randomRow][randomColumn] = doodlebugChar;
            }
        }

        for (int i = 0; i < maxAnts; ++i)
        {
            int randomRow = rand() % this->rows;
            int randomColumn = rand() % this->columns;

            for (int j = 0; j < maxAnts; ++j)
            {
                if (matrix[randomRow][randomColumn] != doodlebugChar)
                {
                    matrix[randomRow][randomColumn] = antChar;
                }
            }
        }

        return matrix[this->rows][this->columns];
    };

    void printGameBoard(char matrix[][20])
    {
        for (int i = 0; i < this->rows; ++i)
        {
            for (int j = 0; j < this->columns; ++j)
            {
                cout << matrix[i][j] << "  ";
            }
            cout << endl;
        }
    }
};

int main()
{

    Ant ant;
    DoodleBug doodleBug;
    GameBoard gameBoard;

    char matrix[20][20];

    char antSymbol = ant.getSymbol();
    char doodlebugSymbol = doodleBug.getSymbol();

    gameBoard.populateGameBoard(matrix, antSymbol, doodlebugSymbol);
    gameBoard.printGameBoard(matrix);

    return 0;
}
