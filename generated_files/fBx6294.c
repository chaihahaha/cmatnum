#include "fBx6294.h"

inline int fBx6294(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            bmats.Bx6294.data[i][j] = bmats.B_28_1.data[i][j] + bmats.B_28_10.data[i][j] + bmats.B_28_11.data[i][j] + bmats.B_28_2.data[i][j] + bmats.B_28_3.data[i][j] + bmats.B_28_4.data[i][j] + bmats.B_28_5.data[i][j] + bmats.B_28_6.data[i][j] + bmats.B_28_7.data[i][j] + bmats.B_28_8.data[i][j] + bmats.B_28_9.data[i][j];
        }
    }
    return 0;
}
