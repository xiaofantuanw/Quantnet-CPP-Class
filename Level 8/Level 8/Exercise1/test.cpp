/*test.cpp
* author:Tengxiao Fan
* This is a program testing "smart" pointers in boost class.
*/

#include "boost/shared_ptr.hpp"
#include "Array.hpp"
#include "ArrayException.hpp"
#include "Shape.hpp"
#include "Point.hpp"
#include "Line.hpp"
#include "Circle.hpp"
// Typedef for a shared pointer to shape and
// a typedef for an array with shapes stored as shared pointers.
typedef boost::shared_ptr<Shape> ShapePtr;
typedef Array<ShapePtr> ShapeArray;

int main()
{
	ShapeArray arr1(3);//Build a shape array with 3 shapes
	ShapePtr point1(new Point(3, 3)),line1(new Line(Point(0,0),Point(1,1))),circle1(new Circle(Point(0,0),3));
	//Build three pointers to different shapes and put them in the array
	arr1[0] = point1;
	arr1[1] = line1;
	arr1[2] = circle1;
	for (int i = 0;i < 3;i++)
	{
		(*arr1[i]).Draw();//Print(draw) the three shapes using virtual function.
	}
	//The destructors of the shapes are called automatically.
	return 0;
}