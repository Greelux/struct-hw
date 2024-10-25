#include <iostream>
#include <vector>
#include <Windows.h>

struct Point {
    double x, y;

    Point(double x_coord = 0, double y_coord = 0) : x(x_coord), y(y_coord) {}
};

struct Line {
    Point start, end;

    Line(Point p1, Point p2) : start(p1), end(p2) {}
};

struct Figure {
    std::vector<Line> lines;

    void addLine(const Line& line) {
        lines.push_back(line);
    }

    bool isClosed() const {
        if (lines.size() < 3) 

        return false;

        return 
            (lines.front().start.x == lines.back().end.x &&
            lines.front().start.y == lines.back().end.y);
    }
};

int main() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    setlocale(LC_ALL, "");

    Point p1(0, 0);
    Point p2(1, 0);
    Point p3(1, 1);
    Point p4(0, 1);

    Line line1(p1, p2);
    Line line2(p2, p3);
    Line line3(p3, p4);
    Line line4(p4, p1);

    Figure square;
    square.addLine(line1);
    square.addLine(line2);
    square.addLine(line3);
    square.addLine(line4);

    if (square.isClosed()) {
        std::cout << "Фігура є замкнутою." << std::endl;
    }
    else {
        std::cout << "Фігура не є замкнутою." << std::endl;
    }

    return 0;
}
