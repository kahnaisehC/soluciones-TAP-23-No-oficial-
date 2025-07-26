#include<bits/stdc++.h>
using namespace std;

const int MAXN = 2*1e5+100;

vector<long long> ini(0);
vector<long long> fin(0);
vector<long long> stini(4*MAXN, 0);
vector<long long> stfin(4*MAXN, 0);

//_______compresion__________
int ind(long long x, vector<long long> &imp){
  return lower_bound(imp.begin(), imp.end(), x)-imp.begin();
}


//___________ST__________
void recalculate(int nodo, vector<long long> &st){//no deberia darle solo el nodo a recaulcualr?
  st[nodo] = st[2*nodo] + st[2*nodo+1];
}

void build(int nodo, int left, int right, vector<long long> &st, vector<long long> &v){
  if(left == right) st[nodo] = v[left];//pensa que left y right son los indices y van de 0 a n-1. cuando coinciden, ese es el valor que queres guardar
  else{
    int mid = (left + right)/2;
    build(2*nodo, left, mid, st, v);
    build(2*nodo+1, mid+1, right, st, v);
    recalculate(nodo, st);
  }
}

long long query(int nodo, int left, int right, int lq, int rq, vector<long long> &st){
  if(left >=lq and right <=rq) return st[nodo];
  long long ans = 0;
  int mid = (left + right)/2;
  if(lq <= mid) ans+= query(2*nodo, left, mid, lq, rq, st);
  if(rq >= mid+1) ans+= query(2*nodo+1, mid+1, right, lq, rq, st);
  return ans;
}

void update(int nodo, int left, int right, int n, int x, vector<long long> &st){
  if(left == right) st[nodo] += x;
  else{
    int mid = (left+right)/2;
    if(n <= mid) update(2*nodo, left, mid, n, x, st);
    else update(2*nodo+1, mid+1, right, n, x, st);
    recalculate(nodo, st);
  }
}
 //YA TENGO LOS DOS ST FUNCIONALES, DEBO HACEER EL RESTO DEL PROBLEMA...
int main(){
  int N, Q; 
  long long h1, h2, w; cin >> N >> Q >> h1 >> h2 >> w;
  vector<pair<long long, long long> > rangos(N);//aca vo a guardar los extremos de cada segmento
  vector<pair<int, int> > operacion(Q);//indica si la operacion es agregar(1), eliminar(2), mover(3)
  for(int i = 0; i < n; i++){
    long long u, d, l, r; cin >> u >> d >> l >> r; rangos[i] = {u, d};//guardo el inicio y el fin de cada cuadrito(miro los cuadritos como segmentos pues no importa el ancho)
    ini.push_back(u);
    fin.push_back(d);
  }
    for(int i = 0; i < Q; i++){//PRIMERO GUARDO LAS OPERACIONES
      string g; cin >> g;
      if(g == "A"){//operacion agregar
        long long u, d, l, r, j; cin >> j >> U >> d >> l >> r; rangos.push_back({u, d});
        operaciones[i] = {1, j};//guardo tipo de operacion e id de foto a eliminar
        ini.push_back(u);
        fin.push_back(d);
      }
      if(g == "D"){//operacion eliminar
      long long j; cin >> j;
        operaciones[i] = {2, j};
      }
      if(g == "M"){
        long long x; cin >> x;
        operaciones[i] = {3, x}
        ini.push_back(x);
        fin.push_back(x+h1);//por que las agrego? en si no son inicios ni finales, pero creo que asi va a ser mas facil 
      }
    }
    //ARREGLO INI Y FIN Y ARMO EL ST()
    sort(ini.begin(), ini.end());
    sort(fin.begin(), fin.end());
    ini.erase(
      unique(ini.begin(), ini.end()), ini.end()
      );
    fin.erase(
      unique(fin.begin(), fin.end()), fin.end()
      );
    //Armo los st iniciales:
    
    
}










