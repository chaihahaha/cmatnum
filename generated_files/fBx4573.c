#include "fBx4573.h"

inline int fBx4573(pack_mats_22x22 bmats) {
    int BL = bmats.A_1_1.shape[0];
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            bmats.Bx4573.data[i][j] = bmats.B_12_19.data[i][j] + bmats.B_13_19.data[i][j] + bmats.B_15_19.data[i][j] + bmats.B_17_19.data[i][j] + bmats.B_19_19.data[i][j] + bmats.B_21_19.data[i][j];
        }
    }
    return 0;
}
