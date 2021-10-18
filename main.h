#include <vector>
#define WIDTH 2.47
#define HEIGHT 2.24
#define X_OFFSET -2
#define Y_OFFSET -1.12
class Bitmap;

typedef struct COLOUR{
    unsigned char red;
    unsigned char green;
    unsigned char blue;
} colour;

Bitmap *image;
int height, width;

void draw();
std::vector<COLOUR*> generatePalette();
COLOUR* calculateColour(std::vector<COLOUR*>,int,int);
