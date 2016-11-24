#ifndef GRID_HPP_INCLUDED
#define GRID_HPP_INCLUDED

#include <vector>

class Grid
{
    std::vector<std::vector<int>> cells;
    std::vector<std::vector<int>> new_cells;

    bool in_range(float, float, float);
    int getActiveNeighbors(int, int);

public:
    Grid(int, int);
    void reset();
    void update();
    int getCell(int, int);
    void setCell(int, int, int);
    std::vector<std::vector<int>> getCells();
};

#endif // GRID_HPP_INCLUDED
