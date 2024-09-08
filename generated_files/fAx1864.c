#include "fAx1864.h"

inline int fAx1864(pack_mats_22x22 bmats) {
    int BL = bmats.A_1_1.shape[0];
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            bmats.Ax1864.data[i][j] = -12*bmats.A_12_12.data[i][j] + bmats.Ax1265.data[i][j] + bmats.Ax1658.data[i][j] + bmats.Ax1714.data[i][j] + bmats.Ax1794.data[i][j] + bmats.Ax1797.data[i][j] + bmats.Ax1814.data[i][j] + bmats.Ax81.data[i][j] + bmats.Ax993.data[i][j];
        }
    }
    return 0;
}
