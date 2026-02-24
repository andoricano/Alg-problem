#include <cstdio>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>
#include <queue>

using namespace std;

// 이분탐색처럼 보였으나 A,B 사이 경로를 형성해야 하기 때문에 그래프 문제로 판단
// 각 vertex 사이의 edge가 공통이기에 인접리스트 자료구조 가능.
// 다만 vertex가 선형적이지 않아 visited를 map으로 진행해야 함.

// 1. 입력에 대한 (1<=>2), (2<=>1) 같은 중복 노선을 제거한 가중치 map과 visited map 생성
// 2. 가중치 map을 기준으로 인접 리스트 생성
// 3. 인접 리스트로 dfs를 돌리면서 A섬과 B섬에 대한 경로 vector 생성
//   - dfs가 가능한 이유는 1->2->3->4와 2->3->4가 같기 때문
//   - 중복 노선을 제거하면서 vertex를 오름차순으로 해놔서 2->1->5->4같은 케이스 방지하여 예외 방지
// 4. 3번의 경로 vector를 순회하여 최소값의 최대값 확인

// 3이 성립하지 않아 bfs로 이분탐색 + 가지치기로 진행해야 함
bool bfs(map<pair<int, int>, int> &r, map<int, vector<int>> &v, int start, int goal, int weight)
{
    map<int, int> visited;
    queue<int> q;
    q.push(start);
    visited[start] = true;

    bool checker = false;
    while (q.size() > 0)
    {
        int node = q.front();
        q.pop();

        if (node == goal)
            return true;

        for (auto x : v[node])
        {

            pair<int, int> edge = minmax(node, x);

            //초기화가 안 된 map에 메모리를 추가하지 않고 접근하려면 count나 find가 좋다고 한다.
            if (visited.count(x) == 0 && r[edge] >= weight)
            {
                visited[x] = 1;
                q.push(x);
            }
        }
    }
    return false;
}

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);

    map<pair<int, int>, int> r;
    for (int i = 0; i < m; i++)
    {
        int a, b, w;
        scanf("%d %d %d", &a, &b, &w);
        //{} initializer c++11 이상 지원
        pair<int, int> c = minmax(a, b);
        if (r[c] < w)
            r[c] = w;
    }

    int a, b;
    scanf("%d %d", &a, &b);

    map<int, vector<int>> v;
    int min = 1000000001, max = 0;
    for (auto route : r)
    {
        pair<int, int> island = route.first;
        v[island.first].push_back(island.second);
        v[island.second].push_back(island.first);
        max = route.second > max ? route.second : max;
        min = route.second < min ? route.second : min;
    }

    int ans = 0;

    // 경로를 찾았다는건 weight를 더 올려볼 수 있다는 것
    // 찾을 수 없다면 weight를 더 낮춰야 .
    while (min <= max)
    {
        int weight = (min + max) / 2;
        bool searching = bfs(r, v, a, b, weight);

        if (searching)
        {
            ans = weight;
            min = weight + 1;
        }
        else
        {
            max = weight - 1;
        }
    }
    printf("%d", ans);
}
/*
3 3
1 2 2
3 1 3
2 3 2
1 3

>> 3

*/