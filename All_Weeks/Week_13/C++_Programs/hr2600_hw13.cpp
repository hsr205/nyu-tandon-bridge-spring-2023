#include <iostream>
#include <ctime>
#include <cstdlib>
#include <set>

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
    int row;
    int column;
    int numTimeStep;
    set<Ant> classObjectSet;

public:
    Ant(){};
    Ant(int row, int column)
    {
        this->row = row;
        this->column = column;
    }

    Ant(int row, int column, int numTimeStep)
    {
        this->row = row;
        this->column = column;
        this->numTimeStep = numTimeStep;
    }

    void move() override
    {
        cout << "Ant is moving." << endl;
    }

    void breed() override
    {
        cout << "Ant is breeding." << endl;
    }

    char getSymbol() const
    {
        return this->symbol;
    }

    int getRow() const
    {
        return this->row;
    }

    int getColumn() const
    {
        return this->column;
    }

    set<Ant> getClassObjectSet()
    {
        return this->classObjectSet;
    }

    int getNumTimeStep() const
    {
        return this->numTimeStep;
    }

    void setRow(int row)
    {
        // TODO: Make it impossible for the character to fall off the map
        // if (row < 0 || row > 19)
        // {
        // }
        this->row = row;
    }

    void setColumn(int column)
    {
        // TODO: Make it impossible for the character to fall off the map
        // if (column < 0 || column > 19)
        // {
        // }
        this->column = column;
    }

    void setClassObjectSet(set<Ant> &classObjectSet, Ant ant)
    {
        classObjectSet.insert(ant);
    }

    /*
    TODO: Review operator overloading
    */
    bool operator<(const Ant &other) const
    {
        if (this->row != other.row)
        {
            return this->row < other.row;
        }
        return this->column < other.column;
    }
};

class DoodleBug : public Organism
{
private:
    char symbol = 'X';
    int row;
    int column;
    int numTimeStep;
    set<DoodleBug> classObjectSet;

public:
    DoodleBug(){};
    DoodleBug(int row, int column)
    {
        this->row = row;
        this->column = column;
    }

    DoodleBug(int row, int column, int numTimeStep)
    {
        this->row = row;
        this->column = column;
        this->numTimeStep = numTimeStep;
    }

    void move() override;

    void breed() override
    {
        cout << "DoodleBug is breeding." << endl;
    }
    void starve()
    {
        cout << "DoodleBug is starving." << endl;
    }

    char getSymbol() const
    {
        return this->symbol;
    }

    int getRow() const
    {
        return this->row;
    }

    int getColumn() const
    {
        return this->column;
    }

    int getNumTimeStep() const
    {
        return this->numTimeStep;
    }

    set<DoodleBug> getClassObjectSet()
    {
        return this->classObjectSet;
    }

    void setClassObjectSet(set<DoodleBug> &classObjectSet, DoodleBug doodleBug)
    {
        classObjectSet.insert(doodleBug);
    }

    void setRow(int row)
    {
        // TODO: Make it impossible for the character to fall off the map
        // if (row < 0 || row > 19)
        // {
        // }
        this->row = row;
    }

    void setColumn(int column)
    {
        // TODO: Make it impossible for the character to fall off the map
        // if (column < 0 || column > 19)
        // {
        // }
        this->column = column;
    }

    /*
        TODO: Review operator overloading
    */
    bool operator<(const DoodleBug &other) const
    {
        if (this->row != other.row)
        {
            return this->row < other.row;
        }
        return this->column < other.column;
    }
};

class Position
{

private:
    char symbol;
    int row;
    int column;

public:
    Position();
    Position(char symbol, int row, int column)
    {
        this->symbol = symbol;
        this->row = row;
        this->column = column;
    };

    char getSymbol()
    {
        return this->symbol;
    }

    int getRow()
    {
        return this->row;
    }

    int getColumn()
    {
        return this->column;
    }

    void setSymbol(char symbol)
    {
        this->symbol = symbol;
    }

    void setRow(int row)
    {
        this->row = row;
    }
    void setColumn(int column)
    {
        this->column = column;
    }

    /*
    TODO: Review operator overloading
*/
    bool operator<(const Position &other) const
    {
        if (this->row != other.row)
        {
            return this->row < other.row;
        }
        return this->column < other.column;
    }
};

class GameBoard
{
private:
    int rows = 20;
    int columns = 20;
    int maxAnts = 100;
    int maxDoodleBugs = 5;

