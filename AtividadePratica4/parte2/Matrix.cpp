#include "matrix.h"

Matrix::Matrix(){};

Matrix::Matrix(int rows, int cols, const double &value = 0.0){};

Matrix::Matrix(ifstream &myFile){};

Matrix::Matrix(const Matrix &that){};

Matrix::~Matrix(){};

int Matrix::getRows() const {};

int Matrix::getCols() const {};

double Matrix::get(int row, int col) const {};

void Matrix::print() const {};

void Matrix::unit(){};

void Matrix::zeros(){};

void Matrix::ones(){};