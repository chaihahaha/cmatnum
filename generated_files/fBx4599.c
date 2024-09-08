#include "fBx4599.h"

inline int fBx4599(pack_mats_22x22 bmats) {
    int BL = bmats.A_1_1.shape[0];
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            bmats.Bx4599.data[i][j] = bmats.B_11_8.data[i][j] + bmats.B_1_8.data[i][j] + bmats.B_2_8.data[i][j] + bmats.B_3_8.data[i][j] + bmats.B_4_8.data[i][j] + bmats.B_7_8.data[i][j] + bmats.B_8_8.data[i][j] + bmats.B_9_8.data[i][j];
        }
    }
    return 0;
}
