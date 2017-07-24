#ifndef __POINT2D_H__
#define __POINT2D_H__

/* class Point2D
{
public:
  Point2D();
  Point2D(double _x, double _y);

  double GetX() const;
  double GetY() const;
  double Distance(const Point2D& _other) const;

  Point2D &operator+=(const Point2D& _other);
  Point2D &operator*=(double _factor);

private:
  double m_x;
  double m_y;
}; */

typedef struct Point2D
{
  double m_x;
  double m_y;
}Point2D;

void   Point2D_v_(Point2D* _this);
void   Point2D_p2d_(Point2D* _this, const Point2D* _p2dOld);
void   Point2D_d_(Point2D* _this, double _x, double _y);
double GetX(const Point2D _this);
double GetY(const Point2D _this);
double Distance(const Point2D _this, const Point2D _other);
void   operatorPlus(Point2D* _this, const Point2D _other);
void   operatorMult(Point2D* _this, double _factor);
void   pointless();

#endif /* __POINT2D_H__ */
