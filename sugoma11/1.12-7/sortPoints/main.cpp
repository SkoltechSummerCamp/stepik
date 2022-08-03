#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <math.h>

using namespace std;

struct man {
    string name;
    float x = 0;
    float y = 0;
    float z = 0;
};

bool cmp(man a, man b) {
    return (a.x + a.y + a.z) / 3 > (b.x + b.y + b.z) / 3;
}


int main() {
  int n;
  cin >> n;
  vector <man> a(n);
  string str;
  int fst_num;
  getline(cin, str);
  for (int i = 0; i < n; i++) {
      getline(cin, str);
      for (int i = 0; i < str.size(); i++) {
          if(isdigit(str[i])){
              fst_num = i;
              break;
          }
      }
      string name;
      for (int i = 0; i < fst_num - 1; ++i) {
          name += str[i];
      }
      man struct_temp;
      struct_temp.name = name;
      struct_temp.x = str[fst_num] - '0';
      struct_temp.y = str[fst_num + 2] - '0';
      struct_temp.z = str[fst_num + 4] - '0';
      a[i] = struct_temp;
  }
      stable_sort(a.begin(), a.end(), cmp);
      for (auto now : a) {
      cout << now.name << endl;
      }
  return 0;
}
