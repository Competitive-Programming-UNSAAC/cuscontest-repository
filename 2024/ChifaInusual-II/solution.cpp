#include <bits/stdc++.h>

using namespace std;

const int N = 100005;
const int modulo = 1000000007;

int factorial[N];

int mul(int x, int y) {
  return (long long)x * y % modulo;
}

int power(int x, int y) {
  int potencia = 1;
  while (y) {
    if (y & 1) {
      potencia = mul(potencia, x);
    }
    x = mul(x, x);
    y >>= 1;
  }
  return potencia;
}

int modulo_inverso(int x) {
  return power(x, modulo - 2);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int test_cases;
  cin >> test_cases;
  factorial[0] = 1;
  for (int i = 1; i < N; i++) {
    factorial[i] = mul(i, factorial[i - 1]); 
  }
  for (int case = 0; case < test_cases; case++) {
    int n, k;
    cin >> n >> k;
    int numerador = factorial[n];
    int denominador = mul(factorial[n - k], factorial[k]);
    int cantidad_platos_unicos = mul(numerador, modulo_inverso(denominador));
    cout << cantidad_platos_unicos << '\n';
  }
  return 0;
}