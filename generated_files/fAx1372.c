#include "fAx1372.h"

inline int fAx1372(pack_mats_22x22 bmats) {
    int BL = bmats.A_1_1.shape[0];
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            bmats.Ax1372.data[i][j] = bmats.A_1_12.data[i][j] + bmats.A_1_15.data[i][j] + bmats.A_1_16.data[i][j] + bmats.A_1_17.data[i][j] + bmats.A_1_18.data[i][j] + bmats.A_1_19.data[i][j] + bmats.A_1_20.data[i][j] + bmats.A_1_21.data[i][j] + bmats.A_1_22.data[i][j];
        }
    }
    return 0;
}
