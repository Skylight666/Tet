#pragma once
#include <QColor>

enum TetrixShape {
    NoShape, ZShape, SShape, LineShape, TShape, SquareShape,
    LShape, MirroredLShape, Kek
};

class TetrixPiece
{
public:
    TetrixPiece() { setShape(NoShape); }

    void setRandomColor();
    void setRandomShape();

    void setShape(TetrixShape shape);
    void setColor(int idxInTable);

    QColor getColor();

    TetrixShape shape() const { return pieceShape; }
    int x(int index) const { return coords[index][0]; }
    int y(int index) const { return coords[index][1]; }
    int minX() const;
    int maxX() const;
    int minY() const;
    int maxY() const;

private:
    void setX(int index, int x) { coords[index][0] = x; }
    void setY(int index, int y) { coords[index][1] = y; }

    QColor pieceColor;
    TetrixShape pieceShape;
    int coords[4][2];
};
