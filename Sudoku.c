#include <stdio.h>

int check(int doo[10][10], int i, int j);
void output(int su[10][10], int doo[10][10]);

int main() {
  char rk[100][100];
  int su[10][10], doo[10][10];
  int i, j, f, s, ab, cd, ef, gh, ram, ram1, ram0;

  for (i = 0; i < 9; i++) scanf("%s", rk[i]);

  for (i = 1; i < 10; i++)
    for (j = 1; j < 10; j++) {
      doo[i][j] = su[i][j] = rk[i - 1][j - 1] - '0';
    }

  for (i = 11; i <= 99; i++) {
    if (i % 10 == 0) continue;

    f = i / 10;
    s = i % 10;

    if (su[f][s] == 0) {
      ab = f;
      cd = s;

      break;
    }
  }

  for (i = 99; i >= 11; i--) {
    if (i % 10 == 0) continue;

    f = i / 10;
    s = i % 10;

    if (su[f][s] == 0) {
      ef = f;
      gh = s;

      break;
    }
  }

  for (i = 1; i <= 9; i++)
    for (j = 1; j <= 9; j++) {
      if (su[i][j] != 0) {
        if (check(su, i, j) == 1) {
          printf("No solution\n");
          return 0;
        }
      }
    }

  for (i = 1; i <= 9; i++)
    for (j = 1; j <= 9; j++) {
      if (su[i][j] != 0) continue;

      ram0 = 1;

      while (ram0) {
        ram = 1;

        while (ram) {
          doo[i][j]++;

          if (doo[i][j] == 10) {
            if (doo[ab][cd] == 10) {
              printf("No solution\n");
              return 0;
            }

            doo[i][j] = 0;
            ram1 = 1;

            while (ram1) {
              if (j == 1) {
                i = i - 1;
                j = 9;
              } else
                j = j - 1;

              if (su[i][j] != 0) continue;

              ram1 = 0;
            }

            continue;
          }

          ram = 0;
        }

        if (check(doo, i, j) == 1) continue;

        ram0 = 0;
      }

      if (i == ef && j == gh) {
        output(su, doo);
      }
    }

  return 0;
}

void output(int su[10][10], int doo[10][10]) {
  int i, j;

  for (i = 1; i <= 9; i++) {
    for (j = 1; j <= 9; j++) printf("%d", doo[i][j]);

    printf("\n");
  }
}

int check(int doo[10][10], int i, int j) {
  int u, v, w, x, r, c;

  for (c = 1; c <= 9; c++) {
    if (c == j) continue;

    if (doo[i][c] == doo[i][j]) {
      return 1;
    }
  }

  for (r = 1; r <= 9; r++) {
    if (r == i) continue;

    if (doo[r][j] == doo[i][j]) {
      return 1;
    }
  }

  if (i % 3 == 1) {
    u = i + 1;
    v = i + 2;
  }

  if (i % 3 == 2) {
    u = i + 1;
    v = i - 1;
  }

  if (i % 3 == 0) {
    u = i - 1;
    v = i - 2;
  }

  if (j % 3 == 1) {
    w = j + 1;
    x = j + 2;
  }

  if (j % 3 == 2) {
    w = j + 1;
    x = j - 1;
  }

  if (j % 3 == 0) {
    w = j - 1;
    x = j - 2;
  }

  if (doo[i][j] == doo[u][w] || doo[i][j] == doo[v][w] ||
      doo[i][j] == doo[u][x] || doo[i][j] == doo[v][x])
    return 1;

  return 0;
}