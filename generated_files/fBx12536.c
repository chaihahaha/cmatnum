#include "fBx12536.h"

inline int fBx12536(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            bmats.Bx12536.data[i][j] = bmats.B_20_1.data[i][j] + bmats.B_20_15.data[i][j] + bmats.B_20_16.data[i][j] + bmats.B_20_2.data[i][j] + bmats.B_20_3.data[i][j] + bmats.B_20_4.data[i][j] + bmats.B_20_5.data[i][j];
        }
    }
    return 0;
}
