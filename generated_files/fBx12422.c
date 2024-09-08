#include "fBx12422.h"

inline int fBx12422(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            bmats.Bx12422.data[i][j] = bmats.B_12_19.data[i][j] + bmats.B_13_19.data[i][j] + bmats.B_15_19.data[i][j] + bmats.B_16_19.data[i][j] + bmats.B_1_19.data[i][j] + bmats.B_2_19.data[i][j] + bmats.B_3_19.data[i][j] + bmats.B_4_19.data[i][j] + bmats.B_5_19.data[i][j] + bmats.B_6_19.data[i][j] + bmats.B_7_19.data[i][j] + bmats.B_8_19.data[i][j] + bmats.B_9_19.data[i][j];
        }
    }
    return 0;
}
