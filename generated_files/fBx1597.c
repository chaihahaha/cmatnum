#include "fBx1597.h"

inline int fBx1597(pack_mats_22x22 bmats) {
    int BL = bmats.A_1_1.shape[0];
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            bmats.Bx1597.data[i][j] = bmats.B_6_12.data[i][j] + bmats.B_6_13.data[i][j] + bmats.B_6_14.data[i][j] + bmats.B_6_15.data[i][j] + bmats.B_6_16.data[i][j] + bmats.B_6_17.data[i][j] + bmats.B_6_18.data[i][j] + bmats.B_6_19.data[i][j] + bmats.B_6_20.data[i][j] + bmats.B_6_21.data[i][j] + bmats.B_6_22.data[i][j];
        }
    }
    return 0;
}
