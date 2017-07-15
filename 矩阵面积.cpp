#include <iostream>

using namespace std;

/*
实现一个矩阵类Rectangle，包含如下的一些成员变量与函数：

两个共有的成员变量 width 和 height 分别代表宽度和高度。
一个构造函数，接受2个参数 width 和 height 来设定矩阵的宽度和高度。
一个成员函数 getArea，返回这个矩阵的面积。
*/


class Rectangle
{
public:
	int width;
	int height;
	Rectangle(int _width,int _height) {
		width = _width;
		height = _height;
	};

	int getArea() {
		return width*height;
	};
	
};


int main(int argc, char const *argv[])
{
	Rectangle *rec = new Rectangle(3,5);
	int result = rec->getArea();
	cout << result << endl;
	return 0;
}