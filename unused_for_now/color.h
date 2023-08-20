//
// Created by Aurelien Levra on 20/08/2023.
//

#ifndef XENLOU_COLOR_H
#define XENLOU_COLOR_H

class color {
public:
	color();
	color(int r, int g, int b, int a);
	~color();

	int getR() const;
	int getG() const;
	int getB() const;
	int getA() const;

	void setR(int r);
	void setG(int g);
	void setB(int b);
	void setA(int a);

private:
	int _r;
	int _g;
	int _b;
	int _a;
};

#endif //XENLOU_COLOR_H
