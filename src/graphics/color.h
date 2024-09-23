#ifndef COLOR_H
#define COLOR_H


typedef struct {
    int red;
    int green;
    int blue;
    int alpha;
} Color;

Color createColor(int red, int green, int blue, int alpha);
//HashMap* createColorMap();

#endif
