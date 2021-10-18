#include <iostream>
#include <time.h>
#include <math.h>
#include "main.h"
#include "Bitmap.h"

const double LOG2 = log(2);

int main (){
    // set this variable to name the output file
    char* imageFileName = (char*) "bitmapImage.bmp";

    // change these to change dimensions of output image
    height = 2160;
    width = 3840;
    image = new Bitmap(height,width,imageFileName);
    
    std::vector<COLOUR*> palette = generatePalette();
    for(int i = 0; i < height; i++) {
        for(int j = 0; j < width; j++){
            COLOUR* colour = calculateColour(palette,i,j);
            image->setPixel(colour->red,colour->green,colour->blue,i,j);
        }
    }

    image->generateBitmapImage();
    return 0;
}

COLOUR* calculateColour(std::vector<COLOUR*> palette,int i,int j) {
        //float x0 = WIDTH * j / width + X_OFFSET;
        //float y0 = HEIGHT * i / height + Y_OFFSET;
        float x0 = 2.47 * j / width - 2;
        float y0 = 2.24 * i / height - 1.12;
        double x = 0;
        double y = 0;
        double x2 = 0;
        double y2 = 0;
        double w = 0;
        int iteration = 0;
        int maxIteration = 1000;
        while (x2 + y2 <= 4 && iteration < maxIteration){
            x = x2 - y2 + x0;
            y = w - x2 - y2 + y0;
            x2 = x*x;
            y2 = y*y;
            w = (x+y) * (x+y);
            iteration++;
        }
        if(iteration >= maxIteration)
            return palette[1000];
        double c = sqrt(iteration - log(log(x2+y2))/LOG2);
        return palette[iteration%1000];
}

std::vector<COLOUR*> generatePalette() {
    std::vector<COLOUR*> palette;
    for(int i = 0; i < 1000; i++){
        palette.push_back(new COLOUR{(unsigned char)i,(unsigned char)0,(unsigned char)0});
    }
    palette.push_back(new COLOUR{0,0,0});
    return palette;
}
