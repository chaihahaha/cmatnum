#include "fBx13253.h"

inline int fBx13253(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            bmats.Bx13253.data[i][j] = -bmats.B_16_19.data[i][j] + bmats.B_17_19.data[i][j] + bmats.B_18_19.data[i][j] + bmats.B_19_19.data[i][j] - bmats.B_1_19.data[i][j] + bmats.B_20_19.data[i][j] + bmats.B_21_19.data[i][j] + bmats.B_22_19.data[i][j] + bmats.B_23_19.data[i][j] + bmats.B_24_19.data[i][j] + bmats.B_25_19.data[i][j] + bmats.B_26_19.data[i][j] + bmats.B_27_19.data[i][j] + bmats.B_28_19.data[i][j] + bmats.B_29_19.data[i][j] - bmats.B_2_19.data[i][j] + bmats.B_30_19.data[i][j] + bmats.B_31_19.data[i][j] + bmats.B_32_19.data[i][j] - bmats.B_3_19.data[i][j] - bmats.Bx12271.data[i][j];
        }
    }
    return 0;
}
