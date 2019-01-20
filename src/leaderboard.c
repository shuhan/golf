#include "leaderboard.h"

void leaderboard_read(LEADERBOARD *leaderboard, const char *file) {
    leaderboard->count = 0;
    FILE *file_handle = fopen(file, "r");
    while(leaderboard->count < MAX_SCORES &&
          fscanf(file_handle, "%d,%128s", &leaderboard->scores[leaderboard->count].score, leaderboard->scores[leaderboard->count].name) == 2) {
        leaderboard->count++;
    }
    fclose(file_handle);

    sort_score(leaderboard->scores, leaderboard->count);
}

void leaderboard_write(LEADERBOARD *leaderboard, const char *file) {
    int i;
    FILE *file_handle = fopen(file, "w");
    for(i = 0; i < leaderboard->count; i++) {
        fprintf(file_handle, "%d,%s\n", leaderboard->scores[i].score, leaderboard->scores[i].name);
    }
    fclose(file_handle);
}

void leaderboard_add_score(LEADERBOARD *leaderboard, GAMESCORE score) {
    leaderboard->scores[leaderboard->count] = score;
    leaderboard->count++;
    sort_score(leaderboard->scores, leaderboard->count);
    if(leaderboard->count > MAX_SCORES) leaderboard->count = MAX_SCORES;
}

void leaderboard_update(LEADERBOARD *leaderboard) {
    //Don't need to update anything right now
}

void leaderboard_paint(LEADERBOARD leaderboard) {
    setbkcolor(LIGHTBLUE);

    ground_paint(&leaderboard.ground);

    setcolor(LEADERBOARD_FORECOLOUR);

    int left    = (WIDTH - LEADERBOARD_WIDTH)/2;
    int top     = (HEIGHT - LEADERBOARD_HEIGHT)/2;

    filled_rectangle(left, top, left + LEADERBOARD_WIDTH, top + LEADERBOARD_HEIGHT, LEADERBOARD_COLOUR);
    rectangle(left, top, left + LEADERBOARD_WIDTH, top + LEADERBOARD_HEIGHT, 1);

    int i;

    int name_left   = left + LEADERBOARD_TEXT_OFFSET,
        line_top    = top + LEADERBOARD_TEXT_OFFSET,
        score_right = left + LEADERBOARD_WIDTH - LEADERBOARD_TEXT_OFFSET,
        line_height = get_line_height();

    for(i = 0; i < leaderboard.count; i++) {
        char score_text[16];
        sprintf(score_text, "%d", leaderboard.scores[i].score);

        int score_width = get_text_width(score_text);

        outtextxy(name_left, line_top, leaderboard.scores[i].name);
        outtextxy(score_right - score_width, line_top, score_text);

        line_top += line_height + LEADERBOARD_TEXT_OFFSET;
    }

    setcolor(DARKDIRT);
    outtextxy(left, top - line_height - LEADERBOARD_TEXT_OFFSET, "Score Board (Please press ESC or Right Click to close)");
}
