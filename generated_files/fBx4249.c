#include "fBx4249.h"

inline int fBx4249(pack_mats_22x22 bmats) {
    int BL = bmats.A_1_1.shape[0];
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            bmats.Bx4249.data[i][j] = bmats.B_10_7.data[i][j] + bmats.B_11_7.data[i][j] + bmats.B_1_7.data[i][j] + bmats.B_2_7.data[i][j] + bmats.B_3_7.data[i][j] + bmats.B_4_7.data[i][j] + bmats.B_8_7.data[i][j];
        }
    }
    return 0;
}
