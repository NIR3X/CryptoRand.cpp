#include "Mouse.h"

bool CMouse::GetPos(UMousePos& pos) {
    return GetCursorPos(&pos.point);
}
