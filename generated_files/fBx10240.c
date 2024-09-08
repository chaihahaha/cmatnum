#include "fBx10240.h"

inline int fBx10240(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            bmats.Bx10240.data[i][j] = bmats.B_17_7.data[i][j] + bmats.B_18_7.data[i][j] + bmats.B_19_7.data[i][j] + bmats.B_20_7.data[i][j] + bmats.B_21_7.data[i][j] + bmats.B_22_7.data[i][j] + bmats.B_23_7.data[i][j] + bmats.B_31_7.data[i][j] + bmats.B_32_7.data[i][j] + bmats.Bx10008.data[i][j];
        }
    }
    return 0;
}
