#include "fBx4633.h"

inline int fBx4633(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            bmats.Bx4633.data[i][j] = bmats.B_17_12.data[i][j] + bmats.B_18_12.data[i][j] + bmats.B_19_12.data[i][j] + bmats.B_20_12.data[i][j] + bmats.B_21_12.data[i][j] + bmats.B_22_12.data[i][j] + bmats.B_23_12.data[i][j] + bmats.B_24_12.data[i][j] + bmats.B_25_12.data[i][j] + bmats.B_26_12.data[i][j] + bmats.B_27_12.data[i][j] + bmats.B_28_12.data[i][j] + bmats.B_29_12.data[i][j] + bmats.B_30_12.data[i][j] + bmats.B_31_12.data[i][j] + bmats.B_32_12.data[i][j];
        }
    }
    return 0;
}
