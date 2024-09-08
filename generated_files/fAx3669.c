#include "fAx3669.h"

inline int fAx3669(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            bmats.Ax3669.data[i][j] = -16*bmats.A_17_23.data[i][j] + bmats.A_17_24.data[i][j] - 16*bmats.A_18_23.data[i][j] + bmats.A_18_24.data[i][j] - 16*bmats.A_20_23.data[i][j] + bmats.A_20_24.data[i][j] - 16*bmats.A_21_23.data[i][j] + bmats.A_21_24.data[i][j] - 16*bmats.A_22_23.data[i][j] + bmats.A_22_24.data[i][j] - 16*bmats.A_24_23.data[i][j] + bmats.A_24_24.data[i][j] - 16*bmats.A_25_23.data[i][j] + bmats.A_25_24.data[i][j] - 16*bmats.A_26_23.data[i][j] + bmats.A_26_24.data[i][j] - 16*bmats.A_27_23.data[i][j] + bmats.A_27_24.data[i][j] - 16*bmats.A_28_23.data[i][j] + bmats.A_28_24.data[i][j] - 16*bmats.A_29_23.data[i][j] + bmats.A_29_24.data[i][j] - 16*bmats.A_30_23.data[i][j] + bmats.A_30_24.data[i][j] - 16*bmats.A_31_23.data[i][j] + bmats.A_31_24.data[i][j] - 16*bmats.A_32_23.data[i][j] + bmats.A_32_24.data[i][j] + bmats.Ax115.data[i][j] + bmats.Ax1370.data[i][j] + bmats.Ax2031.data[i][j] + bmats.Ax321.data[i][j] + bmats.Ax3381.data[i][j] + bmats.Ax3384.data[i][j] + bmats.Ax340.data[i][j] + bmats.Ax347.data[i][j] + bmats.Ax350.data[i][j] + bmats.Ax354.data[i][j] + bmats.Ax50.data[i][j] + bmats.Ax7.data[i][j] + bmats.Ax79.data[i][j] + bmats.Ax82.data[i][j];
        }
    }
    return 0;
}
