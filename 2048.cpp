#include <iostream>
#include <cstdio>
#include <cstdlib>

// implementing 2048 game

class puzzle2048
{
private:
    int board[4][4];
    int span;
    int spaceLeft;
    bool moved;
    
    void spawn(void)
    {
        srand((unsigned int)time(0));
        
        int row = rand() % 4;
        int col = rand() % 4;
        
        while(board[row][col] != 0)
        {
            row = rand() % 4;
            col = rand() % 4;
        }
        
        board[row][col] = 2 * (rand() % 2 + 1);
        moved = false;
    }

public:
    puzzle2048(void) : span(4), spaceLeft(16), moved(false)
    {
        for(int i = 0; i < 4; i++)
        {
            for(int j = 0; j < 4; j++)
            {
                board[i][j] = 0;
            }
        }
        
        for(int i = 0; i < 2; i++) spawn();
    }

    void moveUp(void)
    {
        for (int i = 0; i < span; i++)
        {
            // push all up
            for (int j = 0; j < span - 1; j++)
            {
                // if empty in current position, bring the next rest to it
                if (board[j][i] == 0)
                {
                    int bringSpace = 0;
                    bool allClear = true;

                    // find a space that is not 0
                    while (bringSpace + j < span)
                    {
                        if (board[bringSpace + j][i] != 0)
                        {
                            allClear = false;
                            break;
                        }

                        bringSpace++;
                    }

                    // if you find it, bring the next them here
                    if (!allClear)
                    {
                        moved = true;
                        
                        int k;
                        for (k = 0; k + j + bringSpace < span; k++)
                        {
                            board[j + k][i] = board[j + k + bringSpace][i];
                        }

                        while (j + k < span)
                        {
                            board[j + k][i] = 0;
                            k++;
                        }
                    }
                }
            }

            // check collision between two same-value digits
            for (int j = 1; j < span; j++)
            {
                // if this position is not empty and equals to the previous, merge
                if (board[j][i] != 0 && board[j][i] == board[j - 1][i])
                {
                    moved = true;
                    
                    board[j - 1][i] *= 2;
                    board[j][i] = 0;
                }
            }

            // finish: push all up again
            for (int j = 0; j < span - 1; j++)
            {
                // if empty in current position, bring the next to it
                if (board[j][i] == 0)
                {
                    int bringSpace = 0;
                    bool allClear = true;

                    // find a space that is not 0
                    while (bringSpace + j < span)
                    {
                        if (board[bringSpace + j][i] != 0)
                        {
                            allClear = false;
                            break;
                        }

                        bringSpace++;
                    }

                    // if you find it, bring the next them here
                    if (!allClear)
                    {
                        moved = true;
                        
                        int k;
                        for (k = 0; k + j + bringSpace < span; k++)
                        {
                            board[j + k][i] = board[j + k + bringSpace][i];
                        }

                        while (j + k < span)
                        {
                            board[j + k][i] = 0;
                            k++;
                        }
                    }
                }
            }
        }
    }

    void moveDown(void)
    {
        for (int i = 0; i < span; i++)
        {
            // push all down
            for (int j = span - 1; j >= 1; j--)
            {
                // if empty in current position, bring the next rest to it
                if (board[j][i] == 0)
                {
                    int bringSpace = 0;
                    bool allClear = true;

                    // find a space that is not 0
                    while (j - bringSpace >= 0)
                    {
                        if (board[j - bringSpace][i] != 0)
                        {
                            allClear = false;
                            break;
                        }

                        bringSpace++;
                    }

                    // if you find it, bring the next them here
                    if (!allClear)
                    {
                        moved = true;
                        
                        int k;
                        for (k = 0; j - k - bringSpace >= 0; k++)
                        {
                            board[j - k][i] = board[j - k - bringSpace][i];
                        }

                        while (j - k >= 0)
                        {
                            board[j - k][i] = 0;
                            k++;
                        }
                    }
                }
            }

            // check collision between two same-value digits
            for (int j = span - 2; j >= 0; j--)
            {
                // if this position is not empty and equals to the previous, merge
                if (board[j][i] != 0 && board[j][i] == board[j + 1][i])
                {
                    moved = true;
                    
                    board[j + 1][i] *= 2;
                    board[j][i] = 0;
                }
            }

            // finish: push all down again
            for (int j = span - 1; j >= 1; j--)
            {
                // if empty in current position, bring the next rest to it
                if (board[j][i] == 0)
                {
                    int bringSpace = 0;
                    bool allClear = true;

                    // find a space that is not 0
                    while (j - bringSpace >= 0)
                    {
                        if (board[j - bringSpace][i] != 0)
                        {
                            allClear = false;
                            break;
                        }

                        bringSpace++;
                    }

                    // if you find it, bring the next them here
                    if (!allClear)
                    {
                        moved = true;
                        
                        int k;
                        for (k = 0; j - k - bringSpace >= 0; k++)
                        {
                            board[j - k][i] = board[j - k - bringSpace][i];
                        }

                        while (j - k >= 0)
                        {
                            board[j - k][i] = 0;
                            k++;
                        }
                    }
                }
            }
        }
    }

