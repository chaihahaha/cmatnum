#include "fBx4269.h"

inline int fBx4269(pack_mats_22x22 bmats) {
    int BL = bmats.A_1_1.shape[0];
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            bmats.Bx4269.data[i][j] = bmats.B_10_8.data[i][j] + bmats.B_11_8.data[i][j] + bmats.B_1_8.data[i][j] + bmats.B_2_8.data[i][j] + bmats.B_3_8.data[i][j] + bmats.B_6_8.data[i][j] + bmats.B_8_8.data[i][j];
        }
    }
    return 0;
}
