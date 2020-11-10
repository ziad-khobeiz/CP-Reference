#include <iostream>
#include <cmath>
#include <complex>
#include <bits/stdc++.h>
using namespace std;

const double PI  = acos(-1.0);

typedef complex<double> point;

#define X real()
#define Y imag()
#define angle(a)                (atan2((a).imag(), (a).real()))
#define vec(a,b)                ((b)-(a))
#define same(p1,p2)             (dp(vec(p1,p2),vec(p1,p2)) < EPS)
#define dp(a,b)                 ( (conj(a)*(b)).real() )	// a*b cos(T), if zero -> prep
#define cp(a,b)                 ( (conj(a)*(b)).imag() )	// a*b sin(T), if zero -> parllel
#define length(a)               (hypot((a).imag(), (a).real()))
#define normalize(a)            (a)/length(a)
//#define polar(r,ang)            ((r)*exp(point(0,ang)))  ==> Already added in c++11
#define rotateO(p,ang)          ((p)*exp(point(0,ang)))
#define rotateA(p,ang,about)  (rotateO(vec(about,p),ang)+about)
#define reflectO(v,m)  (conj((v)/(m))*(m))

point reflect(point p, point p0, point p1) {
    point z = p-p0, w = p1-p0;
    return conj(z/w)*w + p0; // Refelect point p1 around p0p1
}

double fixAngle(double A) {
	return A > 1 ? 1 : (A < -1 ? -1 : A);
}

// return min angle: aOb / bOa
// dp(v1, v2) = |v1|*|v2|*cos(theta)
double angleO(point a, point O, point b) {
  point v1(a - O), v2(b - O);
  return acos( fixAngle ( dp(v1, v2) / length(v1) / length(v2) ) );
}

double getAng(point &a, point &b, point &c) // find angle abc, anticlock bc to ba
{
    double ang = angle( vec(b, c)) - angle( vec(b, a));
    if(dcmp(ang, 0) < 0)
    	ang+=2*PI;
    return ang;
}

int main() {

	/*

	complex<double> num1(2, 3);	// 2 + 3i

	std::cout << num1.real() << "+" << num1.imag() << "i\n";	// 2 + 3i

	complex<double> num2(1, 1);

	cout << "Modulus = " << abs(num2) << "\n";			// r = 1.41421
	cout << "Argument = " << arg(num2) << "\n";			// theta radian = 0.785398
	cout << "Angle = " << arg(num2) * 180 / PI << "\n";	// theta degree = 45
	cout << "Norm = " << norm(num2) << "\n";			// 2 (1*1 + 1*1)

	complex<double> num3 = std::polar(1.41421, 0.785398);
	cout << "(x+iy) from polar are: " << num3 << "\n";	// (0.999998,0.999997)

	complex<double> zero;
	complex<double> x_part = 15;
	cout << x_part << "\n";				// (15,0)

	complex<double> a(1, 2);
	complex<double> b(3, 4);

	cout<<a+b<<"\n";	// (4,6)
	cout<<a-b<<"\n";	// (-2,-2)
	cout<<a*b<<"\n";	// (-5,10)
	cout<<b*2.0<<"\n";	// (6,8)
	cout<<b/2.0<<"\n";	// (1.5,2)


    cout << fixed << std::setprecision(1);

	complex<double> i = -1;
	cout<<sqrt(i)<<"\n";		// (0,1)

	complex<double> c(2, 3);
	cout<<conj(c)<<"\n";		// (2,-3)
	cout<<pow(c, 2)<<"\n";		// (-5,12)

	complex<double> i1 (0, -1);
	cout<<exp(i1 * PI)<<"\n";	// (-1, 0)



	 std::cout << std::fixed << std::setprecision(1);

	 std::complex<double> z1 = 1i * 1i;     // imaginary unit squared
	 std::cout << "i * i = " << z1 << '\n';

	 std::complex<double> z2 = std::pow(1i, 2); // imaginary unit squared
	 std::cout << "pow(i, 2) = " << z2 << '\n';

	 double PI = std::acos(-1);
	 std::complex<double> z3 = std::exp(1i * PI); // Euler's formula
	 std::cout << "exp(i * pi) = " << z3 << '\n';

	 std::complex<double> z4 = 1. + 2i, z5 = 1. - 2i; // conjugates
	 std::cout << "(1+2i)*(1-2i) = " << z4*z5 << '\n';
	 */

	point a (10, 10);
	point m1 (1, 0);
	point m2 (0, 1);

	cout<<a<<" reflected around "<<m1<<" = "<<reflectO(a, m1)<<"\n";
	// 10,10) reflected around (1,0) = (10,-10)

	cout<<a<<" reflected around "<<m2<<" = "<<reflectO(a, m2)<<"\n";
	// (10,10) reflected around (0,1) = (-10,10)

	return 0;
}

