#include <algorithm>
#include <vector>

/*
last-updated: 2019/11/19

# 仕様
イテレータは実装していないのでポインタでノードを扱う

AVL_tree() :
	時間計算量: Θ(1)
	空の木を作成する

AVL_tree(const AVL_tree &rhs) :
AVL_tree &operator=(const AVL_tree &rhs) :
	時間計算量: Θ(n log n)
	木のコピーを行う
	enumerate() で得た各要素を insert() しているので遅い

bool empty() const :
	時間計算量: Θ(1)
	木が空がどうか判定する

std::size_t size() const :
	時間計算量: Θ(1)
	木の要素数を返す

void clear() :
	時間計算量: Θ(n)
	全ての要素を削除する

std::vector<T> enumerate() const :
	時間計算量: Θ(n)
	木の全ての要素を昇順に std::vector に入れて返す

Node *begin() const :
	時間計算量: Θ(1)
	最も小さい要素のポインタを返す

Node *end() const :
	時間計算量: Θ(1)
	最も大きい要素の次の要素(?)のポインタを返す

Node *find(const T &x) :
	時間計算量: Θ(log n)
	要素 x を検索してそのポインタを返す
	複数存在する場合ポインタで最小のポインタ

Node *insert(const T &x) :
	時間計算量: Θ(log n)
	要素 x を挿入し、挿入後の要素のポインタを返す

Node *erase(const T &x) :
	時間計算量: Θ(log n)
	要素 x を削除する

Node *erase(Node *Q) :
	時間計算量: Θ(log n)
	ポインタ Q の要素を削除する

Node *lower_bound(const T &x) const :
	時間計算量: Θ(log n)
	x 以上の最小の要素のポインタを返す

Node *upper_bound(const T &x) const :
	時間計算量: Θ(log n)
	x より大きい最小の要素のポインタを返す

Node *k_th_smallest(std::size_t k) const :
	時間計算量: Θ(log n)
	k 番目に小さい要素のポインタを返す

Node *k_th_largest(std::size_t k) const :
	時間計算量: Θ(log n)
	k 番目に大きい要素のポインタを返す

Node *next(Node *Q) const :
	時間計算量: O(log n)
	Q の次に大きい要素のポインタを返す

Node *prev(Node *Q) const :
	時間計算量: O(log n)
	Q より 1 つ小さい要素のポインタを返す

# 参考
https://ja.wikipedia.org/wiki/AVL%E6%9C%A8, 2019/11/19
*/

