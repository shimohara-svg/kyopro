#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <queue>
#include <map>
#include <cmath>
#include <iomanip>
#include <set>
#include <stdio.h>
#include <string.h>

using namespace std;

const long long mod = 1000000007;
//const long long mod = 998244353;
const long double PI = 3.1415926535897932384626;
const int inf = 1001001001;
const long long INF = 1001001001001001001LL;
const int dx[] = {0,0,-1,1};
const int dy[] = {-1,1,0,0};
const int day[] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
const int MX = 220000;

//-1~1の2重ループでもOK
//const int dy[8] = {-1,-1,-1,0,0,1,1,1};
//const int dx[8] = {-1,0,1,-1,1,-1,0,1};

/**********コツとか**********/

//分数の大小を比べる
// a / b  と  c / d どちらが大きいか？
// {a / b ,  c / d}  ->  {a * d , c * b} を比べる。(外外 内内)


// 掛け算をしたら long long の上限を超えてしまいそうな場合
// a * b > 1e18 ならOUT -> a > 1e18 / b とかする。


//lower_bound と upper_bound
/*
  vector<int> v;
  v.push_back(1);
  v.push_back(3);
  v.push_back(3);
  v.push_back(5);
  v.push_back(7);

  int j = lower_bound(v.begin() , v.end() , 3) - v.begin();
  cout << j << endl; // 1になる

  int k = upper_bound(v.begin() , v.end() , 3) - v.begin();
  cout << k << endl; // 3になる
*/


//90度回転

/*
for (int i = 0; i < h; i++) {
  for (int j = 0; j < w; j++) {
    ans[i][j] = c[h - 1 - j][i];
  }
}
*/

/*************************/

//ルートNで素数チェック
/*
bool is_prime(long long x) {
  if (x == 2 || x == 3 || x == 5 || x == 7) {
    return true;
  }
  if (x == 1) {
    return false;
  }
  for (long long j = 2; j * j <= x; j++) {
    if (x % j == 0) {
      return false;
    }
  }
  return true;
}
*/

template <typename T>
void chmin(T &a, T &b) {
  if (a > b) a = b;
}

template <typename T>
void chmax(T &a, T &b) {
  if (a < b) a = b;
}

long long gcd(long long a , long long b) {
  if (a < b) swap(a , b);
  if (b == 0) return a;
  if (a % b == 0) return b;
  else return gcd(b , a % b);
}

long long lcm(long long a , long long b) {
  if (a < b) swap(a, b);
  if (b == 0) return a;
  else return a / gcd(a , b) * b;
}

int keta (long long x) {
  int ret = 0;
  while(x) {
    ret++;
    x /= 10;
  }
  return ret;
}

long long modpow (long long x , long long p) {
  long long ret = 1;
  while (p) {
    if (p % 2) {
      ret *= x;
      ret %= mod;
    }
    p /= 2;
    x *= x;
    x %= mod;
  }
  return ret;
}

vector<long long> fact(MX , 0);
vector<long long> factinv(MX , 0);
 
void calc_fact () {
  fact[0] = 1;
  for (int i = 1; i < MX; i++) fact[i] = 1LL * i * fact[i - 1] % mod;
  for (int i = 0; i < MX; i++) factinv[i] = modpow(fact[i], mod - 2);
}
 
long long nCk (long long n , long long k) {
  return fact[n] * factinv[k] % mod * factinv[n - k] % mod;
}

//modの引き算
long long sub(long long a, long long b) {
  long long ret = (a + mod - b);
  if (ret >= mod) ret -= mod;
  return ret;
}

//v.erase(unique(v.begin(), v.end()), v.end());
//memset(v , 0 , sizeof(v));
//rotate(v.begin() , v.begin() + 1 , v.end()); 1ずらす


int main() {

  //cin.tie(0);
  //ios::sync_with_stdio(false);
  //cout << fixed << setprecision(15);
  
  //グラフ
  /*
  vector<vector<int> > g(n);
  for (int i = 0; i < n - 1; i++) {
    int a , b;
    cin >> a >> b;
    a--;
    b--;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  */


  //グラフBFS
  /*


  */


  
  //グリッド
  /*
  int h , w;
  cin >> h >> w;
  vector<vector<char> > c(h , vector<char>(w));
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      cin >> c[i][j];
    }
  }
  queue<pair<int, int> > q;
  vector<vector<int> > dist(h, vector<int>(w, INF));
  vector<vector<bool> > used(h, vector<bool>(w, false));
  q.push(make_pair(0, 0));
  used[0][0] = true;
  while (!q.empty()) {
    int y = q.front().first;
    int x = q.front().second;
    q.pop();
    for (int k = 0; k < 4; k++) {
      int ny = y + dy[k];
      int nx = x + dx[k];
      if (ny < 0 || nx < 0 || ny >= h || nx >= w) continue;
      if (used[ny][nx]) continue;
      if (dist[ny][nx] <= dist[y][x] + 1) continue;
      used[ny][nx] = true;
      dist[ny][nx] = dist[y][x] + 1;
      q.push(make_pair(ny, nx));
    }
  }
  */

  //素数
  /*
  vector<bool> is_prime(3000001 , true);
  vector<int> p;
  is_prime[0] = is_prime[1] = false;
  for (int i = 2; i <= 3000000; i++) {
    if(is_prime[i]) {
      for (int j = 2 * i; j <= 3000000; j += i) {
        is_prime[j] = false;
      }
      p.push_back(i);
    }
  }
  */

  /*
  int n;
  cin >> n;
  vector<int> a(n);
  for (int &x : a) cin >> x;
  */

  return 0;
}

//% /usr/local/bin/g++ a.cpp
