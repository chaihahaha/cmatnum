#include "fAx2375.h"

inline int fAx2375(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            bmats.Ax2375.data[i][j] = bmats.A_17_27.data[i][j] - 16*bmats.A_17_28.data[i][j] + bmats.A_18_27.data[i][j] - 16*bmats.A_18_28.data[i][j] + bmats.A_19_27.data[i][j] - 16*bmats.A_19_28.data[i][j] + bmats.A_20_27.data[i][j] - 16*bmats.A_20_28.data[i][j] + bmats.A_21_27.data[i][j] - 16*bmats.A_21_28.data[i][j] + bmats.A_22_27.data[i][j] - 16*bmats.A_22_28.data[i][j] + bmats.A_23_27.data[i][j] - 16*bmats.A_23_28.data[i][j] + bmats.A_24_27.data[i][j] - 16*bmats.A_24_28.data[i][j] + bmats.A_25_27.data[i][j] - 16*bmats.A_25_28.data[i][j] + bmats.A_26_27.data[i][j] - 16*bmats.A_26_28.data[i][j] + bmats.A_27_27.data[i][j] - 16*bmats.A_27_28.data[i][j] - 17*bmats.A_28_28.data[i][j] + bmats.A_29_27.data[i][j] - 16*bmats.A_29_28.data[i][j] + bmats.A_32_27.data[i][j] - 16*bmats.A_32_28.data[i][j] + bmats.Ax1.data[i][j] + bmats.Ax10.data[i][j] + bmats.Ax15.data[i][j] + bmats.Ax152.data[i][j] + bmats.Ax1966.data[i][j] + bmats.Ax2225.data[i][j] + bmats.Ax2230.data[i][j] + bmats.Ax23.data[i][j] + bmats.Ax28.data[i][j] + bmats.Ax34.data[i][j] + bmats.Ax39.data[i][j] + bmats.Ax45.data[i][j] + bmats.Ax55.data[i][j];
        }
    }
    return 0;
}
