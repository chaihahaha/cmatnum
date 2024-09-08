#include "fAx1778.h"

inline int fAx1778(pack_mats_22x22 bmats) {
    int BL = bmats.A_1_1.shape[0];
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            bmats.Ax1778.data[i][j] = bmats.Ax1263.data[i][j] + bmats.Ax1391.data[i][j] + bmats.Ax1656.data[i][j] + bmats.Ax1768.data[i][j] + bmats.Ax1770.data[i][j] + bmats.Ax1772.data[i][j] + bmats.Ax1774.data[i][j] + bmats.Ax1776.data[i][j] + bmats.Ax1777.data[i][j] + bmats.Ax41.data[i][j] + bmats.Ax991.data[i][j];
        }
    }
    return 0;
}