    Ant ant;
    DoodleBug doodleBug;

    void populateAsEmptyGameBoard(char matrix[20][20])
    {
        for (int i = 0; i < this->rows; ++i)
        {
            for (int j = 0; j < this->columns; ++j)
            {
                matrix[i][j] = '-';
            }
        }
    }

    void populateGameBoardWithAnts(char matrix[20][20])
    {

        set<Ant> antSet = ant.getClassObjectSet();
        for (int i = 0; i < maxAnts; ++i)
        {
            int randomRow = rand() % this->rows;
            int randomColumn = rand() % this->columns;

            for (int j = 0; j < maxAnts; ++j)
            {
                if (matrix[randomRow][randomColumn] != doodleBug.getSymbol())
                {
                    matrix[randomRow][randomColumn] = ant.getSymbol();
                    ant.setClassObjectSet(antSet, Ant(randomRow, randomColumn));
                }
            }
        }
    }

public:
    int getRows()
    {
        return this->rows;
    }
    int getColumns()
    {
        return this->columns;
    }

    void populateGameBoardWithDoodleBugs(char matrix[20][20]);

    int populateGameBoard(char matrix[20][20])
    {

        srand(time(nullptr));

        populateAsEmptyGameBoard(matrix);
        populateGameBoardWithDoodleBugs(matrix);
        populateGameBoardWithAnts(matrix);

        return 0;
    };

    void printGameBoard(char matrix[20][20])
    {
        cout << string(58, '=') << endl;
        for (int i = 0; i < this->rows; ++i)
        {
            for (int j = 0; j < this->columns; ++j)
            {
                cout << matrix[i][j] << "  ";
            }
            cout << endl;
        }
        cout << string(58, '=') << endl;
    }

    bool exitProgram(string userInput, int &turnNum, bool isContinue)
    {

        if (userInput == "")
        {
            turnNum++;
            cout << endl;
        }
        else if (userInput == "0")
        {
            isContinue = false;
        }

        return isContinue;
    }

    void initializeSimulation()
    {
        int turnNum = 1;
        string userInput;
        char matrix[20][20];
        bool isContinue = true;
        populateGameBoard(matrix);

        while (isContinue)
        {
            cout << "Turn Number: " << turnNum << endl;

            printGameBoard(matrix);

            cout << "Proceed to next turn?" << endl;
            cout << "Press enter to proceed or 0 to end." << endl;

            getline(cin, userInput);

            isContinue = exitProgram(userInput, turnNum, isContinue);
        }
    }
};

void GameBoard::populateGameBoardWithDoodleBugs(char matrix[20][20])
{
    // set<DoodleBug> doodleBugSet = doodleBug.getClassObjectSet();
    set<Position> positionSet;
    char doodleBugSymbol = doodleBug.getSymbol();

    for (int i = 0; i < maxDoodleBugs; ++i)
    {
        int randomRow = rand() % this->rows;
        int randomColumn = rand() % this->columns;

        for (int j = 0; j < maxDoodleBugs; ++j)
        {
            matrix[randomRow][randomColumn] = doodleBugSymbol;
            positionSet.insert(Position(doodleBugSymbol, randomRow, randomColumn));
        }
    }

    // for (Position classObj : positionSet)
    // {
    //     cout << classObj.getSymbol() << "," << classObj.getRow() << "," << classObj.getColumn() << endl;
    // }
}

void DoodleBug::move()
{

    // cout << "DoodleBug is moving." << endl;

    // GameBoard gameBoard;

    // char matrix[20][20];

    // set<DoodleBug> classObjectSet = gameBoard.populateGameBoardWithDoodleBugs(matrix);

    // for (const DoodleBug &classObj : classObjectSet)
    // {
    //     cout << classObj.getRow() << "," << classObj.getColumn() << endl;
    // }

    // cout << string(58, '=') << endl;
}

int main()
{

    DoodleBug doodleBug;
    GameBoard gameBoard;

    doodleBug.move();
    gameBoard.initializeSimulation();

    /*
        TODO:

            (1) Make sure to pass the positionSet collection as an arument across all the populating methods
            (2) Once done make sure you can assess this set in the move() method
            (3) With the positional data you can then detemine how the DoodleBugs will move
            (4) Then how the ants will move
            (5) Add the additional behaviours (breed, eat, starve, etc.)
    */

    return 0;
}