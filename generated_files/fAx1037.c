#include "fAx1037.h"

inline int fAx1037(pack_mats_22x22 bmats) {
    int BL = bmats.A_1_1.shape[0];
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            bmats.Ax1037.data[i][j] = bmats.A_12_15.data[i][j] - 11*bmats.A_12_16.data[i][j] + bmats.A_13_15.data[i][j] - 11*bmats.A_13_16.data[i][j] + bmats.A_14_15.data[i][j] - 11*bmats.A_14_16.data[i][j] + bmats.A_15_15.data[i][j] - 11*bmats.A_15_16.data[i][j] - 12*bmats.A_16_16.data[i][j] + bmats.A_17_15.data[i][j] - 11*bmats.A_17_16.data[i][j] + bmats.A_18_15.data[i][j] - 11*bmats.A_18_16.data[i][j] + bmats.A_19_15.data[i][j] - 11*bmats.A_19_16.data[i][j] + bmats.A_22_15.data[i][j] - 11*bmats.A_22_16.data[i][j] + bmats.Ax742.data[i][j] + bmats.Ax848.data[i][j] + bmats.Ax852.data[i][j] + bmats.Ax861.data[i][j] + bmats.Ax864.data[i][j] + bmats.Ax867.data[i][j] + bmats.Ax870.data[i][j] + bmats.Ax913.data[i][j];
        }
    }
    return 0;
}
