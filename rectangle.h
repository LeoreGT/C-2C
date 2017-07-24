#ifndef __RECTANGLE_H__
#define __RECTANGLE_H__

/* class Rectangle
{
public:
  Rectangle(const Point2D& _a, const Point2D& _b, const char *_name = "anonymous Rectangle");

  const char *GetName() const;
  double CalcArea() const;

private:
  NamedPoint2D m_a;
  Point2D m_b;
  static const int s_curvature = 1;
}; */

typedef struct Rectangle
{
  NamedPoint2D m_a;
  Point2D      m_b;
}Rectangle;

void Rectangle_p2d_p2d_c(Rectangle* _this, Point2D* _a, const Point2D* _b, const char *_name);
void Rectangle_p2d_p2d(Rectangle* _this, const Point2D* _a, const Point2D* _b);
const char* GetName_Rec(const Rectangle* _this);
double CalcArea(const Rectangle* _this);
void dog();
void area();
void Rectangle_destroy(Rectangle* _this);

#endif /* __RECTANGLE_ */
