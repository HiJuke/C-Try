#include "circle.h"


double Circle::calculateZC() {
	return 2 * pi * m_r;
}
double Circle::calculateZP() {
	return m_r * pi * m_r;
}
void Circle::SetR(int R) {
	m_r = R;
}
void Circle::SetC(Point C) {
	m_Center = C;
}
int Circle::GetR() { return m_r; }
Point Circle::GetC() { return m_Center; }

void Circle::isInCircle(Point& p) {
	int tX = p.getX() - m_Center.getX();
	int tY = p.getY() - m_Center.getY();
	int tR = tX * tX + tY * tY;
	if (tR > m_r * m_r) {
		cout << "Outside the Circle" << endl;
	}
	else if (tR == m_r * m_r) {
		cout << "On the Circle" << endl;
	}
	else {
		cout << "In the Circle" << endl;
	}
}


