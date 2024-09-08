#include "fBx4645.h"

inline int fBx4645(pack_mats_22x22 bmats) {
    int BL = bmats.A_1_1.shape[0];
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            bmats.Bx4645.data[i][j] = bmats.B_10_7.data[i][j] + bmats.B_1_7.data[i][j] + bmats.B_2_7.data[i][j] + bmats.B_3_7.data[i][j] + bmats.B_4_7.data[i][j] + bmats.B_5_7.data[i][j] + bmats.B_6_7.data[i][j] + bmats.B_7_7.data[i][j] + bmats.B_9_7.data[i][j];
        }
    }
    return 0;
}
