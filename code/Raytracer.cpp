#include <stdio.h>
#include <stdlib.h>

#include "Raytracer.h"


int main(void)
{   
    FILE *f = fopen("test.ppm", "wb");
    
    if (f)
    {
        int width = 200;
        int height = 100;
        int max = 255;
        fprintf(f, "P3\n");
        fprintf(f, "%d %d\n", width, height);
        fprintf(f, "%d\n", max);
        
        for (int y = height;
             y > 0;
             --y)
        {
            for (int x = 0;
                 x < width;
                 ++x)
            {
                v3 col = {
                    (float)x / (float)width,
                    (float)y / (float)height,
                    0.2f
                };

                int ri = (int)(col.r * 255.0f);
                int gi = (int)(col.g * 255.0f);
                int bi = (int)(col.b * 255.0f);

                fprintf(f, "%d %d %d\n", ri, gi, bi);
            }
        }

        fclose(f);
    }


    return 0;
}