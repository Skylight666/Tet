#include "tetrixpiece.h"

#include <QtCore>

void TetrixPiece::setRandomColor()
{
    setColor(QRandomGenerator::global()->bounded(3) + 1);
}

void TetrixPiece::setColor(int idxInTable)
{
    static constexpr QRgb colorTable[4] = {
    0x000000, 0xCC6666, 0x66CC66, 0x6666CC
    };
    pieceColor = colorTable[idxInTable];
}

QColor TetrixPiece::getColor()
{
    return pieceColor;
}

void TetrixPiece::setRandomShape()
{
    setShape(TetrixShape(9));
}

void TetrixPiece::setShape(TetrixShape shape)
{
    static constexpr int coordsTable[9][4][2] = {
        { { 0, 0 },   { 0, 0 },   { 0, 0 },   { 0, 0 } },
        { { 0, -1 },  { 0, 0 },   { -1, 0 },  { -1, 1 } },
        { { 0, -1 },  { 0, 0 },   { 1, 0 },   { 1, 1 } },
        { { 0, -1 },  { 0, 0 },   { 0, 1 },   { 0, 2 } },
        { { -1, 0 },  { 0, 0 },   { 1, 0 },   { 0, 1 } },
        { { 0, 0 },   { 1, 0 },   { 0, 1 },   { 1, 1 } },
        { { -1, -1 }, { 0, -1 },  { 0, 0 },   { 0, 1 } },
        { { 1, -1 },  { 0, -1 },  { 0, 0 },   { 0, 1 } },
        { { 1, 1 },  { 0, 0 },  { 0, 0 },   { 0, 0 } }
    };

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 2; ++j)
            coords[i][j] = coordsTable[shape][i][j];
    }
    pieceShape = shape;
}

int TetrixPiece::minX() const
{
    int min = coords[0][0];
    for (int i = 1; i < 4; ++i)
        min = qMin(min, coords[i][0]);
    return min;
}

int TetrixPiece::maxX() const

{
    int max = coords[0][0];
    for (int i = 1; i < 4; ++i)
        max = qMax(max, coords[i][0]);
    return max;
}

int TetrixPiece::minY() const
{
    int min = coords[0][1];
    for (int i = 1; i < 4; ++i)
        min = qMin(min, coords[i][1]);
    return min;
}

int TetrixPiece::maxY() const
{
    int max = coords[0][1];
    for (int i = 1; i < 4; ++i)
        max = qMax(max, coords[i][1]);
    return max;
}


