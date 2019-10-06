struct vec3
{
    union
    {
        struct
        {
            float x, y, z;
        };
        
        struct
        {
            float r, g, b;
        };

        float E[3];
    };
};
