#include "tree.h"
#include <graphics_lib.h>

void tree_bound(TREE *tree) {

    tree->stamp_width   = tree->size;
    tree->stamp_height  = tree->stamp_width * 5;
    tree->leaves_radius = tree->stamp_width * 2;

    GAMERECT stamp = {{tree->x, tree->y - tree->stamp_height}, {tree->x + tree->stamp_width, tree->y}};

    tree->stamp = stamp;

    int stamp_top_x = tree->x + (tree->stamp_width / 2);
    int stamp_top_y = tree->y - tree->stamp_height;

    GAMECIRCLE c0 = {{stamp_top_x - tree->leaves_radius, stamp_top_y}, tree->leaves_radius};
    tree->leaves[0] = c0;   //Left Bottom
    GAMECIRCLE c1 = {{stamp_top_x - (1.5 * tree->leaves_radius), stamp_top_y - tree->leaves_radius}, tree->leaves_radius};
    tree->leaves[1] = c1;   //Left Second
    GAMECIRCLE c2 = {{stamp_top_x - tree->leaves_radius, stamp_top_y - (2 * tree->leaves_radius)}, tree->leaves_radius};
    tree->leaves[2] = c2;   //Left Third
    GAMECIRCLE c3 = {{stamp_top_x, stamp_top_y - (3 * tree->leaves_radius)}, tree->leaves_radius};
    tree->leaves[3] = c3;   //Centre Top
    GAMECIRCLE c4 = {{stamp_top_x + tree->leaves_radius, stamp_top_y - (2 * tree->leaves_radius)}, tree->leaves_radius};
    tree->leaves[4] = c4;   //Right Third
    GAMECIRCLE c5 = {{stamp_top_x + (1.5 * tree->leaves_radius), stamp_top_y - tree->leaves_radius}, tree->leaves_radius};
    tree->leaves[5] = c5;   //Right Second
    GAMECIRCLE c6 = {{stamp_top_x + tree->leaves_radius, stamp_top_y}, tree->leaves_radius};
    tree->leaves[6] = c6;   //Right Bottom
    GAMECIRCLE c7 = {{stamp_top_x, stamp_top_y - tree->leaves_radius}, tree->leaves_radius};
    tree->leaves[7] = c7;   //Centre Fillup
}

void tree_paint(TREE *tree) {

    int leaf_colour = FOREST;
    int stamp_colour = BROWN;

    tree_bound(tree);

    filled_gamerect(tree->stamp, stamp_colour);

    int i;
    for(i = 0; i < 8; i++)
        filled_gamecircle(tree->leaves[i], leaf_colour);
}

int tree_hit(TREE tree, BALL *ball) {
    if(hit_gamerect(tree.stamp, ball->shape)) {
        ball->horizontal_speed *= -1 * ( 1 - TREE_LOSS);
        return 1;
    }

    int i;
    for(i = 0; i < 8; i++) {
        if(hit_gamecircle(tree.leaves[i], ball->shape)) {
            ball->horizontal_speed = abs(ball->horizontal_speed * (1 - TREE_LOSS)) + TREE_LEAVES_SHAKE;
            if(i < 3) {
                ball->horizontal_speed *= -1;
            }
            ball->vertical_speed = abs(ball->vertical_speed * (1 - TREE_LOSS));
            if(i == 0 || i == 6) {
                ball->vertical_speed *= -1;
            }
            //ball->state = BALL_LOST;    //Ball is lost when it hits the leaves
            //ball->horizontal_speed  = 0;
            //ball->vertical_speed    = 0;

            return 1;
        }
    }

    return 0;
}