=====================================================
lines:

bool isCollinear(point a, point b, point c) {	
	return fabs( cp(b-a, c-a) ) < EPS;	
} 

bool isPointOnRay(point p0, point p1, point p2) {
    if(length(p2-p0) < EPS) return true;
    return same( normalize(p1-p0), normalize(p2-p0) );
}

bool isPointOnRay(point a, point b, point c) {	// not tested?
    if(!isCollinear(a, b, c))
    	return false;
    return dcmp(dp(b-a, c-a), 0) == 1;
}

bool isPointOnSegment(point a, point b, point c) {
	return isPointOnRay(a, b, c) && isPointOnRay(b, a, c);
}

bool isPointOnSegment(point a, point b, point c) {
	double acb = length(a-b), ac = length(a-c), cb = length(b-c);
	return dcmp(acb-(ac+cb), 0) == 0;
}





double distToLine( point p0, point p1, point p2 ) {
	return fabs(cp(p1-p0, p2-p0)/length(p0-p1)); // area = 0.5*b*h
}




//distance from point p2 to segment p0-p1
double distToSegment( point p0, point p1, point p2 ) {
	double d1, d2;
	point v1 = p1-p0, v2 = p2-p0;
	if( (d1 = dp(v1, v2) ) <= 0)	return length(p2-p0);
	if( (d2 = dp(v1, v1) ) <= d1)	return length(p2-p1);
	double t = d1/d2;
	return length(p2 - (p0 + v1*t) );
}

===========================================================================================

segment intersection and ccw:


bool intersectSegments(point a, point b, point c, point d, point & intersect) {
  double d1 = cp(a - b, d - c), d2 = cp(a - c, d - c), d3 = cp(a - b, a - c);
  if (fabs(d1) < EPS)
    return false;  // Parllel || identical

  double t1 = d2 / d1, t2 = d3 / d1;
  intersect = a + (b - a) * t1;

  if (t1 < -EPS || t2 < -EPS || t2 > 1 + EPS)
    return false;  //e.g ab is ray, cd is segment ... change to whatever
  return true;
}


// Where is P2 relative to segment p0-p1?
// ccw = +1 => angle > 0 or collinear after p1
// cw = -1 => angle < 0 or collinear after p0
// Undefined = 0 => Collinar in range [a, b]. Be careful here
int ccw(point a, point b, point c) {
  point v1(b - a), v2(c - a);
  double t = cp(v1, v2);

  if (t > +EPS)
	return +1;
  if (t < -EPS)
	return -1;
  if (v1.X * v2.X < -EPS || v1.Y * v2.Y < -EPS)
	return -1;
  if (norm(v1) < norm(v2) - EPS)
	return +1;
  return 0;
}

  void ccw_testing() {
    point a(0, 0), b(10, 0);

    cout<<ccw(a, b, point(20, 10))<<"\n";     // +1 => c is ccw for a-b
    cout<<ccw(a, b, point(20, 0))<<"\n";      // +1 => Collinear after b

    cout<<ccw(a, b, point(20, -10))<<"\n";    // -1 => c is cw for a-b
    cout<<ccw(a, b, point(-20, 0))<<"\n";     // -1 => c is Collinear before a

    cout<<ccw(a, b, a)<<"\n";               // 0 => Collinear at a
    cout<<ccw(a, b, b)<<"\n";               // 0 => Collinear at b
    cout<<ccw(a, b, (a+b)/2.0)<<"\n";       // 0 => Collinear between a-b

    // one can design ccw to behave little differently
    // e.g. consider Collinear at b = +1 and at a = -1
  }

  bool intersect(point p1, point p2, point p3, point p4) {
    // special case handling if a segment is just a point
    bool x = (p1 == p2), y = (p3==p4);
    if(x && y)  return p1 == p3;
    if(x)   return ccw(p3, p4, p1) == 0;
    if(y)   return ccw(p1, p2, p3) == 0;

    return  ccw(p1, p2, p3) * ccw(p1, p2, p4) <= 0  &&
        ccw(p3, p4, p1) * ccw(p3, p4, p2) <= 0;
  }

int main() {
  ccw_testing();

  return 0;
}

=========================================================================================
Circles: 





// 2 points has infinite circles
// Find circle passes with 3 points, some times, there is no circle! (in case colinear)
// Draw two perpendicular lines and intersect them
// may be see https://www.topcoder.com/community/data-science/data-science-tutorials/geometry-concepts-line-intersection-and-its-applications/
pair<double, point> findCircle(point a, point b, point c) {
	//create median, vector, its prependicular
	point m1 = (b+a)*0.5, v1 = b-a, pv1 = point(v1.Y, -v1.X);
	point m2 = (b+c)*0.5, v2 = b-c, pv2 = point(v2.Y, -v2.X);
	point end1 = m1+pv1, end2 = m2+pv2, center;
	intersectSegments(m1, end1, m2, end2, center);
	return make_pair( length(a-center), center );  
}



