#include "fBx7193.h"

inline int fBx7193(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            bmats.Bx7193.data[i][j] = bmats.B_17_10.data[i][j] + bmats.B_18_10.data[i][j] + bmats.B_19_10.data[i][j] + bmats.B_20_10.data[i][j] + bmats.B_21_10.data[i][j] + bmats.B_22_10.data[i][j] + bmats.B_23_10.data[i][j] + bmats.B_24_10.data[i][j] + bmats.B_25_10.data[i][j] + bmats.B_26_10.data[i][j] + bmats.B_27_10.data[i][j] + bmats.B_28_10.data[i][j] + bmats.B_29_10.data[i][j] + bmats.B_30_10.data[i][j] + bmats.B_31_10.data[i][j] + bmats.B_32_10.data[i][j];
        }
    }
    return 0;
}
