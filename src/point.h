#pragma once

typedef struct point_t {
    int x;
    int y;
} Point;

Point translate(Point base, Point delta);
Point translateDir(Point base, int direction);
int cdist(Point a, Point b);
double edist(Point a, Point b);
int isAdj(Point a, Point b);

extern Point DIRS[9];

typedef enum dirs_t {
    DIR_CENTER,
    DIR_N,
    DIR_NE,
    DIR_E,
    DIR_SE,
    DIR_S,
    DIR_SW,
    DIR_W,
    DIR_NW
} Directions;