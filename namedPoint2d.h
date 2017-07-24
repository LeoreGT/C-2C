#ifndef __NAMEDPOINT2D_H__
#define __NAMEDPOINT2D_H__

/* class NamedPoint2D : public Point2D
{
public:
  NamedPoint2D(const char *_name = "origin");
  NamedPoint2D(double _x, double _y, const char *_name = "anonymous Point");
  NamedPoint2D(const Point2D& point, const char *_name = "anonymous Point");
  const char *GetName() const;

private:
  const char *m_name;
}; */

typedef struct NamedPoint2D
{
  Point2D     m_p2d;
  const char* m_name;
}NamedPoint2D;

void NamedPoint2D_c_(NamedPoint2D* _this, const char* _name);
void NamedPoint2D_np2d_(NamedPoint2D* _this, NamedPoint2D* _np2dOld);
void NamedPoint2D_p2d_(NamedPoint2D* _this, Point2D* _p2d);
void NamedPoint2D_d_d_c_(NamedPoint2D* _this, double _x, double _y, const char *_name);
void NamedPoint2D_p_c(NamedPoint2D* _this, Point2D* _point, const char *_name);
const char* GetName(const NamedPoint2D* _this);
void NamedPoint2D_destroy(NamedPoint2D* _this);
void NamedPoint2D_operatorMult(NamedPoint2D* _this, int _num);

#endif /* __NAMEDPOINT2D_H__ */
