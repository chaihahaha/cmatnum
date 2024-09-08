#include "fBx5970.h"

inline int fBx5970(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            bmats.Bx5970.data[i][j] = bmats.B_17_11.data[i][j] + bmats.B_18_11.data[i][j] + bmats.B_19_11.data[i][j] + bmats.B_20_11.data[i][j] + bmats.B_21_11.data[i][j] + bmats.B_22_11.data[i][j] + bmats.B_23_11.data[i][j] + bmats.B_24_11.data[i][j] + bmats.B_25_11.data[i][j] + bmats.B_26_11.data[i][j] + bmats.B_27_11.data[i][j] + bmats.B_28_11.data[i][j] + bmats.B_29_11.data[i][j] + bmats.B_30_11.data[i][j] + bmats.B_31_11.data[i][j] + bmats.B_32_11.data[i][j];
        }
    }
    return 0;
}
