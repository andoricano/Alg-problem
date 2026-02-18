#include <cstdio>
#include <deque>

using namespace std;

int main()
{
    int n, s;
    scanf("%d %d", &n, &s);
    deque<int> d;
    int total = 0, length = 2000000000;
    for (int i = 0; i < n; i++)
    {
        int num;
        scanf("%d", &num);
        total += num;
        d.push_back(num);

        while (total >= s)
        {
            if (length > d.size())
            {
                length = d.size();
            }
            total -= d.front();
            d.pop_front();
        }
    }

    if (length == 2000000000)
        printf("0\n");
    else
        printf("%d\n", length);
}
