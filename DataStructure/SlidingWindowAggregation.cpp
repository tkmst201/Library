#include <stack>
#include <vector>
#include <cassert>
#include <cstdio>

/*
last-updated: 2019/12/18

現在 区間min のみ
抽象化したいね
vbackは1要素しか必要ないのでそうするべき

# 仕様
void push(const int &x) :
	時間計算量: Θ(1) amortized
	後ろに値 x を入れる

void pop() :
	時間計算量: Θ(1) amortized
	先頭の要素を削除する

bool empty() :
	時間計算量: Θ(1)
	空かどうかを返す

int fald_all() :
	時間計算量: Θ(1)
	現在入っている全ての要素の演算結果を返す

private:
int func(const int &x, const int &y) :
	時間計算量: Θ(1)
	二項演算

# 参考
https://scrapbox.io/data-structures/Sliding_Window_Aggregation, 2019/12/18
*/

struct SlidingWindowAggregation {
public:
	void push(const int &x) {
		push(x, sback, vback);
	}
	
	void pop() {
		assert(!empty());
		if (sfront.empty()) {
			while (!sback.empty()) {
				push(sback.top(), sfront, vfront);
				sback.pop();
			}
			vback.clear();
		}
		sfront.pop();
		vfront.pop_back();
	}
	
	bool empty() {
		return sfront.empty() && sback.empty();
	}
	
	int fold_all() {
		assert(!empty());
		if (vfront.empty()) return vback.back();
		if (vback.empty()) return vfront.back();
		return func(vfront.back(), vback.back());
	}
	
private:
	std::stack<int> sfront, sback;
	std::vector<int> vfront, vback;
	
	void push(const int &x, std::stack<int> &st, std::vector<int> &v) {
		st.push(x);
		if (v.empty()) v.push_back(x);
		else {
			int addval = func(v.back(), x);
			v.push_back(addval);
		}
	}
	
	int func(const int &x, const int &y) {
		return std::min(x, y);
	}
};


/*
// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_3_D

int main() {
	int N, L;
	scanf("%d %d", &N, &L);
	std::vector<int> A(N);
	for (int i = 0; i < N; ++i) scanf("%d", &A[i]);
	
	SlidingWindowAggregation swag;
	for (int i = 0; i < L - 1; ++i) swag.push(A[i]);
	
	for (int i = L - 1; i < N; ++i) {
		swag.push(A[i]);
		printf("%d%c", swag.fold_all(), i == N - 1 ? '\n' : ' ');
		swag.pop();
	}
	
	return 0;
}
*/