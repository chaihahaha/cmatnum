#include "fAx1378.h"

inline int fAx1378(pack_mats_22x22 bmats) {
    int BL = bmats.A_1_1.shape[0];
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            bmats.Ax1378.data[i][j] = bmats.A_3_12.data[i][j] + bmats.A_3_15.data[i][j] + bmats.A_3_16.data[i][j] + bmats.A_3_17.data[i][j] + bmats.A_3_18.data[i][j] + bmats.A_3_19.data[i][j] + bmats.A_3_20.data[i][j] + bmats.A_3_21.data[i][j] + bmats.A_3_22.data[i][j];
        }
    }
    return 0;
}
