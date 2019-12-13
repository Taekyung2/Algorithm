#include <bits/stdc++.h>
using namespace std;


int TC, N, height[20000];


int solve(int left, int right) {
    //기저 사례 판자가 한 개인 경우
    if(left == right) return height[left];
    int mid = (left + right) / 2;
    int ret = max(solve(left, mid), solve(mid + 1, right));
    int lo = mid, hi = mid + 1;
    int h = min(height[lo], height[hi]);
    ret = max(ret, h * 2);
    //사각형이 입력 전체를 덮을 때 까지 확장
    while(left < lo || hi < right) {
        if(hi < right && (lo == left || height[lo-1] < height[hi+1])) {
            ++hi;
            h = min(h, height[hi]);
        }
        else {
            --lo;
            h = min(h, height[lo]);
        }
        ret = max(ret, h * (hi - lo + 1));
    }
    return ret;
}


int main() {
   cin >> TC;
   for(int t = 0; t < TC; t++) {
        cin >> N;
        for(int i=0; i < N; i++)
            cin >> height[i];    
        cout << solve(0, N-1) << endl;
   } 
}