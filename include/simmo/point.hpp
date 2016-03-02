//
// Created by simmo on 2.03.16.
//

#ifndef SIMMOPP_POINT_HPP
#define SIMMOPP_POINT_HPP

#include "basic_vector.hpp"
#include "vector.hpp"
#include <algorithm>

namespace simmo
{

template<typename T, size_t N, typename Base = basic_vector<T, N>>
class point : public Base
{
public:
    using Base::Base;
    using Base::data;

    auto& operator +=(const vector<T, N> &vec)
    {
        std::transform(data.begin(), data.end(), vec.data.begin(), data.begin(), [](const auto &lhs, const auto &rhs)
        {
            return lhs + rhs;
        });
        return *this;
    }

    auto& operator -=(const vector<T, N> &vec)
    {
        std::transform(data.begin(), data.end(), vec.data.begin(), data.begin(), [](const auto &lhs, const auto &rhs)
        {
            return lhs - rhs;
        });
        return *this;
    }
};

template<typename T, size_t N>
point<T, N> operator +(const point<T, N> &lhs, const vector<T, N> &rhs)
{
    point<T, N> ret = lhs;
    return ret += rhs;
};

template<typename T, size_t N>
point<T, N> operator +(const vector<T, N> &lhs, const point<T, N> &rhs)
{
    point<T, N> ret = rhs;
    return ret += lhs;
};

template<typename T, size_t N>
point<T, N> operator -(const point<T, N> &lhs, const vector<T, N> &rhs)
{
    point<T, N> ret = lhs;
    return ret -= rhs;
};

template<typename T, size_t N>
vector<T, N> operator -(const point<T, N> &lhs, const point<T, N> &rhs)
{
    vector<T, N> ret;
    std::transform(lhs.data.begin(), lhs.data.end(), rhs.data.begin(), ret.data.begin(), [](const auto &lhs, const auto &rhs)
    {
        return lhs - rhs;
    });
    return ret;
};

typedef point<double, 0> point0d;
typedef point<double, 1> point1d;
typedef point<double, 2> point2d;
typedef point<double, 3> point3d;

}

#endif //SIMMOPP_POINT_HPP
