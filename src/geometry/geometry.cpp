#include "geometry.h"

namespace pdelib
{
    std::ostream& operator<<(std::ostream& os, const point& pt)
    {
        os << "[ " << pt._x << ", " << pt._y << ", " << pt._z << " ]";
        return os;
    }

    bool operator==(const point& pt0, const point& pt1)
    {
        if (pt0._x == pt1._x and pt0._y == pt1._y and pt0._z == pt1._z)
        {
            return true;
        }

        int ulp = 5;

        return ((fabs(pt0._x - pt1._x) < std::numeric_limits<double>::epsilon() * fabs(pt0._x + pt1._x) * ulp or fabs(pt0._x - pt1._x) < std::numeric_limits<double>::min()) and
            (fabs(pt0._y - pt1._y) < std::numeric_limits<double>::epsilon() * fabs(pt0._y + pt1._y) * ulp or fabs(pt0._y - pt1._y) < std::numeric_limits<double>::min()) and
            (fabs(pt0._z - pt1._z) < std::numeric_limits<double>::epsilon() * fabs(pt0._z + pt1._z) * ulp or fabs(pt0._z - pt1._z) < std::numeric_limits<double>::min()));
    }

    void point::operator=(const point& pt)
    {
        this->_x = pt._x;
        this->_y = pt._y;
        this->_z = pt._z;
    }

    point point::operator+=(const point& pt)
    {
        this->_x += pt._x;
        this->_y += pt._y;
        this->_z += pt._z;
        return *this;
    }

    point point::operator-=(const point& pt)
    {
        this->_x -= pt._x;
        this->_y -= pt._y;
        this->_z -= pt._z;
        return *this;
    }

    point point::operator+(const point& rhs)
    {
        *this += rhs;
        return *this;
    }

    point point::operator-(const point& rhs)
    {
        *this -= rhs;
        return *this;
    }
} // namespace pdelib
