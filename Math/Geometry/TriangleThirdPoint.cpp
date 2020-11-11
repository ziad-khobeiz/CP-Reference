/*
*      u
*     /|\
*    / | \
*  a/  |  \b
*  /   |m  \
* /____|____\
* p  h  c-h  q
*/

int dcmp(const double &a, const double &b) {
  if (fabs(a - b) < EPS)
    return 0;
  return ((a > b) << 1) - 1;
}

int triangleThirdPoint(const point &p, const point &q, const double &a, const double &b, point &u1, point &u2) {
  point pq = vec(p, q);
  double c = length(pq);
  double arr[] = { a, b, c };
  sort(arr, arr + 3);
  if (dcmp(arr[0] + arr[1], arr[2]) < 0)
    return false;
    
  //m^2=a^2-h^2
  //m^2=b^2-(c-h)^2
  //m^2=b^2-(c^2-2ch+h^2)
  //m^2=b^2-c^2+2ch-h^2
  //a^2-h^2=b^2-c^2+2ch-h^2
  //0=b^2-c^2+2ch-h^2-a^2+h^2
  //0=b^2-c^2+2ch-a^2
  //2ch=a^2-b^2+c^2
  //h=(a^2-b^2+c^2)/2c
  
  double h = (a * a - b * b + c * c) / (2.0 * c);
  double sq=a * a - h * h;
  if(!dcmp(sq,0)) sq=0;
  double m = sqrt(sq);
  point npq = normalize(pq);
  point prp = perp(npq);
  u1 = p + (npq * h) + m * prp;
  u2 = p + (npq * h) - m * prp;
  return 1 + (dcmp(arr[0] + arr[1], arr[2]) != 0);
}
