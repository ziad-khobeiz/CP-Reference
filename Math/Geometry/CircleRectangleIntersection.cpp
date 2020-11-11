typedef long long ll;
typedef long double ld;
const ld eps = 1e-12;
const ld pi = acos(-1);
ld dist(ld x1, ld y1, ld x2, ld y2){
  return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}
bool right(ld cx, ld cy, ld x1, ld y1, ld x2, ld y2, ld angle){
  angle = (angle * pi) / 180.0;
  ld newx = (x1 - cx) * cos(angle) - (y1 - cy) * sin(angle) + cx;
  ld newy = (x1 - cx) * sin(angle) + (y1 - cy) * cos(angle) + cy;
  if(newx > x2 || fabs(newx - x2) < eps)
  return true;
  else
  return false;
}
int main(){
  int t;
  cin >> t;
  for(int tt = 1; tt <= t; tt++){
  ld x1, y1, r;
  cin >> x1 >> y1 >> r;
  ld x2, y2, x3, y3;
  cin >> x2 >> y2 >> x3 >> y3;
  ld xi1, yi1, xi2, yi2;
  ld xin = x2, yin = y3;
  ld st = 0, en = 1e4;
  for(int i = 0; i < 100; i++){
    ld mid = (st + en) / 2;
    ld newx = xin, newy = yin - mid;
    if(fabs(dist(x1, y1, newx, newy) - r) < eps || dist(x1, y1, newx, newy) < r){
      xi1 = newx, yi1 = newy;
      st = mid;
    }
    else
      en = mid;
  }
  st = 0, en = 1e4;
  for(int i = 0; i < 100; i++){
    ld mid = (st + en) / 2;
    ld newx = xin + mid, newy = yin;
    if(fabs(dist(x1, y1, newx, newy) - r) < eps || dist(x1, y1, newx, newy) < r){
      xi2 = newx, yi2 = newy;
      st = mid;
    }
    else
      en = mid;
  }
  st = 0, en = 180;
  ld secangle = asin((dist(xi1, yi1, xi2, yi2) * 0.5) / dist(x1, y1, xi1, yi1));
  secangle = (secangle * 180.0) / pi * 2;
  ld sol = 0.5 * dist(xin, yin, xi1, yi1) * dist(xin, yin, xi2, yi2) + (pi * r * r * (secangle / 360.0) - 0.5 * r * r * sin((secangle * pi) / 180));
  cout << "Case " << tt << ": ";
  cout << fixed << setprecision(5) << sol << '\n';
}
