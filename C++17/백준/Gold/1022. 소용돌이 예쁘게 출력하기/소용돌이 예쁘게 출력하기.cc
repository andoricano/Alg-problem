#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

void make_hurricane(vector<vector<int>> &v, int r1, int c1, int r2, int c2)
{
    for (int r = r1; r <= r2; r++)
    {
        for (int c = c1; c <= c2; c++)
        {
            int n = max(abs(r), abs(c));
            int max_val = (2 * n + 1) * (2 * n + 1);
            int val;

            if (n == 0)
                val = 1;
            else if (r == n)
                val = max_val - (n - c);
            else if (c == -n)
                val = max_val - 2 * n - (n - r);
            else if (r == -n)
                val = max_val - 4 * n - (c + n);
            else
                val = max_val - 6 * n - (r + n);

            v[r - r1][c - c1] = val;
        }
    }
}

void print_hurricane(vector<vector<int>> &v, int r1, int c1, int r2, int c2)
{
    int max_num = 0;
    for (int r = 0; r <= r2 - r1; r++)
    {
        for (int c = 0; c <= c2 - c1; c++)
        {
            if (v[r][c] > max_num)
                max_num = v[r][c];
        }
    }

    int length = 0;
    while (max_num > 0)
    {
        max_num /= 10;
        length++;
    }

    for (int r = 0; r <= r2 - r1; r++)
    {
        for (int c = 0; c <= c2 - c1; c++)
        {
            printf("%*d ", length, v[r][c]);
        }
        printf("\n");
    }
}

int main()
{
    int r1, c1, r2, c2;
    scanf("%d %d %d %d", &r1, &c1, &r2, &c2);
    vector<vector<int>> v(50, vector<int>(5, 0));
    make_hurricane(v, r1, c1, r2, c2);
    print_hurricane(v, r1, c1, r2, c2);
}