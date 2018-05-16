#include <bits/stdc++.h>

using namespace std;

const int N = 100;

// 0 sama, 1 gede -1 kecil
int sign(int a, int b) {
  if (a > b) return 1;
  else if (a < b) return -1;
  else return 0;
}

vector<int> a[N], b[N];
char s[N];
bool bad[N];
int n, K;

vector<int> get() {
  vector<int> ret;
  for (int i = 0; i < K; i++) {
    int numa = 0, numb = 0;
    for (auto it : a[i]) {
      if (bad[it]) {
        numa++;
      } else {
        numa += 1000;
      }
    }
    for (auto it : b[i]) {
      if (bad[it]) {
        numb++;
      } else {
        numb += 1000;
      }
    }
    ret.push_back(sign(numa, numb));
  }
  return ret;
}

map<tuple<int, int, int, int>, bool> mp;

int main() {
  scanf("%d,%d", &n, &K);
  for (int i = 0; i < K; i++) {
    scanf("%s", s);
    int len = strlen(s);
    bool done = 0;
    for (int j = 0; j < len; j++) {
      if (s[j] == '-') {
        done = 1;
        continue;
      }
      if (!done) {
        a[i].push_back(s[j] - 'A');
      } else {
        b[i].push_back(s[j] - 'A');
      }
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      for (int k = 0; k < n; k++) {
        for (int l = k + 1; l < n; l++) {
          if (i == k && j == l) continue;
          bad[i] = bad[j] = 1;
          auto first = get();
          bad[i] = bad[j] = 0;

          bad[k] = bad[l] = 1;
          auto second = get();
          bad[k] = bad[l] = 0;

          if (first == second && !mp[make_tuple(i, j, k, l)]) {
            mp[make_tuple(i, j, k, l)] = mp[make_tuple(k, l, i, j)] = 1;
            printf("%c%c=%c%c\n", i + 'A', j + 'A', k + 'A', l + 'A');
          }
        }
      }
    }
  }
  return 0;
}
