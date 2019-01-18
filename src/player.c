#include "player.h"

void player_init(PLAYER *player) {
    animation_init(&(player->animation));
    player->winframe = load_bitmap(player->winframe_path);
    player->state = PLAYER_PLAYING;
}

void player_destroy(PLAYER *player) {
    animation_destroy(&(player->animation));
    destroy_bitmap(player->winframe);
}

void player_paint(PLAYER *player) {

    if(player->state == PLAYER_PLAYING) {
        animation_update(&(player->animation));
        animation_paint(&(player->animation));
    } else {
        draw_bitmap(player->winframe, player->animation.left, player->animation.top);
    }
}
