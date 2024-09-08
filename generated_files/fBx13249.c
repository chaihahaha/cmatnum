#include "fBx13249.h"

inline int fBx13249(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            bmats.Bx13249.data[i][j] = -bmats.B_16_18.data[i][j] + bmats.B_17_18.data[i][j] + bmats.B_18_18.data[i][j] + bmats.B_19_18.data[i][j] - bmats.B_1_18.data[i][j] + bmats.B_20_18.data[i][j] + bmats.B_21_18.data[i][j] + bmats.B_22_18.data[i][j] + bmats.B_23_18.data[i][j] + bmats.B_24_18.data[i][j] + bmats.B_25_18.data[i][j] + bmats.B_26_18.data[i][j] + bmats.B_27_18.data[i][j] + bmats.B_28_18.data[i][j] + bmats.B_29_18.data[i][j] - bmats.B_2_18.data[i][j] + bmats.B_30_18.data[i][j] + bmats.B_31_18.data[i][j] + bmats.B_32_18.data[i][j] - bmats.Bx12672.data[i][j];
        }
    }
    return 0;
}
