#include "fBx11433.h"

inline int fBx11433(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            bmats.Bx11433.data[i][j] = bmats.B_10_5.data[i][j] + bmats.B_11_5.data[i][j] + bmats.B_13_5.data[i][j] + bmats.B_16_5.data[i][j] + bmats.B_1_5.data[i][j] + bmats.B_2_5.data[i][j] + bmats.B_3_5.data[i][j] + bmats.B_5_5.data[i][j] + bmats.B_6_5.data[i][j] + bmats.B_8_5.data[i][j];
        }
    }
    return 0;
}
