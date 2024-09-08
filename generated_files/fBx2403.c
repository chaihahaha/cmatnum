#include "fBx2403.h"

inline int fBx2403(pack_mats_22x22 bmats) {
    int BL = bmats.A_1_1.shape[0];
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            bmats.Bx2403.data[i][j] = bmats.B_5_12.data[i][j] + bmats.B_5_13.data[i][j] + bmats.B_5_14.data[i][j] + bmats.B_5_15.data[i][j] + bmats.B_5_16.data[i][j] + bmats.B_5_17.data[i][j] + bmats.B_5_18.data[i][j] + bmats.B_5_19.data[i][j] + bmats.B_5_20.data[i][j] + bmats.B_5_21.data[i][j] + bmats.B_5_22.data[i][j];
        }
    }
    return 0;
}
