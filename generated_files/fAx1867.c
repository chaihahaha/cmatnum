#include "fAx1867.h"

inline int fAx1867(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            bmats.Ax1867.data[i][j] = -16*bmats.A_17_13.data[i][j] + bmats.A_17_14.data[i][j] - 16*bmats.A_18_13.data[i][j] + bmats.A_18_14.data[i][j] - 16*bmats.A_19_13.data[i][j] + bmats.A_19_14.data[i][j] - 16*bmats.A_20_13.data[i][j] + bmats.A_20_14.data[i][j] - 16*bmats.A_21_13.data[i][j] + bmats.A_21_14.data[i][j] - 16*bmats.A_22_13.data[i][j] + bmats.A_22_14.data[i][j] - 16*bmats.A_23_13.data[i][j] + bmats.A_23_14.data[i][j] - 16*bmats.A_24_13.data[i][j] + bmats.A_24_14.data[i][j] - 16*bmats.A_25_13.data[i][j] + bmats.A_25_14.data[i][j] - 16*bmats.A_26_13.data[i][j] + bmats.A_26_14.data[i][j] - 16*bmats.A_27_13.data[i][j] + bmats.A_27_14.data[i][j] - 16*bmats.A_28_13.data[i][j] + bmats.A_28_14.data[i][j] - 16*bmats.A_29_13.data[i][j] + bmats.A_29_14.data[i][j] - 16*bmats.A_30_13.data[i][j] + bmats.A_30_14.data[i][j] - 16*bmats.A_31_13.data[i][j] + bmats.A_31_14.data[i][j] - 16*bmats.A_32_13.data[i][j] + bmats.A_32_14.data[i][j] + bmats.Ax482.data[i][j] + bmats.Ax485.data[i][j] + bmats.Ax488.data[i][j] + bmats.Ax491.data[i][j] + bmats.Ax494.data[i][j] + bmats.Ax497.data[i][j] + bmats.Ax500.data[i][j] + bmats.Ax503.data[i][j] + bmats.Ax506.data[i][j] + bmats.Ax509.data[i][j] + bmats.Ax512.data[i][j] + bmats.Ax515.data[i][j] + bmats.Ax518.data[i][j] + bmats.Ax521.data[i][j] + bmats.Ax524.data[i][j] + bmats.Ax527.data[i][j];
        }
    }
    return 0;
}
