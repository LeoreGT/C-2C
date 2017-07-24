#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#include "point2d.h"
#include "namedPoint2d.h"
#include "rectangle.h"

/* ---------------------------------------------------------------- */
/* ==================== RECTANGLE ==================== */

/* Rectangle::Rectangle(const Point2D& _a, const Point2D& _b, const char *_name) : m_a(_a, _name), m_b(_b) {} */

void Rectangle_p2d_p2d_c(Rectangle* _rec, Point2D* _a, const Point2D* _b, const char *_name)
{
  NamedPoint2D_p_c(&_rec->m_a, _a, _name);
  Point2D_p2d_(&_rec->m_b, _b);
}

void Rectangle_p2d_p2d(Rectangle* _rec, const Point2D* _a, const Point2D* _b)
{
  Point2D_p2d_(&_rec->m_a.m_p2d, _a);
  Point2D_p2d_(&_rec->m_b, _b);
}

/* const char *Rectangle::GetName() const
{
  return m_a.GetName();
} */

const char* GetName_Rec(const Rectangle* _rec)
{
  return GetName(&_rec->m_a);
}

/* double Rectangle::CalcArea() const
{
  Point2D p1(m_a.GetX(), m_b.GetY());
  double sideA = m_a.Distance(p1);
  double sideB = m_a.Distance(Point2D(m_b.GetX(), m_a.GetY()));
  return sideA * sideB * s_curvature;
}*/

double CalcArea(const Rectangle* _rec)
{
  static const int s_curvature = 1;
  Point2D p1, p2;
  Point2D_d_(&p2, GetX(_rec->m_b), GetY(_rec->m_a.m_p2d));
  Point2D_d_(&p1, GetX(_rec->m_a.m_p2d), GetY(_rec->m_b));
  double sideA = Distance(_rec->m_a.m_p2d, p1);
  double sideB = Distance(_rec->m_a.m_p2d, p2);
  return sideA * sideB * s_curvature;
}

void Rectangle_destroy(Rectangle* _this)
{
  NamedPoint2D_destroy(&_this->m_a);
}

/* ---------------------------------------------------------------- */

/* void dog()
{
  NamedPoint2D home(5,7, "home");
  Point2D point(home);
  NamedPoint2D dog(point);

  dog *= 2;
  printf("Distance from %s to %s is %f\n", home.GetName(), dog.GetName(), home.Distance(dog));
} */

void dog()
{
  NamedPoint2D home;
  NamedPoint2D dog;
  Point2D point;

  NamedPoint2D_d_d_c_(&home, 5, 7, "home");
  Point2D_p2d_(&point, &home.m_p2d);
  NamedPoint2D_p_c(&dog, &point, "second");

  NamedPoint2D_operatorMult(&dog, 2);
  printf("Distance from %s to %s is %f\n", GetName(&home), GetName(&dog), Distance(home.m_p2d, dog.m_p2d));
}


/* ---------------------------------------------------------------- */

/* void area()
{
  Point2D p0;
  Point2D p1(12,12);
  Rectangle r(p0, p1);

  printf("The area of %s is %f\n", r.GetName(), r.CalcArea());
  printf("rectangle size %zu", sizeof(r));
} */

void area()
{
  Point2D p0, p1;
  Rectangle r;
  Point2D_v_(&p0);
  Point2D_d_(&p1, 12,12);
  Rectangle_p2d_p2d(&r, &p0, &p1);

  printf("rectangle size %zu", sizeof(r));
  //printf("The area of %s is %f\n", GetName_Rec(&r), CalcArea(&r));

  Rectangle_destroy(&r);
}

/* ---------------------------------------------------------------- */
