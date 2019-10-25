#include <bits/stdc++.h>
#define db(x) cerr << #x << " = " << x << endl
#define db2(x, y) cerr << #x << " = " << x << ", " << #y << " = " << y << endl
#define db3(x, y, z) cerr << #x << " = " << x << ", " << #y << " = " << y << ", z = " << z << endl
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;

const ld INF = 1e100;
const ld EPS = 1e-12;

bool eq(ld a, ld b) {
    return abs(a - b) < EPS;
}

struct Pt {
    ld x, y;
    Pt() {}
    Pt(ld x, ld y) : x(x), y(y) {}
    Pt(const Pt &p) : x(p.x), y(p.y) {}
    Pt operator+(const Pt &p) const { return {x + p.x, y + p.y}; }
    Pt operator-(const Pt &p) const { return {x - p.x, y - p.y}; }
    Pt operator*(const ld c) const { return {x * c, y * c}; }
    Pt operator/(const ld c) const { return {x / c, y / c}; }
    bool operator==(const Pt &p) const { return eq(x, p.x) && eq(y, p.y); }
    bool operator!=(const Pt &p) const { return !(*this == p); }
    bool operator<(const Pt &p) const { return eq(x, p.x) ? y < p.y - EPS : x < p.x; }
    Pt rot() { return {-y, x}; }
    ld abs() const { return hypotl(x, y); }
};

ld dot(Pt p, Pt q) {
    return p.x * q.x + p.y * q.y;
}
ld cross(Pt p, Pt q) {
    return p.x * q.y - p.y * q.x;
}
ld dist2(Pt p, Pt q) {
    return dot(p - q, p - q);
}
ld dist(Pt p, Pt q) {
    return sqrt(dist2(p, q));
}
int ccw(Pt p, Pt q, Pt r) {
    ld v = cross(p - q, p - r);
    if (v < -EPS) return -1;
    if (v > EPS) return 1;
    return 0;
}
bool linesParallel(Pt a, Pt b, Pt c, Pt d) {
    return abs(cross(b - a, c - d)) < EPS;
}
Pt ray(Pt a, Pt b){
    return a + (b-a)* 1e10;
}
bool linesCollinear(Pt a, Pt b, Pt c, Pt d) {
    return linesParallel(a, b, c, d)
    && abs(cross(a - b, a - c)) < EPS
    && abs(cross(c - d, c - a)) < EPS;
}
bool segmentsIntersect(Pt a, Pt b, Pt c, Pt d) {
    if (linesCollinear(a, b, c, d)) {
        if (dist2(a, c) < EPS || dist2(a, d) < EPS ||
            dist2(b, c) < EPS || dist2(b, d) < EPS) return true;
        if (dot(c - a, c - b) > 0 && dot(d - a, d - b) > 0 && dot(c - b, d - b) > 0)
            return false;
        return true;
    }
    if (cross(d - a, b - a) * cross(c - a, b - a) > 0) return false;
    if (cross(a - c, d - c) * cross(b - c, d - c) > 0) return false;
    return true;
}

Pt computeLineIntersection(Pt a, Pt b, Pt c, Pt d) {
    b = b - a;
    d = c - d;
    c = c - a;
    assert(dot(b, b) > EPS && dot(d, d) > EPS);
    return a + b * cross(c, d) / cross(b, d);
}
int madd(int a, int b, int mod){
    return (a + b) % mod;
}
int msub(int a, int b, int mod){
    return (a - b + mod) % mod;
}


Pt A[300];
Pt B[300];
ld dp[300][300];
int n, m;
vector<Pt> border(int i, int j){

    vector<Pt> v;

    Pt l = B[msub(i, 1, m)]; // left of i
    Pt r = B[madd(j, 1, m)]; // right of j
    if (segmentsIntersect(B[i], ray(l, B[i]), B[j], ray(r, B[j]))){
        Pt sect = computeLineIntersection(l, ray(l, B[i]), r, ray(r, B[j]));
        v.push_back(l);
        v.push_back(sect);
        v.push_back(r);
        return v;
    }
    Pt start;
    Pt end;
    int starti = -1;
    int endi = -1;
    for(int k = 0; k < n; k++){
        int k2 = madd(k, 1, n);
        if (segmentsIntersect(l, ray(l, B[i]), A[k], A[k2])){
            start = computeLineIntersection(l, ray(l, B[i]), A[k], A[k2]);
            starti = k2;
        }
        if (segmentsIntersect(r, ray(r, B[j]), A[k], A[k2])){
            end = computeLineIntersection(r, ray(r, B[j]), A[k], A[k2]);
            endi = k;
        }
    }
    assert(starti != -1);
    assert(endi != -1);
    v.push_back(l);
    v.push_back(start);
    while(starti != endi){
        v.push_back(A[starti]);
        starti = madd(starti, 1, n);
    }
    v.push_back(A[endi]);
    v.push_back(end);
    v.push_back(r);
    return v;
}
int main() {
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        cin >> A[i].x >> A[i].y;
    }
    scanf("%d", &m);
    for(int i = 0; i < m; i++){
        cin >> B[i].x >> B[i].y;
    }
    for(int i = 0; i < m; i++){ // base case
        int j = madd(i, 1, m);
        dp[i][j] = dist(B[i], B[j]);
    }
    for(int d = 2; d < m; d++){
        for(int i = 0; i < m; i++){
            int j = madd(i, d, m);
            dp[i][j] = 1e20;
            vector<Pt> v = border(i, j);
            int l = 0;
            int r = 0;
            for(int k = i; k != j; k = madd(k, 1, m)){
                int k2 = madd(k, 1, m);
                while(v[l] == v[l + 1] || !segmentsIntersect(B[k2] + (B[k] - B[k2]) * EPS, ray(B[k2], B[k]), v[l], v[l + 1])){
                    l++;
                }
                while(v[r] == v[r + 1] || !segmentsIntersect(B[k] + (B[k2] - B[k]) * EPS, ray(B[k], B[k2]), v[r], v[r + 1])){
                    r++;
                }
                assert(l != r);
                Pt sect1 = computeLineIntersection(B[k2], ray(B[k2], B[k]), v[l], v[l + 1]);
                Pt sect2 = computeLineIntersection(B[k], ray(B[k], B[k2]), v[r], v[r + 1]);
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k2][j] + dist(sect1, sect2));
            }
        }
    }
    ld ans = 1e20;
    for(int i = 0; i< m; i++){
        int j = madd(i, 1, m);
        vector<Pt> v;
        for(int k = 0; k < n; k++){
            int k2 = madd(k, 1, n);
            if (segmentsIntersect(A[k], A[k2], B[i], ray(B[i], B[j]))){
                v.push_back(computeLineIntersection(A[k], A[k2], B[i], ray(B[i], B[j])));
            }
            if (segmentsIntersect(A[k], A[k2], B[j], ray(B[j], B[i]))){
                v.push_back(computeLineIntersection(A[k], A[k2], B[j], ray(B[j], B[i])));
            }
        }
        ans = min(ans, dp[j][i] + dist(v[0], v[1]));
    }
    printf("%.9Lf\n", ans);

    /*for(int i = 0; i < m; i++){
        for(int j = i; j < m; j++){
            db2(i, j);
            cout << dp[i][j] << endl;
        }

    }*/
}
/*
4
0 0
0 10
10 10
10 0
4
1 1
1 6
6 6
6 1
*/
