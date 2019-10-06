#include "Raytracer.h"

#include "vec3.cpp"
#include "ray.cpp"

internal vec3 
color(Ray r)
{
    vec3 unit_direction = unit(r.direction);
    float t = 0.5f * (unit_direction.y + 1.0f);

    vec3 white = {1.0f, 1.0f, 1.0f};
    vec3 sky_blue = {0.5f, 0.7f, 1.0f};
    vec3 res = lerp(white, t, sky_blue);

    return res;
}


int main(void)
{   
    FILE *f = fopen("output.ppm", "wb");
    
    if (f)
    {
        int width = 200;
        int height = 100;
        int max = 255;
        fprintf(f, "P3\n");
        fprintf(f, "%d %d\n", width, height);
        fprintf(f, "%d\n", max);

        vec3 lower_left_corner = {-2, -1, -1};
        vec3 horizontal = {4, 0, 0};
        vec3 vertical = {0, 2, 0};
        vec3 origin = {0, 0, 0};
        
        for (int y = height;
             y > 0;
             --y)
        {
            for (int x = 0;
                 x < width;
                 ++x)
            {
                float u = (float)x / (float)width;
                float v = (float)y / (float)height;
                Ray r = ray(origin, lower_left_corner + u * horizontal + v * vertical);
                vec3 col = color(r);
                
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