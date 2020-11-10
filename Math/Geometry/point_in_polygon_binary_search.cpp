
bool point_in_polygon(vector<point> &pol, point pt){
    int low = 1, high = (int) pol.size() - 1, idx = -1;
    while(high >= low){
        int mid = low + high >> 1;
        if(cp(pol[mid] - pol[0], pt - pol[0]) >= 0){
            idx = mid;
            low = mid + 1;
        }
        else high = mid - 1;
    }
    if(idx == -1) return 0;
    int idx2;
    if(idx + 1 == pol.size()) idx2 = idx - 1;
    else idx2 = idx + 1;
    ld tmp_area1 = area(pol[0], pol[idx], pol[idx2]);
    ld tmp_area2 = area(pol[0], pol[idx], pt) + area(pol[0], pol[idx2], pt);
    tmp_area2 += area(pol[idx], pol[idx2], pt);
    if(fabs(tmp_area1 - tmp_area2) <= EPS) return 1;
    return 0;
}
