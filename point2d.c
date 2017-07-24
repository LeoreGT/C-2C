#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#include "point2d.h"

/* -------------------------------------------------------- */
/* ==================== POINT2D ==================== */

/* Point2D::Point2D() : m_x(0), m_y(0) {} */

void Point2D_v_(Point2D* _p2d)
{
  _p2d->m_x = 0;
  _p2d->m_y = 0;
}

void Point2D_p2d_(Point2D* _p2d, const Point2D* _p2dOld)
{
  _p2d->m_x = _p2dOld->m_x;
  _p2d->m_y = _p2dOld->m_y;
}

/* Point2D::Point2D(double _x, double _y) : m_x(_x), m_y(_y) {} */

void Point2D_d_(Point2D* _p2d, double _x, double _y)
{
  _p2d->m_x = _x;
  _p2d->m_y = _y;
}

/* inline double Point2D::GetX() const
{
  return m_x;
} */

double GetX(const Point2D _p2d)
{
  return _p2d.m_x;
}

/* inline double Point2D::GetY() const
{
  return m_y;
} */

double GetY(const Point2D _p2d)
{
  return _p2d.m_y;
}

/* double Point2D::Distance(const Point2D& _other) const
{
  double dx = m_x - _other.m_x;
  double dy = m_y - _other.m_y;
  return sqrt(dx * dx + dy * dy);
} */
double Distance(const Point2D _p2d, const Point2D _other)
{
  double dx = _p2d.m_x - _other.m_x;
  double dy = _p2d.m_y - _other.m_y;
  return sqrt(dx * dx + dy * dy);
}

/* Point2D& Point2D::operator+=(const Point2D& _other)
{
  m_x += _other.m_x;
  m_y += _other.m_y;

  return *this;
} */

void operatorPlus(Point2D* _this, const Point2D _other)
{
  _this->m_x += _other.m_x;
  _this->m_y += _other.m_y;
}

/*Point2D& Point2D::operator*=(double _factor)
{
  m_x *= _factor;
  m_y *= _factor;

  return *this;
} */

void operatorMult(Point2D* _this, double _factor)
{
  _this->m_x *= _factor;
  _this->m_y *= _factor;
}

/* void pointless()
{
  Point2D p0;
  Point2D p1(0,10);
  printf("distance p0 --> p1 == %f\n", p0.Distance(p1));

  Point2D dxy(+4, -7);
  p1 += dxy;
  printf("%f, %f\n", p1.GetX(), p1.GetY());
  printf("now distance p0 --> p1 == %f\n", p0.Distance(p1));
} */

void pointless()
{
 Point2D p0;
 Point2D p1;
 Point2D dxy;

 Point2D_d_(&dxy, +4, -7);
 Point2D_d_(&p1, 0,10);
 Point2D_v_(&p0);
 operatorPlus(&p1, dxy);

 printf("distance p0 --> p1 == %f\n", Distance(p0, p1));
 printf("%f, %f\n", GetX(p1), GetY(p1));
 printf("now distance p0 --> p1 == %f\n", Distance(p0, p1));
}
