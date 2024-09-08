#include "fBx7427.h"

inline int fBx7427(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            bmats.Bx7427.data[i][j] = bmats.B_27_1.data[i][j] + bmats.B_27_2.data[i][j] + bmats.B_27_3.data[i][j] + bmats.B_27_4.data[i][j] + bmats.B_27_5.data[i][j] + bmats.B_27_6.data[i][j] + bmats.B_27_7.data[i][j] + bmats.B_27_8.data[i][j] + bmats.B_27_9.data[i][j];
        }
    }
    return 0;
}
