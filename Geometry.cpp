#include <bits/stdc++.h>
 
#define ll long long
#define ld long double
 
using namespace std;
 
const double PI = 3.1415926;
const double EPS = 1e-10;
 
struct Point
{
    int x, y;
    Point(int x1, int y1) {
        x = x1;
        y = y1;
    }
    double polar_angle(Point a) {
        double angle = atan2(a.y, a.x);
        if (angle < 0) angle += 2 * PI;
        return angle;
    }
};
 
struct Vector
{
    int x, y;
    Vector(Point a, Point b) {
        x = b.x - a.x;
        y = b.y - a.y;
    }
    double calc_length(Vector v)
    {
        return sqrt(v.x * v.x + v.y * v.y);
    }
    int dot_product(Vector a, Vector b)
    {
        return b.x * a.x + b.y * a.y;
    }
    int cross_product(Vector a, Vector b)
    {
        return a.x * b.y - a.y * b.x;
    }
    double triangle_square(Vector a, Vector b)
    {
        return abs(0.5 * cross_product(a, b));
    }
    double angle_between_vectors(Vector a, Vector b)
    {
        return abs(atan2(cross_product(a, b), dot_product(a, b)));
    }
    double dist_between_point_and_ray(Point c, Point start_ray, Vector ray)
    {
        Vector ac = Vector(start_ray, c);
        if (dot_product(ray, ac) >= 0)
            return abs(cross_product(ray, ac)) / calc_length(ray);
        else
            return calc_length(ac);
    }
    double dist_between_point_and_segment(Point c, Point l_seg, Point r_seg, Vector segment)
    {
        Vector ac = Vector(l_seg, c);
        Vector bc = Vector(r_seg, c);
        if (dot_product(segment, ac) >= 0) {
            if (dot_product(segment, bc) <= 0)
                return abs(cross_product(segment, ac)) / calc_length(segment);
            else
                return calc_length(bc);
        }
        else
            return calc_length(ac);
    }
    bool does_point_belong_to_ray(Vector ray, Point start_of_ray, Point a)
    {
        Vector b = Vector(start_of_ray, a);
        if (b.cross_product(b, ray) == 0) {
            if (b.dot_product(b, ray) >= 0) {
                return true;
            }
        }
        return false;
    }
    bool does_point_belong_to_segment(Vector segment, Point l_segment, Point r_segment, Point a)
    {
        Vector b = Vector(l_segment, a);
        Vector c = Vector(r_segment, a);
        if (b.cross_product(b, segment) == 0) {
            if (b.dot_product(b, segment) >= 0) {
                if (c.dot_product(c, segment) <= 0) {
                    return true;
                }
            }
        }
        return false;
    }
};
 
struct Line
{
    int a, b, c;
    Line(Point p1, Point p2)
    {
        a = p2.y - p1.y;
        b = p1.x - p2.x;
        c = -a * p1.x - b * p1.y;
    }
    Line(int a1, int b1, int c1) {
        a = a1;
        b = b1;
        c = c1;
    }
    bool does_point_belong_to_line(Point a, Line l)
    {
        if (l.a * a.x + l.b * a.y + l.c == 0) return true;
        else return false;
    }
};
 
int main()
{
    ios_base::sync_with_stdio(false);
    cout << "zdarova glebshapa" << endl;
    return 0;
}