// If line intersect cirlce at point p, and p = p0 + t(p1-p0)
// Then (p-c)(p-c) = r^2 substitute p and rearrange
// (p1-p0)(p1-p0)t^2 + 2(p1-p0)(p0-C)t + (p0-C)(p0-C) = r*r; -> Quadratic
vector<point> intersectLineCircle(point p0, point p1, point C, double r) {
    double a = dp(p1-p0, p1-p0), b = 2*dp(p1-p0, p0-C), 
           c = dp(p0-C, p0-C) - r*r;
    double f = b*b - 4*a*c;

    vector<point> v;
    if( dcmp(f, 0) >= 0) {
	    if( dcmp(f, 0) == 0)	f = 0;
	    double t1 =(-b + sqrt(f))/(2*a);
	    double t2 =(-b - sqrt(f))/(2*a);
	    v.push_back( p0 + t1*(p1-p0) );
	    if( dcmp(f, 0) != 0)	v.push_back( p0 + t2*(p1-p0) );
    }
    return v;
}

vector<point> intersectCircleCircle(point c1, double r1, point c2, double r2) {
  // Handle infinity case first: same center/radius and r > 0
  if (same(c1, c2) && dcmp(r1, r2) == 0 && dcmp(r1, 0) > 0)
    return vector<point>(3, c1);    // infinity 2 same circles (not points)

  // Compute 2 intersection case and handle 0, 1, 2 cases
  double ang1 = angle(c2 - c1), ang2 = getAngle_A_abc(r2, r1, length(c2 - c1));

  if(::isnan(ang2)) // if r1 or d = 0 => nan in getAngle_A_abc (/0)
    ang2 = 0; // fix corruption

  vector<point> v(1, polar(r1, ang1 + ang2) + c1);

  // if point NOT on the 2 circles = no intersection
  if(dcmp(dp(v[0]-c1, v[0]-c1), r1*r1) != 0 ||
      dcmp(dp(v[0]-c2, v[0]-c2), r2*r2) != 0 )
    return vector<point>();

  v.push_back(polar(r1, ang1 - ang2) + c1);
  if(same(v[0], v[1]))  // if same, then 1 intersection only
    v.pop_back();
  return v;
}

int intersectCircleCircle_TEST() {
  print(intersectCircleCircle(point(-1.5,-1.5), 0.5, point(1.5,1.5), 0.5));   // no intersection far

  print(intersectCircleCircle(point(0, 0), 5, point(9, 0), 1));   // no intersection far
  print(intersectCircleCircle(point(0, 0), 5, point(0, 0), 1));   // no intersection nested same center
  print(intersectCircleCircle(point(0, 0), 5, point(1, 0), 1));   // no intersection nested

  print(intersectCircleCircle(point(0, 0), 5, point(6, 0), 1));   // 1 intersection: (5,0) external
  print(intersectCircleCircle(point(0, 0), 5, point(4, 0), 1));   // 1 intersection: (5,0) internal
  print(intersectCircleCircle(point(0, 0), 5, point(5, 0), 0));   // 1 intersection: (5,0) point on circle
  print(intersectCircleCircle(point(5, 0), 0, point(5, 0), 0));   // 1 intersection: (5,0) 2 same points

  print(intersectCircleCircle(point(0, 0), 5, point(5, 0), 1));   // 2 intersection: ~(5,1) (5,-1)

  print(intersectCircleCircle(point(0, 0), 5, point(0, 0), 5));   // infinity intersections

  // Full correct testing should consider also swapping these parameters

  return 0;
}




const int MAX = 100000+9;
point pnts[MAX], r[3], cen;
double rad;
int ps, rs;	// ps = n, rs = 0, initially

// Pre condition
// random_shuffle(pnts, pnts+ps);		rs = 0;
void MEC() {
	if(ps == 0 && rs == 2) {
		cen = (r[0]+r[1])/2.0;
		rad = length(r[0]-cen);
	}
	else if(rs == 3) {
		pair<double, point> p = findCircle(r[0], r[1], r[2]);
		cen = p.second;
		rad = p.first;
	}
	else if(ps == 0) {
		cen = r[0];	// sometime be garbage, but will not affect
		rad = 0;
	}
	else {
		ps--;
		MEC();

		if(length(pnts[ps]-cen) > rad) {
			r[rs++] = pnts[ps];
			MEC();
			rs--;
		}

		ps++;
	}
}
