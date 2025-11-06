#include <string>
#include <vector>
#include <cmath>

using namespace std;

int solution(vector<vector<int>> dots) {
    int x1 = dots[0][0], y1 = dots[0][1];
    int width, height;
    for (int i = 1; i < dots.size(); ++i) {
        int x = dots[i][0];
        int y = dots[i][1];
        if (x1 != x) width = abs(x1 - x);
        if (y1 != y) height = abs(y1 - y);
    }
    return width * height;
}