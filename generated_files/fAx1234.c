#include "fAx1234.h"

inline int fAx1234(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            bmats.Ax1234.data[i][j] = bmats.A_30_17.data[i][j] + bmats.A_30_18.data[i][j] + bmats.A_30_19.data[i][j] + bmats.A_30_20.data[i][j] + bmats.A_30_21.data[i][j] + bmats.A_30_22.data[i][j] + bmats.A_30_23.data[i][j] + bmats.A_30_24.data[i][j] + bmats.A_30_25.data[i][j] + bmats.A_30_26.data[i][j] + bmats.A_30_29.data[i][j] + bmats.A_30_30.data[i][j] + bmats.A_30_31.data[i][j] + bmats.A_30_32.data[i][j];
        }
    }
    return 0;
}
