#if 0
static vec3 
point_at_parameter(const Ray &r, float t)
{
    vec3 res = r.origin + t * r.direction;

    return res;
}
#endif

internal vec3
lerp(vec3 a, float t, vec3 b)
{
    vec3 res = (1 - t) * a + t * b;

    return res;
}

internal Ray
ray(vec3 origin, vec3 direction)
{
    Ray res = {};

    res.origin = origin;
    res.direction = direction;

    return res;
}