#include "fAx1487.h"

inline int fAx1487(pack_mats_22x22 bmats) {
    int BL = bmats.A_1_1.shape[0];
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            bmats.Ax1487.data[i][j] = bmats.A_14_12.data[i][j] + bmats.A_14_13.data[i][j] + bmats.A_14_14.data[i][j] + bmats.A_14_15.data[i][j] + bmats.A_14_16.data[i][j] + bmats.A_14_17.data[i][j] + bmats.A_14_18.data[i][j] + bmats.A_14_21.data[i][j] + bmats.A_14_22.data[i][j];
        }
    }
    return 0;
}
