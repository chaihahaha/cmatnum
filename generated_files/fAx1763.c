#include "fAx1763.h"

inline int fAx1763(pack_mats_22x22 bmats) {
    int BL = bmats.A_1_1.shape[0];
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            bmats.Ax1763.data[i][j] = bmats.Ax1.data[i][j] + bmats.Ax1261.data[i][j] + bmats.Ax1389.data[i][j] + bmats.Ax1654.data[i][j] + bmats.Ax1753.data[i][j] + bmats.Ax1755.data[i][j] + bmats.Ax1757.data[i][j] + bmats.Ax1759.data[i][j] + bmats.Ax1761.data[i][j] + bmats.Ax1762.data[i][j] + bmats.Ax989.data[i][j];
        }
    }
    return 0;
}
