#include "fBx9525.h"

inline int fBx9525(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            bmats.Bx9525.data[i][j] = bmats.B_25_1.data[i][j] + bmats.B_25_2.data[i][j] + bmats.B_25_3.data[i][j] + bmats.B_25_4.data[i][j] + bmats.B_25_5.data[i][j] + bmats.B_25_6.data[i][j] + bmats.B_25_7.data[i][j] + bmats.B_25_8.data[i][j];
        }
    }
    return 0;
}
