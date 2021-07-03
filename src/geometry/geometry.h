#pragma once

#include <fstream>
#include <vector>
#include <cmath>
#include <limits>

using std::vector;

namespace pdelib
{
    /// \brief A class to define a point
    class point
    {
    private:
        double _x, _y, _z;
    public:
        /// \brief Constructor: Setting all coordinates of the point to zero when constructed
        point() :_x(0), _y(0), _z(0) {}

        /// \brief Constructor: Constructing the point object by setting the coordinates.
        /// \param x x coordinate
        /// \param y y coordinate
        /// \param z z coordinate
        point(double x, double y, double z) :_x(x), _y(y), _z(z) {}

        /// \brief operator: << 
        /// prints the point like [ x, y, z ]
        friend std::ostream& operator<<(std::ostream& os, const point& pt);

        /// \brief operator: == and !=
        /// overloading the comparison operator
        friend bool operator ==(const point& pt0, const point& pt1);
        friend bool operator !=(const point& pt0, const point& pt1) { return !(pt0 == pt1); }

        /// \brief operator: assignment (=)
        /// overloading the assignment operator
        void operator=(const point& pt);

        /// \brief operator: += and -=
        /// overloading arithmetic operators
        point operator+=(const point& pt);
        point operator-=(const point& pt);
        point operator+(const point& rhs);
        point operator-(const point& rhs);

        /// \brief Get the x,y, and z coordinates of the point in a vector.
        vector<double> getCoordinates() { return { _x, _y, _z }; }
    };

    /// \brief A class to define a line
    class line
    {
    public:
        /// \brief Constractors
        line() {}
        line(const point& p0, const point& p1) : _startPt(p0), _endPt(p1) {}

        point getStartPoint() {return _startPt;}
        point getEndPoint() {return _endPt;}
    private:
        point _startPt, _endPt;
    };
} // namespace pdelib
