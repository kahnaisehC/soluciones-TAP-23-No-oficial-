#include<bits/stdc++.h>

using namespace std;


// (1 << 21) + 1
const int MAX = 1048580;
vector<int> inicios;
vector<int> finales;

typedef struct _treap{
	int value;
	int priority;
	_treap* left;
	_treap* right;

}treap;

pair<treap*, treap*> split(treap* t, int key){
	if(t == nullptr)return {nullptr, nullptr};
	treap* leftP;
	treap* rightP;
	if(t->value <= key){
		{leftP, rightP} = split(t->right);
		t->right = leftP;
		return {t, rightP};
	}
	{leftP, rightP} = split(t->left);
	t->left = rightP;
	return {leftP, t};
}

treap* merge(treap* left, treap* right){
	treap* root;
	if(left == nullptr) return right;
	if(right == nullptr) return left;
	if(left->priority > right->priority){
		root = left;
		treap* newRight = merge(left->right, right);
		root->right = newRight;
	}else{
		root = right;
		treap* newLeft = merge(left, right->left);
		root->left = newLeft;
	}
	return root;
}

treap* createNode(int key){
	treap* t = (treap*)malloc(sizeof(treap));
	t->value = key;
	t->priority = rand();
	t->left = nullptr;
	t->right = nullptr;
	return t;
}

treap* insert(treap* t, treap* newNode){
	if(t == nullptr){
		t = newNode;
		return newNode;
	}
	if(t->priority < newNode->priority){
		treap* left;
		treap* right;
		{left, right} = split(t, newNode->value);
		newNode->right = right;
		newNode->left = left;
		return 
	}
}

treap* erase(treap* t, int value){
	if(t == nullptr)return t;
	if(t->value == value){
		treap* newT = merge(t->left, t->right);
		free(t);
		t = nullptr;
		return newT;
	}
	if(t->value > value){
		treap* newTreap = erase(t->right, value);
		t = newTreap;
		return t;
	}
	if(t->value < value){
		treap* newTreap = erase(t->left, value);
		t = newTreap;
		return t;
	}
	return nullptr;
}

typedef struct _treap_of_treaps{
	int x;
	int y;
	int priority;
	treap* tree;
	_treap_of_treaps left;
	_treap_of_treaps right;
}treap_of_treaps;



vector<int> coordenadas;

vector<int> segTreeInicios(MAX);
vector<int> segTreeFinales(MAX);



typedef struct _query{
	char format;
	int id;
	int x;
	int inicio;
	int final;
}Query;

int compress(int coordenada){
	return lower_bound(coordenadas.begin(), coordenadas.end(), coordenada) - coordenadas.begin();
}

// Retorna true si i1-f1 solapa con i2-f2
// asume que i1 < f1 y i2 < f2
bool overlap(int i1, int f1, int i2, int f2){
	return (i2 >= i1 && i2 <= f1 || f2 >= i1 && f2 <= f1|| i2 <= i1 && f2 >= f1);
}

void build(int left, int right, int index, vector<int>&base, vector<int>&segTree){
	if(left == right){
		segTree[index] = base[left];
		return;
	}
	int middle = (right-left)/2+left;
	build(left, middle, index*2, base, segTree);
	build(middle+1, right, index*2+1, base, segTree);
	segTree[index] = segTree[index*2] + segTree[index*2+1];
}

int query(vector<int>&segTree, int left, int right, int tLeft = 0, int tRight = MAX-1, int level = 1){
	if(left > right){
		return 0;
	}
	if(left == tLeft && tRight == right){
		return segTree[level];
	}
	int middle = (tRight-tLeft) /2 + tLeft;
	int leftTree = query(segTree, left, min(right, middle), tLeft, middle, level*2);
	int rightTree = query(segTree, max(middle+1, left), right, middle+1, tRight, level*2+1);
	return leftTree + rightTree;
}

