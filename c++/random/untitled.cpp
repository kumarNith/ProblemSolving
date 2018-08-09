bool doLinesIntersect(Point ptA, Point ptB, Point chkA, Point chkB){
	bool intersect = true;
	/*
	int x1 = ptB.x -  ptA.x;
	int y1 = ptB.y -  ptA.y;

	int x2 = ptB.x -  chkA.x;
	int y2 = ptB.y -  chkA.y;

	int x3 = ptB.x -  chkB.x;
	int y3 = ptB.y -  chkB.y;

	int x11 = chkB.x -  chkA.x;
	int y11 = chkB.y -  chkA.y;

	int x12 = chkB.x -  ptA.x;
	int y12 = chkB.y -  ptA.y;

	int x13 = chkB.x -  ptB.x;
	int y13 = chkB.y -  ptB.y;

	int a = (x1*y2) - (y1*x2);
	int b = (x1*y3) - (y1*x3);
	int c = (x11*y12) - (y11*x12);
	int d = (x11*y13) - (y11*x13);*/
	

	/*
	if (a == 0 && ((ptA.x<=chkA.x <= ptB.x || ptB.x<=chkA.x <= ptA.x)) ||
					(ptA.y<=chkA.y <= ptB.y || ptB.y<=chkA.y <= ptA.y))
		return intersect;
	if (b == 0 && ((ptA.x<=chkB.x <= ptB.x || ptB.x<=chkB.x <= ptA.x)) ||
					(ptA.y<=chkB.y <= ptB.y || ptB.y<=chkB.y <= ptA.y))
		return intersect;
	if (c == 0 && ((chkA.x<=ptA.x <= chkB.x || chkB.x<=ptA.x <= chkA.x)) ||
					(chkA.y<=ptA.y <= chkB.y || chkB.y<=ptA.y <= chkA.y))
		return intersect;
	if (d == 0 && ((chkA.x<=ptB.x <= chkB.x || chkB.x<=ptB.x <= chkA.x)) ||
					(chkA.y<=ptB.y <= chkB.y || chkB.y<=ptB.y <= chkA.y))
		return intersect;
	*/

	cout<<"a is "<<a<<" b is : "<<b<<" a*b is :"<<a*b<<endl;
	cout<<"c is "<<c<<" d is : "<<d<<" c*d is :"<<c*d<<endl;
	//if (a*b < 0 && c*d < 0){
	if((a*b) > 0){
		cout<<"***123***"<<endl; 
		//intersect = true;
	}
	else
		intersect = false;

	return intersect;
}