#include "fAx1815.h"

inline int fAx1815(pack_mats_22x22 bmats) {
    int BL = bmats.A_1_1.shape[0];
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            bmats.Ax1815.data[i][j] = bmats.Ax1265.data[i][j] + bmats.Ax1393.data[i][j] + bmats.Ax1658.data[i][j] + bmats.Ax1714.data[i][j] + bmats.Ax1794.data[i][j] + bmats.Ax1797.data[i][j] + bmats.Ax1799.data[i][j] + bmats.Ax1814.data[i][j] + bmats.Ax81.data[i][j] + bmats.Ax993.data[i][j];
        }
    }
    return 0;
}
