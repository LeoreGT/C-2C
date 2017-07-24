#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#include "point2d.h"
#include "namedPoint2d.h"

/* ---------------------------------------------------------------- */
/* ==================== NAMED POINT2D ==================== */

/* NamedPoint2D::NamedPoint2D(const char *_name) : m_name(_name) {} */

void NamedPoint2D_c_(NamedPoint2D* _np2d, const char* _name)
{
  Point2D_v_(&_np2d->m_p2d);
  _np2d->m_name = strdup(_name); //is possible?
}

/* ---------------------------------------------------------------- */

void NamedPoint2D_np2d_(NamedPoint2D* _np2d, NamedPoint2D* _np2dOld)
{
  Point2D_p2d_(&_np2d->m_p2d, &_np2dOld->m_p2d);
  _np2d->m_name = strdup(_np2dOld->m_name);
}

/* ---------------------------------------------------------------- */

void NamedPoint2D_p2d_(NamedPoint2D* _np2d, Point2D* _p2d)
{
  Point2D_p2d_(&_np2d->m_p2d, _p2d);
  _np2d->m_name = strdup("");
}

/* ---------------------------------------------------------------- */

/* NamedPoint2D::NamedPoint2D(double _x, double _y, const char *_name) : m_name(_name), Point2D(_x, _y) {} */

void NamedPoint2D_d_d_c_(NamedPoint2D* _np2d, double _x, double _y, const char *_name)
{
  Point2D_d_(&_np2d->m_p2d, _x, _y);
  _np2d->m_name = strdup(_name);
}

/* ---------------------------------------------------------------- */

/* NamedPoint2D::NamedPoint2D(const Point2D& _point, const char *_name) : m_name(_name), Point2D(_point) {} */

void NamedPoint2D_p_c(NamedPoint2D* _np2d, Point2D* _point, const char *_name)
{
  Point2D_p2d_(&_np2d->m_p2d, _point);
  _np2d->m_name = strdup(_name);
}

/* ---------------------------------------------------------------- */

/* const char* NamedPoint2D::GetName() const
{
  return m_name;
} */

const char* GetName(const NamedPoint2D* _np2d)
{
  return _np2d->m_name;
}

/* ---------------------------------------------------------------- */

void NamedPoint2D_destroy(NamedPoint2D* _np2d)
{
}

/* ---------------------------------------------------------------- */

void NamedPoint2D_operatorMult(NamedPoint2D* _np2d, int _num)
{
  _np2d->m_p2d.m_x *= _num;
  _np2d->m_p2d.m_y *= _num;
}
