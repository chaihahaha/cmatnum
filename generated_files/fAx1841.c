#include "fAx1841.h"

inline int fAx1841(pack_mats_22x22 bmats) {
    int BL = bmats.A_1_1.shape[0];
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            bmats.Ax1841.data[i][j] = -12*bmats.A_1_1.data[i][j] + bmats.Ax1267.data[i][j] + bmats.Ax1395.data[i][j] + bmats.Ax1660.data[i][j] + bmats.Ax1716.data[i][j] + bmats.Ax1784.data[i][j] + bmats.Ax1789.data[i][j] + bmats.Ax1806.data[i][j] + bmats.Ax995.data[i][j];
        }
    }
    return 0;
}
