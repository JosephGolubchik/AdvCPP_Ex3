#include "Circle.h"
#include "Triangle.h"
#include <vector>
#include <iostream>
#include "MM.h"
using namespace std;
extern MemoryManager mm;

int main()
{
   cout << sizeof(Circle) << " " << sizeof(Triangle) << endl;
Shape* circles[1000];
Shape* triangles[1000];
   cout << mm.free_circles() << " " << mm.free_circles() << endl;
//for (int i = 0;i < 200; i++) {
   for (int j = 0; j < 1000; j++) {
      circles[j] = new Circle(3.2,Point(1.8,2.5));
      triangles[j] = new Triangle({0,0},{0,2},{2,0});
   }
   cout << mm.free_circles() << " " << mm.free_circles() << endl;
   for (int j = 0; j < 1000; j++) {
      delete circles[j];
      delete triangles[j];
   }
//}
   cout << mm.free_circles() << " " << mm.free_circles() << endl;
   for (int j = 0; j < 10; j++) {
      circles[j] = new Circle(3.2,Point(1.8,2.5));
      triangles[j] = new Triangle({0,0},{0,2},{2,0});
   }
   cout << mm.free_circles() << " " << mm.free_circles() << endl;
   cout << static_cast<int>(circles[5]->area()) << " "
	<< static_cast<int>(circles[5]->area()) << endl;
   cout << triangles[5]->area() << " " << triangles[9]->area() << endl;
   for (int j = 0; j < 10; j++) {
      delete circles[j];
      delete triangles[j];
   }
   cout << mm.free_circles() << " " << mm.free_circles() << endl;
return 0;
}
