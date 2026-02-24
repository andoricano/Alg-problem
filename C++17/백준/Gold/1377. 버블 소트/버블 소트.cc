#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

// 코드 실행하라길래 실행했더니 시간초과 발생..
// 버블 정렬과 정렬 방식이 유사하면서도 더 빠른 정렬을 이용해야 함
// 버블 정렬을 통한 정렬이 다 되었을 시점의 i를 구하는 방법
// 정렬 빠르게 하는 방시긍로 수정해야 한다

// 여기서부턴 검색을 이용하여 풀음
// 어떤 경우에도 작은 수가 왼쪽으로 이동하는 경우는 i에 단 한 번임.
// 즉 왼쪽으로 이동한 수의 최대값과 정렬이 일어난 케이스와 같다는 것.
int main()
{
    int n;
    scanf("%d", &n);
    pair<int, int> p[n];

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &p[i].first);
        p[i].second = i;
    }

    sort(p, p + n);

    int max = 0;

    for (int i = 0; i < n; i++)
    {
        if (max < p[i].second - i)
        {
            max = p[i].second - i;
        }
    }

    printf("%d\n", max + 1);
}
