#include "fBx13245.h"

inline int fBx13245(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            bmats.Bx13245.data[i][j] = -bmats.B_16_17.data[i][j] + bmats.B_17_17.data[i][j] + bmats.B_18_17.data[i][j] + bmats.B_19_17.data[i][j] - bmats.B_1_17.data[i][j] + bmats.B_20_17.data[i][j] + bmats.B_21_17.data[i][j] + bmats.B_22_17.data[i][j] + bmats.B_23_17.data[i][j] + bmats.B_24_17.data[i][j] + bmats.B_25_17.data[i][j] + bmats.B_26_17.data[i][j] + bmats.B_27_17.data[i][j] + bmats.B_28_17.data[i][j] + bmats.B_29_17.data[i][j] - bmats.B_2_17.data[i][j] + bmats.B_30_17.data[i][j] + bmats.B_31_17.data[i][j] + bmats.B_32_17.data[i][j] - bmats.Bx12860.data[i][j];
        }
    }
    return 0;
}
