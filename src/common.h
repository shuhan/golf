#ifndef COMMON_H_INCLUDED
#define COMMON_H_INCLUDED

//Extension of colour from Allegro wrapper
#define COLOUR_TRANSPARENT      -1

//Screen Size
#define WIDTH                   1200
#define HEIGHT                  675

int get_text_width(const char* text);

int get_line_height(void);

#endif // COMMON_H_INCLUDED
