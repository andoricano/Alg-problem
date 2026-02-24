#include <cstdio>
#include <vector>

using namespace std;

// 시간을 주축으로 해서 queue를 소비시키면 끝나는 문제인데 n이 20억이라 queue 못 씀
// 브루트포스는 m의 경우의 수가 30억이라 절대 불가
// 시간을 주축으로 해서 놀이기구에 할당된 시간을 계산하여 n의 마지막이 탈 수 있는 시간 대를 구함
// 해당 시간 대에서 가장 번호가 적은 놀이기구에 탑승
// 이것도 사실상 시간 대까지 몇 명이 탑승하는지 최대값의 최소값을 구하는 문제
// 매개 변수 이분 탐색이다..
// 실전에서 생각할 수 있을지도??

// 일단 주어진 값 n을 기준으로 max를 만드는 과정이 복잡해서 최악의 시간 600만으로 하드코딩.(최대 22번)
// 시간에 따라 vector 요소값으로 싹다 나눠서 몫을 구하여 더한 r을 구함(최대 만번, 현재 시간 복잡도 m * log 600만)
// r에 대한 time 중 최소 time을 구하자.
// 마지막 time이 최적의 time일 것이 지고하니 이 time을 가지고 O(N)의 로직을 돌림.
int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    vector<int> v(m);
    for (int i = 0; i < m; i++)
    {
        scanf("%d", &v[i]);
    }

    if (n <= m)
    {
        printf("%d", n);
        return 0;
    }
    long long time = 0, min = 1, max = 60000000000; // 최악의 경우에서 계산해나가.

    while (min <= max)
    {
        long long mid = (min + max) / 2, cnt = m;

        for (int i = 0; i < m; i++)
            cnt += mid / v[i];

        if (n <= cnt)
        {
            time = mid;
            max = mid - 1;
        }
        else
        {
            min = mid + 1;
        }
    }

    // 감이 안와서 인터넷 검색
    // t-1까지 나머지 연산으로 자리를 배정한 뒤 그 자리에서 마지막 아이를 줄 세우는 방식이 결과적으로 가장 좋은 방법이라고 함
    // 이건 실전에서 생각 아예 못 할 거 같은데..
    long long ans = 0, total = m;
    for (int i = 0; i < m; i++)
    {
        total += (time - 1) / v[i];
    }

    for (int i = 0; i < m; i++)
    {
        if (time % v[i] == 0)
        {
            total++;
            if (total == n)
            {
                printf("%d", i + 1);
                return 0;
            }
        }
    }
}
