#include "point.h"
#include "utils.h"
#include <math.h>

Point DIRS[9] = {
    {0, 0},
    {0, -1},
    {1, -1},
    {1, 0},
    {1, 1},
    {0, 1},
    {-1, 1},
    {-1, 0},
    {-1, -1}
};

Point translate(Point base, Point delta) {
    Point result;
    result.x = base.x + delta.x;
    result.y = base.y + delta.y;
    return result;
}

Point translateDir(Point base, int direction) {
    return translate(base, DIRS[direction]);
}

int cdist(Point a, Point b) {
    int xdist = abs(b.x - a.x);
    int ydist = abs(b.y - a.y);
    return max(xdist, ydist);
}

double edist(Point a, Point b) {
    int ys = b.y - a.y;
    int xs = b.x - a.x;
    return sqrt((ys * ys) + (xs * xs));
}

int isAdj(Point a, Point b) {
    return cdist(a, b) == 1;
}