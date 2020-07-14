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

void TetrixPiece::setSquareShape()
{
    setShape(TetrixShape(1));
}

void TetrixPiece::setShape(TetrixShape shape)
{
    static constexpr int coordsTable[2][4][2] = {
        { { 0, 0 }, { 0, 0 }, { 0, 0 }, { 0, 0 } },
        { { 1, 1 }, { 0, 0 }, { 0, 0 }, { 0, 0 } }
    };

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 2; ++j)
            coords[i][j] = coordsTable[shape][i][j];
    }
    pieceShape = shape;
}



