#include "fBx11066.h"

inline int fBx11066(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            bmats.Bx11066.data[i][j] = bmats.B_23_1.data[i][j] + bmats.B_23_2.data[i][j] + bmats.B_23_3.data[i][j] + bmats.B_23_4.data[i][j] + bmats.B_23_5.data[i][j] + bmats.B_23_6.data[i][j];
        }
    }
    return 0;
}
