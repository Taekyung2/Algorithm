// 최대 증가 부분 수열을 실제로 계산하기
int n;
int cache[101], S[100], choices[101];

int lis4(int start) {
	int& ret = cache[start];
	if(ret != -1) return ret;
	ret = 1;
	int bestNext = -1;
	for(int next = start + 1; next < n; ++next)
		if(start == -1 || S[start] < S[next]) {
			int cand = lis4(next) + 1;
			if(cand > ret) {
				ret = cand;
				bestNext = next;
			}
		}
	choices[start + 1] = bestNext;
	return ret;
}


void reconstruct(int start, vctor<int>& seq) {
	if(start != -1)
		seq.push_back(S[start]);
	int next = choices[start + 1];
	if(next != -1)
		reconstruct(next, seq);
}
