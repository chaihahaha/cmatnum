#include "fBx2515.h"

inline int fBx2515(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            bmats.Bx2515.data[i][j] = bmats.B_17_13.data[i][j] + bmats.B_18_13.data[i][j] + bmats.B_19_13.data[i][j] + bmats.B_20_13.data[i][j] + bmats.B_21_13.data[i][j] + bmats.B_22_13.data[i][j] + bmats.B_23_13.data[i][j] + bmats.B_24_13.data[i][j] + bmats.B_25_13.data[i][j] + bmats.B_26_13.data[i][j] + bmats.B_27_13.data[i][j] + bmats.B_28_13.data[i][j] + bmats.B_29_13.data[i][j] + bmats.B_30_13.data[i][j] + bmats.B_31_13.data[i][j] + bmats.B_32_13.data[i][j];
        }
    }
    return 0;
}
