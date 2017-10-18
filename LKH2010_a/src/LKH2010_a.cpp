#include <iostream>
#include <vector>
#include <queue>
using namespace std;



struct Element {
	Element(string name) {
		this->name = name;
		step = -1;
	}
	string name;
	int step;

};

struct Sviaz {
	int first;
	int last;
};

int find(string str, vector<Element>& vec);

int main() {
	unsigned m;
	cin >> m;
	vector<Element> elements;
	Sviaz* sviazi = new Sviaz[m];
	for(unsigned i = 0;i<m;i++) {
		string first, last;
		cin >> first >> last >> last;
		sviazi[i].first = find(first,elements);
		sviazi[i].last = find(last,elements);
	}

	string str;
	cin >> str;
	int beg,end;
	beg = find(str,elements);
	cin >> str;
	end = find(str,elements);
	queue<int> nums;
	elements[beg].step = 0;
	nums.push(beg);
	while(!nums.empty()) {
		int t;
		t = nums.front();
		nums.pop();
		for(unsigned i =0;i<m;i++) {
			if(t == sviazi[i].first && elements[sviazi[i].last].step == -1) {
				nums.push(sviazi[i].last);
				elements[sviazi[i].last].step=elements[t].step+1;
			}
		}
	}
//	for (unsigned i = 0; i < m; i++) {
//		cout << elements[sviazi[i].first].name << ' '
//				<< elements[sviazi[i].first].step << ' '
//				<< elements[sviazi[i].last].name << ' '
//				<< elements[sviazi[i].last].step << endl;
//	}
	cout<<elements[end].step<<endl;
	return 0;
}

int find(string str, vector<Element>& vec) {
	for(unsigned i = 0;i<vec.size();i++) {
		if(str == vec[i].name) {
			return i;
		}
	}
	vec.push_back(Element(str));
	return vec.size() - 1;
}
