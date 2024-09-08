#include "fBx3798.h"

inline int fBx3798(pack_mats_22x22 bmats) {
    int BL = bmats.A_1_1.shape[0];
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            bmats.Bx3798.data[i][j] = bmats.B_12_1.data[i][j] + bmats.B_12_10.data[i][j] + bmats.B_12_11.data[i][j] + bmats.B_12_2.data[i][j] + bmats.B_12_3.data[i][j] + bmats.B_12_4.data[i][j] + bmats.B_12_5.data[i][j] + bmats.B_12_6.data[i][j] + bmats.B_12_7.data[i][j] + bmats.B_12_8.data[i][j] + bmats.B_12_9.data[i][j];
        }
    }
    return 0;
}
