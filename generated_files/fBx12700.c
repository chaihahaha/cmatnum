#include "fBx12700.h"

inline int fBx12700(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            bmats.Bx12700.data[i][j] = bmats.B_11_2.data[i][j] + bmats.B_12_2.data[i][j] + bmats.B_13_2.data[i][j] + bmats.B_14_2.data[i][j] + bmats.B_2_2.data[i][j] + bmats.B_5_2.data[i][j] + bmats.B_8_2.data[i][j] + bmats.B_9_2.data[i][j];
        }
    }
    return 0;
}
