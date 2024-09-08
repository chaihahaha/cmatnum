#include "fAx3419.h"

inline int fAx3419(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            bmats.Ax3419.data[i][j] = bmats.A_17_7.data[i][j] - 16*bmats.A_17_8.data[i][j] + bmats.A_18_7.data[i][j] - 16*bmats.A_18_8.data[i][j] + bmats.A_19_7.data[i][j] - 16*bmats.A_19_8.data[i][j] + bmats.A_20_7.data[i][j] - 16*bmats.A_20_8.data[i][j] + bmats.A_21_7.data[i][j] - 16*bmats.A_21_8.data[i][j] + bmats.A_22_7.data[i][j] - 16*bmats.A_22_8.data[i][j] + bmats.A_23_7.data[i][j] - 16*bmats.A_23_8.data[i][j] + bmats.A_24_7.data[i][j] - 16*bmats.A_24_8.data[i][j] + bmats.A_25_7.data[i][j] - 16*bmats.A_25_8.data[i][j] + bmats.A_26_7.data[i][j] - 16*bmats.A_26_8.data[i][j] + bmats.A_27_7.data[i][j] - 16*bmats.A_27_8.data[i][j] + bmats.A_28_7.data[i][j] - 16*bmats.A_28_8.data[i][j] + bmats.A_29_7.data[i][j] - 16*bmats.A_29_8.data[i][j] + bmats.A_30_7.data[i][j] - 16*bmats.A_30_8.data[i][j] + bmats.A_31_7.data[i][j] - 16*bmats.A_31_8.data[i][j] + bmats.A_32_7.data[i][j] - 16*bmats.A_32_8.data[i][j] + bmats.Ax1422.data[i][j] + bmats.Ax2109.data[i][j] + bmats.Ax2454.data[i][j] + bmats.Ax2726.data[i][j] + bmats.Ax3002.data[i][j] + bmats.Ax3322.data[i][j] + bmats.Ax3390.data[i][j] + bmats.Ax3393.data[i][j] + bmats.Ax3396.data[i][j] + bmats.Ax3399.data[i][j] + bmats.Ax3402.data[i][j] + bmats.Ax3405.data[i][j] + bmats.Ax3408.data[i][j] + bmats.Ax3411.data[i][j] + bmats.Ax3414.data[i][j] + bmats.Ax3417.data[i][j];
        }
    }
    return 0;
}