template<typename T> struct AVL_tree {
public:
	
	// private に, したくない…??
	struct Node {
		T value;
		Node *child[2] {}, *par = nullptr;
		bool is_r;
		std::size_t size[2] {}, height[2] {};
		
		Node(T x, Node *par, bool is_r)
			: value(x), par(par), is_r(is_r) {}
	};
	
	AVL_tree() : size_(0), root_node(nullptr) {}
	~AVL_tree() {
		clear();
	}
	
	AVL_tree(const AVL_tree &rhs) {
		*this = rhs;
	}
	
	AVL_tree &operator=(const AVL_tree &rhs) {
		if (this != &rhs) {
			this->clear();
			std::vector<T> tmp = rhs.enumerate();
			for (const T &elm : tmp) this->insert(elm);
		}
		return *this;
	}
	
	bool empty() const {
		return size_ == 0;
	}
	
	std::size_t size() const {
		return size_;
	}
	
	void clear() {
		clear_dfs(root_node);
		root_node = nullptr;
		size_ = 0;
		e_ptr[0] = e_ptr[1] = nullptr;
	}
	
	std::vector<T> enumerate() const {
		std::vector<T> elements;
		elements.reserve(size_);
		enumerate_dfs(root_node, elements);
		return elements;
	}
	
	Node *begin() const {
		return begin_();
	}
	
	Node *end() const {
		return end_();
	}
	
	Node *find(const T &x) {
		return find_(x);
	}
	
	Node *insert(const T &x) {
		size_++;
		bool ef[2] {};
		
		Node *Q = root_node, *R = nullptr;
		bool d = false;
		while (Q) {
			R = Q;
			d = Q->value <= x;
			ef[!d] = true;
			Q = Q->child[d];
		}
		Q = new Node(x, R, d);
		if (!ef[0]) e_ptr[0] = Q;
		if (!ef[1]) e_ptr[1] = Q;
		
		if (R) {
			R->size[d] = 1;
			R->height[d] = 1;
			R->child[d] = Q;
			update(R);
		}
		else root_node = Q;
		return Q;
	}
	
	Node *erase(const T &x) {
		Node *Q = find_(x);
		if (Q) return erase_(Q);
		return end_();
	}
	
	Node *erase(Node *Q) {
		if (Q) return erase_(Q);
		return end_();
	}
	
	Node *lower_bound(const T &x) const {
		return lower_bound_(x);
	}
	
	Node *upper_bound(const T &x) const {
		return upper_bound_(x);
	}
	
	Node *k_th_smallest(std::size_t k) const {
		return k_th_smallest_(k);
	}
	
	Node *k_th_largest(std::size_t k) const {
		return k_th_largest_(k);
	}
	
	Node *next(Node *Q) const {
		if (Q) return move(Q, true);
		return e_ptr[0];
	}
	
	Node *prev(Node *Q) const {
		if (Q) return move(Q, false);
		return e_ptr[1];
	}
	
private:
	std::size_t size_ {};
	Node *root_node {};
	Node *e_ptr[2] {};
	
	void clear_dfs(Node* Q) {
		if (!Q) return;
		clear_dfs(Q->child[0]);
		clear_dfs(Q->child[1]);
		delete Q;
	}
	
	void enumerate_dfs(const Node *Q, std::vector<T> &elements) const {
		if (!Q) return;
		enumerate_dfs(Q->child[0], elements);
		elements.push_back(Q->value);
		enumerate_dfs(Q->child[1], elements);
	}
	
	 Node *begin_() const {
		return e_ptr[0];
	}
	
	Node *end_() const {
		return nullptr;
	}
	
	Node *rotate(Node *Q, bool d) {
		Node *R = Q->par, *P = Q->child[!d], *B = P->child[d];
		
		if (R) R->child[Q->is_r] = P;
		else root_node = P;
		
		Q->child[!d] = B;
		P->child[d] = Q;
		
		if (B) {
			B->par = Q;
			B->is_r = !d;
		}
		
		P->par = Q->par;
		P->is_r = Q->is_r;
		
		Q->par = P;
		Q->is_r = d;
		Q->size[!d] = P->size[d];
		Q->height[!d] = P->height[d];
		
		P->size[d] = Q->size[0] + Q->size[1] + 1;
		P->height[d] = std::max(Q->height[0], Q->height[1]) + 1;
		return P;
	}
	
	void update(Node *Q) {
		bool done = false;
		while (true) {
			if (!done && std::abs(static_cast<int>(Q->height[0]) - static_cast<int>(Q->height[1])) > 1) {
				bool d = Q->height[0] > Q->height[1];
				Node *P = Q->child[!d];
				if (P->height[!d] < P->height[d]) rotate(P, !d);
				Q = rotate(Q, d);
				done = true;
			}
			
			Node *R = Q->par;
			if (!R) break;
			R->size[Q->is_r] = Q->size[0] + Q->size[1] + 1;
			R->height[Q->is_r] = std::max(Q->height[0], Q->height[1]) + 1;
			Q = R;
		}
	}
	
	Node *find_(const T &x) {
		Node *Q = lower_bound_(x);
		if (Q && Q->value != x) Q = end_();
		return Q;
	}
	
	Node *erase_(Node *Q) {
		size_--;
		Node *ret = next(Q), *upd = nullptr;
		
		if (Q->child[0] && Q->child[1]) {
			Node *P = Q->child[0];
			while (P->child[1]) P = P->child[1];
			Q->value = std::move(P->value);
			Q = P;
		}
		
		Node *R = Q->par;
		if (R) upd = R;
		if (Q->child[0] || Q->child[1]) {
			Node *P = Q->child[0] ? Q->child[0] : Q->child[1];
			if (R) {
				R->size[Q->is_r] = Q->size[P->is_r];
				R->height[Q->is_r] = Q->height[P->is_r];
				R->child[Q->is_r] = P;
				P->par = R;
				P->is_r = Q->is_r;
			}
			else {
				P->par = nullptr;
				root_node = P;
			}
		}
		else {
			if (R) {
				R->size[Q->is_r] = 0;
				R->height[Q->is_r] = 0;
				R->child[Q->is_r] = nullptr;
			}
			else {
				root_node = nullptr;
			}
		}
		
		if (e_ptr[0] == Q) e_ptr[0] = next(Q);
		if (e_ptr[1] == Q) e_ptr[1] = prev(Q);
		delete Q;
		if (upd) update(upd);
		return ret;
	}
	
	Node *lower_bound_(const T &x) const {
		Node *Q = root_node;
		if (!Q) return end_();
		while (true) {
			Node *P = Q->child[Q->value < x];
			if (!P) break;
			Q = P;
		}
		if (!Q) return end_();
		if (Q->value < x) Q = next(Q);
		return Q;
	}
	
	Node *upper_bound_(const T &x) const {
		Node *Q = root_node;
		if (!Q) return end_();
		while (true) {
			Node *P = Q->child[Q->value <= x];
			if (!P) break;
			Q = P;
		}
		if (!Q) return end_();
		if (Q->value <= x) Q = next(Q);
		return Q;
	}
	
	Node *k_th_smallest_(std::size_t k) const {
		if (k == 0 || size_ < k) return end_();
		Node *Q = root_node;
		std::size_t sum = 0;
		while (sum < k) {
			if (sum + Q->size[0] >= k) {
				Q = Q->child[0];
			}
			else {
				sum += Q->size[0];
				++sum;
				if (sum != k) Q = Q->child[1];
			}
		}
		return Q;
	}
	
	Node *k_th_largest_(std::size_t k) const {
		if (k == 0 || size_ < k) return end_();
		return k_th_smallest_(size_ - k + 1);
	}
	
	Node *move(Node *Q, bool d) const {
		if (Q->child[d]) {
			Q = Q->child[d];
			while (Q->child[!d]) Q = Q->child[!d];
		}
		else {
			while (Q && (d ^ !Q->is_r)) Q = Q->par;
			if (Q) Q = Q->par;
		}
		return Q;
	}
};

