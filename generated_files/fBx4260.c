#include "fBx4260.h"

inline int fBx4260(pack_mats_22x22 bmats) {
    int BL = bmats.A_1_1.shape[0];
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            bmats.Bx4260.data[i][j] = bmats.B_10_18.data[i][j] + bmats.B_11_18.data[i][j] + bmats.B_1_18.data[i][j] + bmats.B_2_18.data[i][j] + bmats.B_3_18.data[i][j] + bmats.B_4_18.data[i][j] + bmats.B_5_18.data[i][j] + bmats.B_7_18.data[i][j] + bmats.B_8_18.data[i][j] + bmats.B_9_18.data[i][j];
        }
    }
    return 0;
}