int rangeQuery(int left, int right){
	// C<-right - T<-left
	int iniciosALaIzquierda = query(segTreeInicios, 0, right);


	int finalesALaIzquierda = query(segTreeFinales, 0, left);

	cout << iniciosALaIzquierda << " " << finalesALaIzquierda << endl;
	return iniciosALaIzquierda - finalesALaIzquierda;
}

void update(vector<int>&segTree, int newValue, int prevValue, int index, int level = 1, int tLeft = 0, int tRight = MAX-1){
	// if index is out of range return early
	if((index < tLeft || index > tRight)){
		return;
	}
	// if range == index, assign
	if(tLeft == tRight && tLeft == index){
		segTree[level] = newValue;
		return;
	}
	// update current level
	segTree[level] = segTree[level] - prevValue + newValue;

	int middle = (tRight - tLeft) /2 + tLeft;
	if(index <= middle){
		update(segTree, newValue, prevValue, index, level*2, tLeft, middle);
	}else{
		update(segTree, newValue, prevValue, index, level*2+1, middle+1, tRight);
	}

}


int main(){
	int n, q, h1, h2, w; 
	cin >> n >> q >> h1 >> h2 >> w;

	for(int i = 0; i < n; i++){
		int inicio, final, l, r;
		cin >> inicio >> final >> l >> r;
		inicios.push_back(inicio);
		finales.push_back(final);

		coordenadas.push_back(inicio);
		coordenadas.push_back(final);
	}

	coordenadas.push_back(0);

	vector<Query> queries;



	for(int i = 0; i < q; i++){
		Query q;
		cin >> q.format;
		switch (q.format){
			case 'M':{
				cin >> q.x;
				coordenadas.push_back(q.x);
				coordenadas.push_back(q.x+h1);
				break;
			}
			case 'A':{
				int l, r;
				cin >> q.id >> q.inicio >> q.final >> l >> r;
				// correccion de indices porque se dan comenzando en 1
				q.id--;
				coordenadas.push_back(q.inicio);
				coordenadas.push_back(q.final);
				break;
			}
			case 'D':{
				cin >> q.id;
				// correccion de indices porque se dan comenzando en 1
				q.id--;
				break;
			}
			default:{
				cout << "mal formato" << endl;
				return 1;
			}

		}
		queries.push_back(q);
	}

	set<int> s;
	for(auto coordenada: coordenadas){
		s.insert(coordenada);
	}
	coordenadas.assign(s.begin(), s.end() );

	int tamanoBases = 1;
	while(tamanoBases < coordenadas.size()){
		tamanoBases <<= 1;
	}


	vector<int> baseInicios(tamanoBases, 0);

	for(int i = 0; i < inicios.size(); i++){
		int indiceComprimido = compress(inicios[i]);
		baseInicios[indiceComprimido]++;
	}

	vector<int> baseFinales(tamanoBases, 0);

	for(int i = 0; i < finales.size(); i++){
		int indiceComprimido = compress(finales[i]);
		baseFinales[indiceComprimido]++;
	}


	int left = 0;
	int right = baseInicios.size()-1;
	int index = 1;
	build(left, right, index, baseInicios, segTreeInicios);
	build(left, right, index, baseFinales, segTreeFinales);

	int pantallaInicio = 0;
	int pantallaFinal = h1;

	cout << rangeQuery(0, 2) << endl << endl;;


	for(auto& query: queries){
		switch(query.format){
			case 'M':{
				int nuevoInicio = query.x;
				int nuevoFinal = query.x+h1;

				//La pantalla no se mueve
				if(nuevoInicio == pantallaInicio){
					cout << "0 0" << endl;
				}

				int rangosEnViejo = rangeQuery(pantallaInicio,pantallaFinal); 
				int rangosEnNuevo = rangeQuery(nuevoInicio, nuevoFinal); 
				// la nueva pantalla no overlapea con la vieja y esta a la derecha
				if(nuevoInicio >= pantallaFinal){
					// Saca la unioncita
					int unioncita =  rangeQuery(pantallaInicio, nuevoFinal);

					// Interseccion
					int interseccion = rangosEnViejo + rangosEnNuevo - unioncita;

					int gatosQueAhoraSeVen = rangosEnNuevo - interseccion;
					
					int gatosQueNoSeVen = rangosEnViejo - interseccion;

					cout << gatosQueAhoraSeVen << " " << gatosQueNoSeVen << endl;

				}

				// la nueva Pantalla no overlapea y esta a la izquierda

				if(nuevoFinal <= pantallaInicio){
					// Saca la unioncita
					int unioncita =  rangeQuery(nuevoInicio, pantallaFinal);

					// Interseccion
					int interseccion = rangosEnViejo + rangosEnNuevo - unioncita;

					int gatosQueAhoraSeVen = rangosEnNuevo - interseccion;
					
					int gatosQueNoSeVen = rangosEnViejo - interseccion;

					cout << gatosQueAhoraSeVen << " " << gatosQueNoSeVen << endl;
				}
				
				// se solapan, la pantalla nueva esta a la derecha
				if(nuevoInicio > pantallaInicio && nuevoInicio < pantallaFinal){
					int unioncita = rangeQuery(pantallaInicio, nuevoFinal);

					int gatosQueAhoraSeVen = unioncita - rangosEnViejo;
					int gatosQueAhoraNoSeVen = unioncita - rangosEnNuevo;

					cout << gatosQueAhoraSeVen << " " << gatosQueAhoraNoSeVen << endl;
				}

				// se solapan, la pantalla nueva esta a la izquierda 
				if(nuevoInicio < pantallaInicio && nuevoFinal > pantallaInicio){
					int unioncita = rangeQuery(nuevoInicio, pantallaFinal);

					int gatosQueAhoraNoSeVen = unioncita - rangosEnViejo;
					int gatosQueAhoraSeVen = unioncita - rangosEnNuevo;

					cout << gatosQueAhoraSeVen << " " << gatosQueAhoraNoSeVen << endl;
				}



				pantallaInicio = nuevoInicio;
				pantallaFinal = nuevoFinal;
				break;
			}
			case 'A':{
				inicios.push_back(query.inicio);
				finales.push_back(query.final);

				int inicioComprimido = compress(query.inicio);
				int finalComprimido = compress(query.final);

				int prevInicio = baseInicios[inicioComprimido];
				int newInicio = prevInicio+1;

				int prevFinal = baseFinales[finalComprimido];
				int newFinal = prevFinal+1;

				baseInicios[inicioComprimido]++;
				baseFinales[finalComprimido]++;


				update(segTreeInicios, newInicio, prevInicio, inicioComprimido);
				update(segTreeFinales, newFinal, prevFinal, finalComprimido);


					
				if(overlap(pantallaInicio, pantallaFinal, query.inicio, query.final)){
					cout << "1 0" << endl;
				}else{
					cout << "0 0" << endl;
				}
				break;

			}
			case 'D':{
				int inicio = inicios[query.id];
				int final  = finales[query.id];

				int inicioComprimido = compress(inicio);
				int finalComprimido = compress(final);

				int prevInicio = baseInicios[inicioComprimido];
				int newInicio = prevInicio-1;

				int prevFinal = baseFinales[finalComprimido];
				int newFinal = prevFinal-1;

				baseInicios[inicioComprimido]--;
				baseFinales[finalComprimido]--;

				update(segTreeInicios, newInicio, prevInicio, inicioComprimido);
				update(segTreeFinales, newFinal, prevFinal, finalComprimido);
					
				if(overlap(pantallaInicio, pantallaFinal, inicio, final)){
					cout << "0 1" << endl;
				}else{
					cout << "0 0" << endl;
				}
				break;
			}

		}
	}


	return 0;
}
