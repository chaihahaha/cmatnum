#include "fBx13209.h"

inline int fBx13209(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            bmats.Bx13209.data[i][j] = bmats.B_17_29.data[i][j] + bmats.B_18_29.data[i][j] + bmats.B_19_29.data[i][j] + bmats.B_20_29.data[i][j] + bmats.B_21_29.data[i][j] + bmats.B_22_29.data[i][j] + bmats.B_23_29.data[i][j] + bmats.B_24_29.data[i][j] + bmats.B_25_29.data[i][j] + bmats.B_26_29.data[i][j] + bmats.B_27_29.data[i][j] + bmats.B_28_29.data[i][j] + bmats.B_29_29.data[i][j] + bmats.B_30_29.data[i][j] + bmats.B_31_29.data[i][j] + bmats.B_32_29.data[i][j] - bmats.Bx2488.data[i][j];
        }
    }
    return 0;
}
