#include "fBx13385.h"

inline int fBx13385(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            bmats.Bx13385.data[i][j] = bmats.B_17_15.data[i][j] + bmats.B_18_15.data[i][j] + bmats.B_19_15.data[i][j] + bmats.B_20_15.data[i][j] + bmats.B_21_15.data[i][j] + bmats.B_22_15.data[i][j] + bmats.B_23_15.data[i][j] + bmats.B_24_15.data[i][j] + bmats.B_25_15.data[i][j] + bmats.B_26_15.data[i][j] + bmats.B_27_15.data[i][j] + bmats.B_28_15.data[i][j] + bmats.B_29_15.data[i][j] + bmats.B_30_15.data[i][j] + bmats.B_31_15.data[i][j] + bmats.B_32_15.data[i][j];
        }
    }
    return 0;
}
