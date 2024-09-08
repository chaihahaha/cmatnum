#include "fBx12667.h"

inline int fBx12667(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            bmats.Bx12667.data[i][j] = bmats.B_19_2.data[i][j] + bmats.B_20_2.data[i][j] + bmats.B_21_2.data[i][j] + bmats.B_22_2.data[i][j] + bmats.B_23_2.data[i][j] + bmats.B_24_2.data[i][j] + bmats.B_25_2.data[i][j] + bmats.B_26_2.data[i][j] + bmats.B_27_2.data[i][j] + bmats.B_28_2.data[i][j] + bmats.B_29_2.data[i][j] + bmats.B_30_2.data[i][j] + bmats.B_31_2.data[i][j];
        }
    }
    return 0;
}
