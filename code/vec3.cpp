inline vec3
v3(float x, float y, float z)
{
    vec3 res = {x, y, z};

    return res;
}

inline float 
squared_length(vec3 v)
{
    float res = (v.x * v.x + 
                 v.y * v.y + 
                 v.z * v.z);
    return res;
}

inline float 
length(vec3 v)
{
    float res = squared_length(v);
    res = sqrtf(res);

    return res;
}

inline vec3 
unit(vec3 v)
{
    vec3 res = v;

    float len = length(res);
    assert(len != 0.0f);

    res.x /= len;
    res.y /= len;
    res.z /= len;

    return res;
}

inline float
dot(vec3 a, vec3 b)
{
    float res = a.x * b.x + a.y * b.y + a.z * b.z;

    return res;
}

inline vec3
cross(vec3 a, vec3 b)
{
    vec3 res = {};

    res.x = a.y * b.z - a.z * b.y;
    res.y = a.z * b.x - a.x * b.z;
    res.z = a.x * b.y - a.y * b.x;

    return res;
}


inline vec3&
operator+(vec3 &v)
{
    return v;
}

inline vec3&
operator-(vec3 &v)
{
    v.x = -v.x;
    v.y = -v.y;
    v.z = -v.z;

    return v;
}


inline vec3 
operator+(vec3 lhs, vec3 rhs)
{
    vec3 res = {};

    res.x = lhs.x + rhs.x;
    res.y = lhs.y + rhs.y;
    res.z = lhs.z + rhs.z;

    return res;
}

inline vec3 
operator-(vec3 lhs, vec3 rhs)
{
    vec3 res = {};

    res.x = lhs.x - rhs.x;
    res.y = lhs.y - rhs.y;
    res.z = lhs.z - rhs.z;

    return res;
}

inline vec3 
operator*(vec3 lhs, vec3 rhs)
{
    vec3 res = {};

    res.x = lhs.x * rhs.x;
    res.y = lhs.y * rhs.y;
    res.z = lhs.z * rhs.z;

    return res;
}

inline vec3 
operator/(vec3 lhs, vec3 rhs)
{
    assert(rhs.x != 0.0f &&
           rhs.y != 0.0f &&
           rhs.z != 0.0f);

    vec3 res = {};

    res.x = lhs.x / rhs.x;
    res.y = lhs.y / rhs.y;
    res.z = lhs.z / rhs.z;

    return res;
}


inline vec3 
operator*(vec3 v, float n)
{
    vec3 res = {};

    res.x = v.x * n;
    res.y = v.y * n;
    res.z = v.z * n;

    return res;
}

inline vec3 
operator*(float n, vec3 v)
{
    vec3 res = v * n;

    return res;
}

inline vec3 
operator/(vec3 v, float n)
{
    assert(n != 0.0f);

    vec3 res = {};

    res.x = v.x / n;
    res.y = v.y / n;
    res.z = v.z / n;

    return res;
}

inline vec3 
operator/(float n, vec3 v)
{
    vec3 res = v / n;

    return res;
}


inline vec3& 
operator+=(vec3 &lhs, vec3 rhs)
{
    lhs = lhs + rhs;

    return lhs;
}

inline vec3& 
operator-=(vec3 &lhs, vec3 rhs)
{
    lhs = lhs - rhs;

    return lhs;
}

inline vec3& 
operator*=(vec3 &lhs, vec3 rhs)
{
    lhs = lhs * rhs;

    return lhs;
}

inline vec3& 
operator/=(vec3 &lhs, vec3 rhs)
{
    lhs = lhs / rhs;

    return lhs;
}

inline vec3&
operator*=(vec3 &lhs, float n)
{
    lhs = lhs * n;

    return lhs;
}

inline vec3&
operator/=(vec3 &lhs, float n)
{
    lhs = lhs / n;

    return lhs;
}
