#include "fAx2297.h"

inline int fAx2297(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            bmats.Ax2297.data[i][j] = bmats.A_5_17.data[i][j] + bmats.A_5_18.data[i][j] + bmats.A_5_19.data[i][j] + bmats.A_5_20.data[i][j] + bmats.A_5_21.data[i][j] + bmats.A_5_22.data[i][j] + bmats.A_5_23.data[i][j] + bmats.A_5_24.data[i][j] + bmats.A_5_25.data[i][j] + bmats.A_5_26.data[i][j] + bmats.A_5_29.data[i][j] + bmats.A_5_30.data[i][j] + bmats.A_5_31.data[i][j] + bmats.A_5_32.data[i][j];
        }
    }
    return 0;
}
