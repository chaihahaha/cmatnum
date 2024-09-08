#include "fBx12865.h"

inline int fBx12865(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            bmats.Bx12865.data[i][j] = bmats.B_19_1.data[i][j] + bmats.B_20_1.data[i][j] + bmats.B_21_1.data[i][j] + bmats.B_22_1.data[i][j] + bmats.B_23_1.data[i][j] + bmats.B_24_1.data[i][j] + bmats.B_25_1.data[i][j] + bmats.B_26_1.data[i][j] + bmats.B_27_1.data[i][j] + bmats.B_28_1.data[i][j] + bmats.B_29_1.data[i][j] + bmats.B_30_1.data[i][j] + bmats.B_31_1.data[i][j];
        }
    }
    return 0;
}
