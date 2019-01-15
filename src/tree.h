#ifndef TREE_H_INCLUDED
#define TREE_H_INCLUDED

#include "common.h"
#include "ball.h"

typedef struct {
    int x;          //Bottom centre of tree x
    int y;          //Bottom centre of tree y
    int size;       //Tree stamp width

    //calculated, shall not be updated manually
    int stamp_width;
    int stamp_height;
    int leaves_radius;

    GAMERECT    stamp;      //For drawing and hit test
    GAMECIRCLE  leaves[8];  //For drawing and hit test
} TREE;

void tree_bound(TREE *tree);

void tree_paint(TREE *tree);

int tree_hit(TREE tree, BALL *ball);

#endif // TREE_H_INCLUDED
