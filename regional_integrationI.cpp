#include<bits/stdc++.h>

using namespace std;

typedef struct _circle{
	int x;
	int y;
	int r;
	double distanceToSquare;
	double distanceToTriangle;
}circle;

typedef struct _square{
	int x1;
	int x2;
	int y1;
	int y2;
}square;

typedef struct _triangle{
	int x1;
	int x2;
	int x3;

	int y1;
	int y2;
	int y3;

	double distanceToSquare;
}triangle;




int main(){
	int amountOfCircles, amountOfSquares, amountOfTriangles;
	cin >> amountOfCircles >> amountOfSquares >> amountOfTriangles;

	vector<circle> circles;
	vector<square> squares;
	vecot<triangle> triangle;

	for(int i = 0; i < amountOfCircles; i++){
		circle c;
		cin >> c.x >> c.y >> c.r;
		circles.push_back(c);
	}

	for(int i = 0; i < amountOfSquares; i++){
		square s;
		cin >> s.x1 >> s.y1;
		cin >> s.x2 >> s.y2;
		squares.push_back(s);

	}

	for(int i = 0; i < amountOfTriangles; i++){
		triangle t;
		cin >> t.x1 >> t.y1;
		cin >> t.x2 >> t.y2;
		cin >> t.x3 >> t.y3;
		triangles.push_back(t);
	}

	double min = DBL_MAX;
	for(auto& t: triangles){
		t.distanceToSquare = DBL_MAX;
		for(auto& s: squares){
			t.distanceToSquare = min(t.distanceToSquare, distanceTriangleSquare(t, s));
		}
		mn = min(mn, t.distanceToSquare);
	}
	for(auto& c: circles){
		c.distanceToSquare = DBL_MAX;
		c.distanceToTriangle = DBL_MAX;
		for(auto& s: squares){
			c.distanceToSquare = min(c.distanceToSquare, distanceCircleSquare(c, s));
		}
		for(auto& t: triangles){
			c.distanceToTriangle = min(c.distanceToTriangle, distanceCircleTriangle(c, s);
		}
		mn = min(mn, c.distanceToSquare+c.distance.ToTriangle);
	}



	return 0;
}
