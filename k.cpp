


/*
	vector<int> prefSumStarts(points.size(),0);
	prefSumStarts[points.size()-1] = compStarts[points.size()-1];
	for(int i = points.size()-2; i >= 0; i--){
		prefSumStarts[i] = prefSumStarts[i+1] + compStarts[i];
	}


	vector<int> prefSumEnds(points.size(),0);
	prefSumEnds[0] = compEnds[0];
	for(int i = 1; i < compEnds.size(); i++){
		prefSumEnds[i] = prefSumEnds[i-1] + compEnds[i];
	}

	vector<int> windowSums(
*/



#include<bits/stdc++.h>


using namespace std;


const long long MAX= (1 << 17)+10;

vector<long long> points;

long long comp(int x){
	return lower_bound(polong longs.begin(), points.end(), x) - points.begin();
}

typedef struct{


	int count;
	int tl;
	int tr;

	int lazyV;


	Vertex* left;
	Vertex* right;
}Vertex;

Vertex* createV(int count, int tl, int tr){
	Vertex* v = (Vertex*)malloc(sizeof(Vertex));
	v->count = count;
	v->tl = tl;
	v->tr = tr;
	v->lazyV = 0;
	v->left = nullptr;
	v->right = nullptr;
}

Vertex* build(vector<int>& v, int l, int r){
	if(r == l){
		return createV(v[r], l, r);
	}
	int m = l + (r-l)/2;

	auto left = build(v, l, m);
	auto right = build(v, m+1, r);

	auto v = createV(0, l, r);
	v->count = left->count+right->count;
	v->left = left;
	v->right = right;
	return v;
}

int update(Vertex* v, int ql, int qr, int qv){
	int tl = v->tl;
	int tr = v->tr;


	if(ql > tr || qr < tl)return;
	if(tl == tr){
		v->count+=qv;
		return v->count;
	}
	if(ql == tl && qr == tr){
		v->count += qv;
		lazyV += qv;
		return v->count;
	}
	int tm = tl + (tr-tl)/2;
	qv += v->lazyV;
	v->lazyV = 0;
	v->count += qv;

	update(v->left, ql, min(qr, tm), qv);
	update(v->right, max(tm+1,ql), qr, qv);

	return v->count;
}

typedef struct {
	char t;
	int s, e;
	int j;
	int x;
}query;

int main(){
	int n, q, h1, h2, w;
	cin >> n >> q >> h1 >> h2 >> w;
	vector<int> starts(n);
	vector<int> ends(n);
	points.push_back(h1);
	points.push_back(h2);

	for(int i = 0;i < n; i++){
		int l, r;
		cin >> starts[i] >> ends[i] >> l >> r;
		points.push_back(starts[i]);
		points.push_back( ends[i]);
	}

	for(int i = 0; i < q; i++){
		query q;
		cin >> q.t;
		switch (q.t){
			case 'A':
				int l, r;
				cin >> q.s >> q.e >> l >> r;
				points.push_back(q.s);
				points.push_back(q.e);
			break;
			case 'D':
				cin >> q.j;
			break;
			case 'M':
				cin >> q.x;
				points.push_back(q.x);
				points.push_back(q.x+h1);
			break;
		}
		queries.push_back(q);
	}

	set<int>pointSet;
	for(auto& a: points)pointSet.insert(a);
	points.assign(pointSet.begin(), pointSet.end());

	vector<int> compStarts(n,0);
	int i =0;
	for(auto& s: starts){
		int compS = comp(s);
		compStarts[i] = compS;
		i++;
	}

	vector<int> compEnds(n, 0);
	i = 0;
	for(auto& e: ends){
		int compE = comp(e);
		compEnds[i] = compE;
		i++;
	}

	vector<int> x(points.size(), 0);
	auto v = build(x, 0, x.size()-1);

	for(int i = 0; i < compStarts.size(); i++){
		update(v, compStarts[i], compEnds[i], 1);
	}


	int currX = 0;
	for(auto& q: queries){
		switch (q.t){
			case 'A':
				q.s;
				q.e;
				int compS = comp(q.s);
				int compE = comp(q.e);
				cout << update(v, compS, compE, 1);
			break;
			case 'D':
			break;
			case 'M':
			break;
		}
		queries.push_back(q);
	}


	return 0;
}
