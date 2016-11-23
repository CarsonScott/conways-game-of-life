#ifndef GRID_HPP_INCLUDED
#define GRID_HPP_INCLUDED

#include <vector>

class Grid
{
    std::vector<std::vector<int>> cells;
    std::vector<std::vector<int>> new_cells;

    bool in_range(float lower, float upper, float val)
    {
        return val >= lower && val <= upper;
    }

    int getActiveNeighbors(int x, int y)
    {
        int neighbors = 0;
        for(int i = y-1; i <= y+1; i++)
        {
            for(int j = x-1; j <= x+1; j++)
            {
                if(in_range(0, cells.size()-1, i) && in_range(0, cells[i].size()-1, j))
                {
                    if(i != y || j != x)
                    {
                        neighbors += cells[i][j];
                    }
                }
            }
        }
        return neighbors;
    }

public:
    Grid(int width, int height)
    {
        for(int i = 0; i < height; i++)
        {
            cells.push_back(std::vector<int>());
            for(int j = 0; j < width; j++)
            {
                cells[i].push_back(0);
            }
        }
        new_cells = cells;
    }

    void reset()
    {
        for(int i = 0; i < cells.size(); i++)
        {
            for(int j = 0; j < cells[i].size(); j++)
            {
                cells[i][j] = 0;
                new_cells[i][j] = 0;
            }
        }
    }

    void update()
    {
        for(int y = 0; y < cells.size(); y++)
        {
            for(int x = 0; x < cells[y].size(); x++)
            {
                int state = cells[y][x];
                int new_state = state;
                int neighbors = getActiveNeighbors(x, y);

                if(state == 1)
                {
                    if(neighbors < 2 || neighbors > 3)
                    {
                        new_state = 0;
                    }
                }
                else
                {
                    if(neighbors == 3)
                    {
                        new_state = 1;
                    }
                }
                new_cells[y][x] = new_state;
            }
        }
        cells = new_cells;
    }

    int getCell(int x, int y)
    {
        return cells[y][x];
    }

    void setCell(int x, int y, int val)
    {
        cells[y][x] = val;
        new_cells[y][x] = val;
    }

    std::vector<std::vector<int>> getCells()
    {
        return cells;
    }
};

#endif // GRID_HPP_INCLUDED
