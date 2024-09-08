#include "fBx4092.h"

inline int fBx4092(pack_mats_22x22 bmats) {
    int BL = bmats.A_1_1.shape[0];
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            bmats.Bx4092.data[i][j] = bmats.B_11_21.data[i][j] + bmats.B_1_21.data[i][j] + bmats.B_2_21.data[i][j] + bmats.B_3_21.data[i][j] + bmats.B_4_21.data[i][j] + bmats.B_5_21.data[i][j] + bmats.B_6_21.data[i][j];
        }
    }
    return 0;
}
