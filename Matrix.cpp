#include <vector>
#include <iostream>
using std::vector;
using std::cout;
using std::endl;

class Matrix {
private:
    vector<vector<double>> val;

public:
    Matrix(int x, int y) : val(x, vector<double>(y)) {}

    const vector<double>& get_row(int x) const {
        return val[x];
    }

    vector<double> get_column(int y) const {
        vector<double> column;
        for (const auto& row : val) {
            column.push_back(row[y]);
        }
        return column;
    }

    double get_value(int x, int y) const {
        return val[x][y];
    }

    void set_value(int x, int y, double value) {
        val[x][y] = value;
    }
};

int main() {
    Matrix matrix(2, 2);

    matrix.set_value(0, 0, 1.0);
    matrix.set_value(0, 1, 0.0);
    matrix.set_value(1, 0, 0.0);
    matrix.set_value(1, 1, 1.0);

    cout << "Matrix:" << endl;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) { 
            cout << matrix.get_value(i, j) << " ";
        }
        cout << endl;
    }

    // faire exemple ligne colonne

    return 0;
}