    void moveLeft(void)
    {
        for (int i = 0; i < span; i++)
        {
            // push all left
            for (int j = 0; j < span - 1; j++)
            {
                // if empty in current position, bring the next rest to it
                if (board[i][j] == 0)
                {
                    int bringSpace = 0;
                    bool allClear = true;

                    // find a space that is not 0
                    while (bringSpace + j < span)
                    {
                        if (board[i][bringSpace + j] != 0)
                        {
                            allClear = false;
                            break;
                        }

                        bringSpace++;
                    }

                    // if you find it, bring the next them here
                    if (!allClear)
                    {
                        moved = true;
                        
                        int k;
                        for (k = 0; k + j + bringSpace < span; k++)
                        {
                            board[i][j + k] = board[i][j + k + bringSpace];
                        }

                        while (j + k < span)
                        {
                            board[i][j + k] = 0;
                            k++;
                        }
                    }
                }
            }

            // check collision between two same-value digits
            for (int j = 1; j < span; j++)
            {
                // if this position is not empty and equals to the previous, merge
                if (board[i][j] != 0 && board[i][j] == board[i][j - 1])
                {
                    moved = true;
                    
                    board[i][j - 1] *= 2;
                    board[i][j] = 0;
                }
            }

            // finish: push all left again
            for (int j = 0; j < span - 1; j++)
            {
                // if empty in current position, bring the next rest to it
                if (board[i][j] == 0)
                {
                    int bringSpace = 0;
                    bool allClear = true;

                    // find a space that is not 0
                    while (bringSpace + j < span)
                    {
                        if (board[i][bringSpace + j] != 0)
                        {
                            allClear = false;
                            break;
                        }

                        bringSpace++;
                    }

                    // if you find it, bring the next them here
                    if (!allClear)
                    {
                        moved = true;
                        
                        int k;
                        for (k = 0; k + j + bringSpace < span; k++)
                        {
                            board[i][j + k] = board[i][j + k + bringSpace];
                        }

                        while (j + k < span)
                        {
                            board[i][j + k] = 0;
                            k++;
                        }
                    }
                }
            }
        }
    }

    void moveRight(void)
    {
        for (int i = 0; i < span; i++)
        {
            // push all right
            for (int j = span - 1; j >= 1; j--)
            {
                // if empty in current position, bring the next rest to it
                if (board[i][j] == 0)
                {
                    int bringSpace = 0;
                    bool allClear = true;

                    // find a space that is not 0
                    while (j - bringSpace >= 0)
                    {
                        if (board[i][j - bringSpace] != 0)
                        {
                            allClear = false;
                            break;
                        }

                        bringSpace++;
                    }

                    // if you find it, bring the next them here
                    if (!allClear)
                    {
                        moved = true;
                        
                        int k;
                        for (k = 0; j - k - bringSpace >= 0; k++)
                        {
                            board[i][j - k] = board[i][j - k - bringSpace];
                        }

                        while (j - k >= 0)
                        {
                            board[i][j - k] = 0;
                            k++;
                        }
                    }
                }
            }

            // check collision between two same-value digits
            for (int j = span - 2; j >= 0; j--)
            {
                // if this position is not empty and equals to the previous, merge
                if (board[i][j] != 0 && board[i][j] == board[i][j + 1])
                {
                    moved = true;
                    
                    board[i][j + 1] *= 2;
                    board[i][j] = 0;
                }
            }

            // finish: push all right again
            for (int j = span - 1; j >= 1; j--)
            {
                // if empty in current position, bring the next rest to it
                if (board[i][j] == 0)
                {
                    int bringSpace = 0;
                    bool allClear = true;

                    // find a space that is not 0
                    while (j - bringSpace >= 0)
                    {
                        if (board[i][j - bringSpace] != 0)
                        {
                            allClear = false;
                            break;
                        }

                        bringSpace++;
                    }

                    // if you find it, bring the next them here
                    if (!allClear)
                    {
                        moved = true;
                        
                        int k;
                        for (k = 0; j - k - bringSpace >= 0; k++)
                        {
                            board[i][j - k] = board[i][j - k - bringSpace];
                        }

                        while (j - k >= 0)
                        {
                            board[i][j - k] = 0;
                            k++;
                        }
                    }
                }
            }
        }
    }

    void printBoard(void)
    {
        int spaces = 0;
        
        for (int i = 0; i < span; i++)
        {
            for (int j = 0; j < span; j++)
            {
                printf("%4d ", board[i][j]);
                
                if(board[i][j] == 0)
                {
                    spaces++;
                }
            }

            printf("\n");
        }
        
        spaceLeft = spaces;
    }
    
    void spawnNumber(void)
    {
        if(spaceLeft <= 0 || !moved)
        {
            return;
        }
        
        spawn();
    }
};

int main(void)
{
    puzzle2048 p;
    
    while(true)
    {
        p.printBoard();
        
        char input;
        std::cin >> input;
        
        switch(input)
        {
            case 'w':
            p.moveUp();
            break;
            
            case 's':
            p.moveDown();
            break;
            
            case 'a':
            p.moveLeft();
            break;
            
            case 'd':
            p.moveRight();
            break;
        }
        
        p.spawnNumber();
    }
    
    return 0;
}
