#include "fBx12969.h"

inline int fBx12969(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            bmats.Bx12969.data[i][j] = bmats.B_12_17.data[i][j] + bmats.B_13_17.data[i][j] + bmats.B_14_17.data[i][j] + bmats.B_15_17.data[i][j] + bmats.B_16_17.data[i][j] + bmats.B_1_17.data[i][j] + bmats.B_2_17.data[i][j] + bmats.B_3_17.data[i][j] + bmats.B_4_17.data[i][j] + bmats.B_5_17.data[i][j] + bmats.B_6_17.data[i][j] + bmats.B_7_17.data[i][j] + bmats.B_8_17.data[i][j];
        }
    }
    return 0;
}
