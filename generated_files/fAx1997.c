#include "fAx1997.h"

inline int fAx1997(pack_mats_22x22 bmats) {
    int BL = bmats.A_1_1.shape[0];
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            bmats.Ax1997.data[i][j] = bmats.A_11_12.data[i][j] + bmats.A_11_13.data[i][j] + bmats.A_11_14.data[i][j] + bmats.A_11_15.data[i][j] + bmats.A_11_16.data[i][j] + bmats.A_11_17.data[i][j] + bmats.A_11_18.data[i][j] + bmats.A_11_21.data[i][j] + bmats.A_11_22.data[i][j];
        }
    }
    return 0;
}
