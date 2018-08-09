#include<iostream>
#include<vector>

#define infinite 1000

using namespace std;



struct Point{
	int x;
	int y;
};

int direction(Point p1, Point p2, Point p3){
	int x1 = p1.x - p2.x;
	int y1 = p1.y - p2.y;

	int x2 = p2.x - p3.x;
	int y2 = p2.y - p3.y;
	return ((x1*y2) - (x2*y1));
}

bool onSegment(Point p1, Point p2, Point p3){
	bool result = false;
	//cout<<"Inside onSegment()"<<endl;
	//cout<<p1.x<<" "<<p1.y<<endl;
	//cout<<p2.x<<" "<<p2.y<<endl;
	//cout<<p3.x<<" "<<p3.y<<endl;
	
	if ((min(p1.x, p2.x) <= p3.x <= max(p1.x, p2.x)) &&
		(min(p1.y, p2.y) <= p3.y <= max(p1.y, p2.y)))
		result = true;
	if(result)
		cout<<"onSegment"<<endl;
	return result;
}

bool doLinesIntersect(Point ptA, Point ptB, Point chkA, Point chkB, int &isPointOnEdge){
	static int j = 0;
	bool intersect = true;
    int d1 = direction(ptA, ptB, chkA);
    int d2 = direction(ptA, ptB, chkB);
    int d3 = direction(chkA, chkB, ptA);
    int d4 = direction(chkA, chkB, ptB);
    //cout<<++j<<endl;
    //cout<<d1<<" "<<d2<<" "<<d3<<" * "<<d4<<endl;
    //if ((d1 * d2 < 0) && (d3 *d4 < 0))
    //	return true;
    ///*
    if(((d1 > 0 && d2 < 0) ||(d2 > 0 && d1 < 0))&&
    	((d3 > 0 && d4 < 0) ||(d4 > 0 && d3 < 0)))
    	return true;
    //	*/
    if (d1 ==0 && onSegment(ptA, ptB, chkA)){
    	isPointOnEdge = 1;
    	return true;
    }
    if (d2 ==0 && onSegment(ptA, ptB, chkB)){
    	isPointOnEdge = 1;
    	return true;
    }
    if (d3 ==0 && onSegment(chkA, chkB, ptA)){
    	isPointOnEdge = 1;
    	return true;
    }
    if (d4 ==0 && onSegment(chkA, chkB, ptB)){
    	isPointOnEdge = 1;
    	return true;
    }
    return false;
}

bool isPointInside(Point points[], Point check, int n){
	bool result = false;
	bool intersect = false;
	int isPointOnEdge = 0;
	Point exterme = {1000, check.y};
	int cnt = 0; // Counter for no of lines intersect with the line (check, exterme)
	int i = 0;
	for(; i < n; i++){
		if(i == n-1)
			intersect = doLinesIntersect(points[i],points[0], check, exterme, isPointOnEdge);
		else
			intersect = doLinesIntersect(points[i],points[i+1], check, exterme, isPointOnEdge);

		if(intersect){
			cnt++;
			if(isPointOnEdge){
				cnt = 1; // As the point is on the line, it is considered as inside the line
				break;
			}
		}
	}

	//cout<<cnt<<" "<<(cnt&1)<<endl;
	if (cnt&1)
		result = true;
	
	return result;
}

//It will not work for a corner case. A point outside the polygon just passing one
//edge of the polygon

int main(){
	Point points[] = {{1, 1}, {4, 1}, {4, 4}, {1, 4}};
	int n = sizeof(points)/sizeof(points[0]);
	cout<<"No of sides "<<n<<endl;
	Point check = {5,5};
	Point check1 = {1,3};
	Point check2 = {0,3};
	Point check3 = {2,3};
	//Point check = {-1,3};
	cout<<(isPointInside(points, check, n) ? "Yes":"No")<<endl;
	cout<<(isPointInside(points, check1, n) ? "Yes":"No")<<endl;
	cout<<(isPointInside(points, check2, n) ? "Yes":"No")<<endl;
	cout<<(isPointInside(points, check3, n) ? "Yes":"No")<<endl;

	Point points1[] = {{2, 1}, {6, 1}, {4, 4}};
	n = sizeof(points)/sizeof(points[0]);
	cout<<"Now its a triangle"<<endl;
	check = {4, 1};
	check1 = {1,4};
	check2 = {1,4};
	cout<<(isPointInside(points1, check, n) ? "Yes":"No")<<endl;
	cout<<(isPointInside(points1, check1, n) ? "Yes":"No")<<endl;
	cout<<(isPointInside(points1, check2, n) ? "Yes":"No")<<endl;


}