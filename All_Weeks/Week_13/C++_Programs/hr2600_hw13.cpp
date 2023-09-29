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

class GameBoard
{
private:
    int rows = 20;
    int columns = 20;
    int maxAnts = 100;
    int maxDoodleBugs = 5;

    Ant ant;
    DoodleBug doodleBug;

public:
    int getRows()
    {
        return this->rows;
    }
    int getColumns()
    {
        return this->columns;
    }

    char populateGameBoard(char matrix[20][20])
    {

        set<DoodleBug> doodleBugSet = doodleBug.getClassObjectSet();
        set<Ant> antSet = ant.getClassObjectSet();

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
                matrix[randomRow][randomColumn] = doodleBug.getSymbol();
                doodleBug.setClassObjectSet(doodleBugSet, DoodleBug(randomRow, randomColumn));
            }
        }

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

        for (const DoodleBug &classObj : doodleBugSet)
        {
            cout << classObj.getRow() << "," << classObj.getColumn() << endl;
        }

        cout << string(58, '=') << endl;

        return matrix[this->rows][this->columns];
    };

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

            cout << "Proceed to next turn?" << endl;
            cout << "Press enter to proceed or 0 to end." << endl;

            getline(cin, userInput);

            if (userInput == "")
            {
                turnNum++;
                cout << endl;
                continue;
            }
            else if (userInput == "0")
            {
                isContinue = false;
            }
        }
    }

    // void printGameBoard()
    // {
    //     char matrix[20][20];
    //     populateGameBoard(matrix);

    //     cout << string(58, '=') << endl;
    //     for (int i = 0; i < this->rows; ++i)
    //     {
    //         for (int j = 0; j < this->columns; ++j)
    //         {
    //             cout << matrix[i][j] << "  ";
    //         }
    //         cout << endl;
    //     }
    //     cout << string(58, '=') << endl;
    // }
};

int main()
{

    GameBoard gameBoard;

    gameBoard.initializeSimulation();

    return 0;
}
