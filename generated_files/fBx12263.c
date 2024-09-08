#include "fBx12263.h"

inline int fBx12263(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            bmats.Bx12263.data[i][j] = bmats.B_20_3.data[i][j] + bmats.B_21_3.data[i][j] + bmats.B_22_3.data[i][j] + bmats.B_23_3.data[i][j] + bmats.B_24_3.data[i][j] + bmats.B_25_3.data[i][j] + bmats.B_26_3.data[i][j] + bmats.B_27_3.data[i][j] + bmats.B_28_3.data[i][j] + bmats.B_29_3.data[i][j] + bmats.B_30_3.data[i][j] + bmats.B_31_3.data[i][j];
        }
    }
    return 0;
}
