#include "fAx4351.h"

inline int fAx4351(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            bmats.Ax4351.data[i][j] = bmats.A_18_17.data[i][j] + bmats.A_18_18.data[i][j] + bmats.A_18_21.data[i][j] + bmats.A_18_22.data[i][j] + bmats.A_18_23.data[i][j] + bmats.A_18_24.data[i][j] + bmats.A_18_25.data[i][j] + bmats.A_18_26.data[i][j] + bmats.A_18_27.data[i][j] + bmats.A_18_28.data[i][j] + bmats.A_18_29.data[i][j] + bmats.A_18_30.data[i][j] + bmats.A_18_31.data[i][j] + bmats.A_18_32.data[i][j];
        }
    }
    return 0;
}
