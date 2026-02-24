#include <cstdio>

using namespace std;

//수열에 들어갈 데이터를 만드는 문제
//어떻게 보면 리소스없이 리소스를 만드는 문제랄까
//사이즈가 100KB*100KB라서 10000MB나 된다.
//일차원 오름차순으로 만든다고 하니 일반적인 방법은 시도조차 못한다.
//즉 n*n으로 만들어진 가상의 배열에서 k로 나누기 + 나머지 연산을 이용하여 i*j 인덱스를 구하면서 오름차순으로 정렬된 위치까지 생각해야 한다.
//소수로 진행하기에도 애매한게 10**9라서 에라토스테네스의 체도 불가
//도저히 모르겠어서 알고리즘 종류 확인하니 이분+매개변수 탐색이라고 나옴
//그냥 매개변수 하나 넣고 그게 k번째에 만족하냐 라는 조건만 만들면 끝나는 문제라는게 참..
//이분탐색 특성상 최대값의 최소가 확실하게 잡혀서 복잡한 예외 사항도 없음
//n이 4고 k가 11일 때 v를 8이라면 잡는다면 그냥 나누기 + 나머지만 해서 1행에 4, 2행에 4, 3행에 2, 4행에 2 찍힘
//4 + 4 + 2 + 2 ==> k == 12임
//11보다 커서 v값을 갱신하고 max 값을 줄이고, 늘리고 하다보면 k가 11일 때 매칭되는 값이 없어서 그냥 v == 8로 끝남
//실전에 이런 사고를 할 수 있을지 걱정까지 되네..

long long count_row(long long n, long long a){
    long long cnt = 0;
    for(int i = 1; i <= n; i ++){
        long long row = n*i > a ? a : n*i;
        cnt += row/i;
    }
    return cnt;
}

int main()
{
    long long n, k;
    scanf("%lld %lld", &n, &k);

    long long ans = 0, min = 1, max = n*n;

    // int cnt = 0;
    while(min <= max){
        // if(cnt ++ > 20)break;
        long long mid = (max + min)/2;
        long long v = count_row(n,mid);
        
        if(v >= k){
            ans = mid;
            max = mid - 1;
        }else{
            min = mid + 1;
        }
    }

    printf("%lld",ans);
}
