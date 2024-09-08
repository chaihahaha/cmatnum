#include "fBx13243.h"

inline int fBx13243(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            bmats.Bx13243.data[i][j] = bmats.B_14_1.data[i][j] + bmats.B_15_1.data[i][j] + bmats.B_16_1.data[i][j] - bmats.B_17_1.data[i][j] - bmats.B_18_1.data[i][j] - bmats.B_19_1.data[i][j] - bmats.B_20_1.data[i][j] - bmats.B_21_1.data[i][j] - bmats.B_22_1.data[i][j] - bmats.B_23_1.data[i][j] - bmats.B_24_1.data[i][j] - bmats.B_25_1.data[i][j] - bmats.B_26_1.data[i][j] - bmats.B_27_1.data[i][j] - bmats.B_28_1.data[i][j] - bmats.B_29_1.data[i][j] - bmats.B_30_1.data[i][j] - bmats.B_31_1.data[i][j] - bmats.B_32_1.data[i][j] + bmats.B_4_1.data[i][j] + bmats.B_5_1.data[i][j] + bmats.B_6_1.data[i][j] + bmats.B_7_1.data[i][j] + bmats.Bx12870.data[i][j];
        }
    }
    return 0;
}