/*
int main() {
	AVL_tree<int> tree;
	
	const int queryNumber = 11;
	std::string str[queryNumber] = {"clear", "kths", "kthl", "size", "print", "ins", "find", "era", "lower", "upper", "exit"};
	std::set<std::string> ss;
	REP(i, queryNumber) ss.insert(str[i]);
	
	while (true) {
		std::string query;
		std::cin >> query;
		
		if (ss.find(query) == ss.end()) {
			puts("Please input again");
			continue;
		}
		
		if (query == "exit") {
			break;
		}
		if (query == "clear") {
			tree.clear();
		}
		else if (query == "size") {
			printf("size: %d\n", tree.size());
		}
		else if (query == "print") {
			std::vector<int> v = tree.enumerate();
			REP(i, v.size()) printf("%d ", v[i]);
			puts("");
			
		}
		else {
			int num;
			std::cin >> num;
			if (query == "ins") {
				tree.insert(num);
			}
			else if (query == "find") {
				
				std::cout << std::boolalpha << (bool)tree.find(num) << std::endl;
			}
			else if (query == "era") {
				tree.erase(num);
			}
			else if (query == "lower") {
				auto *p = tree.lower_bound(num);
				while (p) {
					printf("%d ", p->value);
					p = tree.next(p);
				}
				puts("");
			}
			else if (query == "upper") {
				auto *p = tree.upper_bound(num);
				while (p) {
					printf("%d ", p->value);
					p = tree.next(p);
				}
				puts("");
			}
			else if (query == "kths") {
				auto *P = tree.k_th_smallest(num);
				if (P) cout << P->value << endl;
			}
			else if (query == "kthl") {
				auto *P = tree.k_th_largest(num);
				if (P) cout << P->value << endl;
			}
		}
		std::vector<int> v = tree.enumerate();
		REP(i, v.size()) printf("%d ", v[i]); puts("");
		if (!tree.empty()) printf("begin: %d, end: %d\n", tree.begin()->value, prev(tree.end())->value);
		
	}
	
	return 0;
}
*/