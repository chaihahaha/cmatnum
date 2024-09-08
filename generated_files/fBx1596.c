#include "fBx1596.h"

inline int fBx1596(pack_mats_22x22 bmats) {
    int BL = bmats.A_1_1.shape[0];
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            bmats.Bx1596.data[i][j] = bmats.B_17_1.data[i][j] + bmats.B_17_10.data[i][j] + bmats.B_17_11.data[i][j] + bmats.B_17_2.data[i][j] + bmats.B_17_3.data[i][j] + bmats.B_17_4.data[i][j] + bmats.B_17_5.data[i][j] + bmats.B_17_6.data[i][j] + bmats.B_17_7.data[i][j] + bmats.B_17_8.data[i][j] + bmats.B_17_9.data[i][j];
        }
    }
    return 0;
}
