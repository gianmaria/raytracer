#pragma once

#include <assert.h>
#include <math.h>

struct v3
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

        float E[3] = {0};
    };
};

inline float 
squared_length(const v3 &v)
{
    float res = (v.x * v.x + 
                 v.y * v.y + 
                 v.z * v.z);
    return res;
}

inline float 
length(const v3 &v)
{
    float res = squared_length(v);
    res = sqrtf(res);

    return res;
}

inline v3 
unit(const v3 &v)
{
    v3 res = v;

    float len = length(res);
    assert(len != 0.0f);

    res.x /= len;
    res.y /= len;
    res.z /= len;

    return res;
}

inline float
dot(const v3 &a, const v3 &b)
{
    float res = a.x * b.x + a.y * b.y + a.z * b.z;

    return res;
}

inline v3
cross(const v3 &a, const v3 &b)
{
    v3 res;

    res.x = a.y * b.z - a.z * b.y;
    res.y = a.z * b.x - a.x * b.z;
    res.z = a.x * b.y - a.y * b.x;

    return res;
}


inline v3&
operator+(v3 &v)
{
    return v;
}

inline v3&
operator-(v3 &v)
{
    v.x = -v.x;
    v.y = -v.y;
    v.z = -v.z;
    
    return v;
}


inline v3 
operator+(const v3 &lhs, const v3 &rhs)
{
    v3 res;

    res.x = lhs.x + rhs.x;
    res.y = lhs.y + rhs.y;
    res.z = lhs.z + rhs.z;

    return res;
}

inline v3 
operator-(const v3 &lhs, const v3 &rhs)
{
    v3 res;

    res.x = lhs.x - rhs.x;
    res.y = lhs.y - rhs.y;
    res.z = lhs.z - rhs.z;

    return res;
}

inline v3 
operator*(const v3 &lhs, const v3 &rhs)
{
    v3 res;

    res.x = lhs.x * rhs.x;
    res.y = lhs.y * rhs.y;
    res.z = lhs.z * rhs.z;

    return res;
}

inline v3 
operator/(const v3 &lhs, const v3 &rhs)
{
    assert(rhs.x != 0.0f &&
           rhs.y != 0.0f &&
           rhs.z != 0.0f);

    v3 res;

    res.x = lhs.x / rhs.x;
    res.y = lhs.y / rhs.y;
    res.z = lhs.z / rhs.z;

    return res;
}


inline v3 
operator*(const v3 &v, float n)
{
    v3 res;

    res.x = v.x * n;
    res.y = v.y * n;
    res.z = v.z * n;

    return res;
}

inline v3 
operator*(float n, const v3 &v)
{
    v3 res = v * n;

    return res;
}

inline v3 
operator/(const v3& v, float n)
{
    assert(n != 0.0f);

    v3 res;

    res.x = v.x / n;
    res.y = v.y / n;
    res.z = v.z / n;

    return res;
}

inline v3 
operator/(float n, const v3 &v)
{
    v3 res = v / n;

    return res;
}


inline v3& 
operator+=(v3 &lhs, const v3 &rhs)
{
    lhs = lhs + rhs;

    return lhs;
}

inline v3& 
operator-=(v3 &lhs, const v3 &rhs)
{
    lhs = lhs - rhs;

    return lhs;
}

inline v3& 
operator*=(v3 &lhs, const v3 &rhs)
{
    lhs = lhs * rhs;

    return lhs;
}

inline v3& 
operator/=(v3 &lhs, const v3 &rhs)
{
    lhs = lhs / rhs;

    return lhs;
}

inline v3&
operator*=(v3 &lhs, float n)
{
    lhs = lhs * n;

    return lhs;
}

inline v3&
operator/=(v3 &lhs, float n)
{
    lhs = lhs / n;

    return lhs;
}