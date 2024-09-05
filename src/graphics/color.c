#include "color.h"

Color createColor(int red, int green, int blue, int alpha){

    Color color;
    color.red = red;
    color.green = green;
    color.blue = blue;
    color.alpha = alpha;

    return color;

}

HashMap* createColorMap(){

    HashMap* map = createHashMap();

    Color red = createColor(255, 0, 0, 255); 
    Color orange = createColor(255, 128, 0, 255); 
    Color yellow = createColor(255, 255, 0, 255);
    Color green = createColor(0, 255, 0, 255);
    Color blue = createColor(0, 0, 255, 255);
    Color purple = createColor(127, 0, 255, 255);
    Color pink = createColor(255, 0, 255, 255);
    Color grey = createColor(128, 128, 128, 255);
    Color white = createColor(255, 255, 255, 255);
    Color black = createColor(0, 0, 0, 255);
    
    put(map, "RED", &red);
    put(map, "ORANGE", &orange);
    put(map, "YELLOW", &yellow);
    put(map, "GREEN", &green);
    put(map, "BLUE", &blue);
    put(map, "PURPLE", &purple);
    put(map, "PINK", &pink);
    put(map, "GREY", &grey);
    put(map, "WHITE", &white);
    put(map, "BLACK", &black);

    return map;

}
