#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>
#define STB_IMAGE_IMPLEMENTATION
#include "stb/stb_image.h"
#define STB_IMAGE__WRITE_IMPLEMENTATION
#include "stb/stb_image_write.h"

using namespace std;

int main(int argc, char** argv) {

    int imageWidth, imageHeight, numChannels;
    unsigned char* image = stbi_load("C:/Users/.../image.bmp", &imageWidth, &imageHeight, &numChannels, 0);
    if(image == NULL)
    {
        cout<<"Error: Image didn't load"<<endl;
    }

    size_t img_size = imageWidth * imageHeight * numChannels;
    int gray_channels = numChannels == 4 ? 2 : 1;
    size_t gray_img_size = imageWidth * imageHeight * gray_channels;

    unsigned char* gray_img = (unsigned char*) malloc(gray_img_size);
    if(gray_img==NULL)
    {
        cout<<"Error: Cannot allocate memory for gray image"<<endl;
    }

    for(unsigned char* p = image, *pg = gray_img; p != image + img_size; p += numChannels, pg += gray_channels)
    {
        *pg = (uint8_t)((*p + (*p+1) + *(p+2))/3.0);
        if (numChannels==4)
        {
            *(pg+1) = *(p+3);
        }
    }
    stbi_write_bmp("imageBMP.bmp", imageWidth, imageHeight, gray_channels, gray_img);
    //stbi_write_jpg("imageJPG.jpg", imageWidth, imageHeight, gray_channels, gray_img, 100);

    stbi_image_free(image);
    free(gray_img);

    return 0;
}
