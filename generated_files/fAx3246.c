#include "fAx3246.h"

inline int fAx3246(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            bmats.Ax3246.data[i][j] = -16*bmats.A_17_25.data[i][j] + bmats.A_17_26.data[i][j] - 16*bmats.A_18_25.data[i][j] + bmats.A_18_26.data[i][j] - 16*bmats.A_19_25.data[i][j] + bmats.A_19_26.data[i][j] - 16*bmats.A_20_25.data[i][j] + bmats.A_20_26.data[i][j] - 16*bmats.A_21_25.data[i][j] + bmats.A_21_26.data[i][j] - 16*bmats.A_22_25.data[i][j] + bmats.A_22_26.data[i][j] - 16*bmats.A_23_25.data[i][j] + bmats.A_23_26.data[i][j] - 16*bmats.A_24_25.data[i][j] + bmats.A_24_26.data[i][j] - 17*bmats.A_25_25.data[i][j] - 16*bmats.A_26_25.data[i][j] + bmats.A_26_26.data[i][j] - 16*bmats.A_27_25.data[i][j] + bmats.A_27_26.data[i][j] - 16*bmats.A_30_25.data[i][j] + bmats.A_30_26.data[i][j] - 16*bmats.A_31_25.data[i][j] + bmats.A_31_26.data[i][j] - 16*bmats.A_32_25.data[i][j] + bmats.A_32_26.data[i][j] + bmats.Ax1494.data[i][j] + bmats.Ax211.data[i][j] + bmats.Ax236.data[i][j] + bmats.Ax239.data[i][j] + bmats.Ax242.data[i][j] + bmats.Ax245.data[i][j] + bmats.Ax248.data[i][j] + bmats.Ax251.data[i][j] + bmats.Ax254.data[i][j] + bmats.Ax257.data[i][j] + bmats.Ax2948.data[i][j] + bmats.Ax2952.data[i][j] + bmats.Ax58.data[i][j];
        }
    }
    return 0;
}