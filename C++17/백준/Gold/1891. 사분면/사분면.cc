#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#include <cstring>

using namespace std;

/**
 * 1. d를 바탕으로 가상의 canvas를 만든다.(2**d)
 * 2. 주어진 사분면 번호로 가상의 canvas 상의 좌표를 구한다.
 *  2.1 1분면 (size/2,0), 2분면(0,0), 3분면(0, size/2), 4분면(size/2, size/2)
 *  2.2 위 수치를 기준으로 각각의 사분면 번호와 사이즈를 계산하여 더해주면 canvas 상의 좌표를 구할 수 있다.
 * 3. x,y 변화량을 더하여 올바른지 확인한다.
 * 4. 더해진 좌표에 대한 사분면 번호를 구한다.
 */

void edit_position(int d, string num, long long *position)
{
    if (d == 0)
        return;

    edit_position(d - 1, num, position);

    int quadrant = num[num.length() - d] - '0';
    long long delta = (long long)pow(2, d - 1);

    if (quadrant == 1 || quadrant == 2)
    {
        position[1] += delta;
        if (quadrant == 1)
            position[0] += delta;
    }
    else if (quadrant == 4)
    {
        position[0] += delta;
    }
}
bool change_position(int size, long long *position, long long deltaX, long long deltaY)
{
    long long len = (long long)pow(2, size);

    position[0] += deltaX;
    position[1] += deltaY;

    if (position[0] < 0 || position[0] >= len || position[1] < 0 || position[1] >= len)
    {
        printf("-1");
        return false;
    }

    return true;
}
int get_new_quadrant(int size, long long *position)
{
    long long half = (long long)pow(2, size - 1);

    int quadrant = 0;
    long long x = position[0];
    long long y = position[1];

    if (x >= half && y >= half)
    {
        quadrant = 1;
        position[0] -= half;
        position[1] -= half;
    }
    else if (x < half && y >= half)
    {
        quadrant = 2;
        position[1] -= half;
    }
    else if (x < half && y < half)
    {
        quadrant = 3;
    }
    else if (x >= half && y < half)
    {
        quadrant = 4;
        position[0] -= half;
    }

    return quadrant;
}

int main()
{
    int d;
    string quadrant;
    cin >> d >> quadrant;

    long long x, y;
    scanf("%lld %lld", &x, &y);

    long long position[2] = {0, 0};

    edit_position(d, quadrant, position);
    if (change_position(d, position, x, y))
    {
        for (int i = d; i > 0; i--)
        {
            printf("%d", get_new_quadrant(i, position));
        }
    }
}