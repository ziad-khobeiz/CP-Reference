#include <bits/stdc++.h>
using namespace std;
const int N = 3e8 + 1;
const long double PI = acos(-1), EPS = 1e-11;
long double areaOfIntersection(long double x0, long double y0, long double r0, long double x1, long double y1, long double r1) {
  long double rr0 = r0 * r0;
  long double rr1 = r1 * r1;
  long double d = sqrt((x1 - x0) * (x1 - x0) + (y1 - y0) * (y1 - y0));
  // Circles do not overlap
  if (d + EPS >= r1 + r0) {
    return 0;
  }
  // Circle1 is completely inside circle0
  else if (d <= fabs(r0 - r1) + EPS && r0 + EPS >= r1) {
  // Return area of circle1
    return PI * rr1;
  }
  // Circle0 is completely inside circle1
  else if (d <= fabs(r0 - r1) + EPS && r0 <= r1 + EPS) {
  // Return area of circle0
    return PI * rr0;
  }
  // Circles partially overlapIn
  else {
    long double phi = (acos((rr0 + (d * d) - rr1) / (2.0 * r0 * d))) * 2.0;
    long double theta = (acos((rr1 + (d * d) - rr0) / (2.0 * r1 * d))) * 2.0;
    long double area1 = 0.5 * theta * rr1 - 0.5 * rr1 * sin(theta);
    long double area2 = 0.5 * phi * rr0 - 0.5 * rr0 * sin(phi);
    // Return area of intersection
    return area1 + area2;
  }
}
int main() {
int t;
scanf("%d", &t);
for (int test = 1; test <= t; ++test) {
  int x0, y0, r0, x1, y1, r1;
  scanf("%d %d %d %d %d %d", &x0, &y0, &r0, &x1, &y1, &r1);
  printf("Case #%d: %.8lf\n", test, (double) (PI * r0 * r0 - areaOfIntersection(x0, y0, r0, x1, y1, r1)));
}
return 0;
